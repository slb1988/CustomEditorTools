// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetActions/QuickAssetAction.h"
#include "DebugHeader.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"

void UQuickAssetAction::DuplicateAssets(int32 NumOfDuplicates)
{
    if (NumOfDuplicates <= 0)
    {
        ShowMsgDialog(EAppMsgType::Type::Ok, TEXT("Please enter a VALID number"));
        return;
    }

    TArray<FAssetData> SelectedAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
    uint32 Counter = 0;

    for (const FAssetData& SelectedAssetData : SelectedAssetsData)
    {
        const FString SourceAssetPath = SelectedAssetData.GetSoftObjectPath().ToString();
        const FString BaseDuplicatedAssetName = SelectedAssetData.AssetName.ToString();
        
        for (int32 i = 0; i < NumOfDuplicates; i++)
        {
            const FString NewDuplicatedAssetName = BaseDuplicatedAssetName + TEXT("_") + FString::FromInt(i + 1);
            const FString NewPathName = FPaths::Combine(SelectedAssetData.PackagePath.ToString(), NewDuplicatedAssetName);

            if (UEditorAssetLibrary::DuplicateAsset(SourceAssetPath, NewPathName))
            {
                UEditorAssetLibrary::SaveAsset(NewPathName, false);
                ++Counter;
            }
        }
    }

    if (Counter > 0)
    {
        ShowNotifyInfo(TEXT("Successfully duplicated ") + FString::FromInt(Counter) + TEXT(" files."));
    }
}

void UQuickAssetAction::AddPrefixes()
{
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter = 0;

	for (UObject* SelectedObject : SelectedObjects)
	{
		if (!SelectedObject) continue;

		FString* PrefixFound = PrefixMap.Find(SelectedObject->GetClass());
		if (!PrefixFound || PrefixFound->IsEmpty())
		{
			Print(TEXT("Failed to find prefix for class ") + SelectedObject->GetClass()->GetName(), FColor::Red);
			continue;
		}
		
		// Get the full path of the asset
		FString OldPathName = SelectedObject->GetPathName();
		UE_LOG(LogTemp, Log, TEXT("Asset path: %s"), *OldPathName);

		// Get the directory path and old asset name
		FString DirectoryPath;
		FString OldAssetName;
        OldPathName.Split(TEXT("/"), &DirectoryPath, &OldAssetName, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

		// Extract the base name and extension of the old asset
		FString OldBaseName;
		FString Extension;
		OldAssetName.Split(TEXT("."), &OldBaseName, &Extension, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		
		if (OldAssetName.StartsWith(*PrefixFound))
		{
			Print(OldPathName + TEXT(" already has prefix added"), FColor::Red);
			continue;
		}

        const FString OldPackagePath = DirectoryPath + "/" + OldBaseName;
		if (SelectedObject->IsA<UMaterialInstanceConstant>())
		{
			OldBaseName.RemoveFromStart("M_");
			OldBaseName.RemoveFromEnd("_Inst");
		}

		const FString NewBaseName = *PrefixFound + OldBaseName;
		
//		const FString NewAssetName = NewBaseName + "." + NewBaseName;
		const FString NewPathNameWithPrefix = DirectoryPath + "/" + NewBaseName;
		UE_LOG(LogTemp, Log, TEXT("Change New asset path: %s"), *NewPathNameWithPrefix);

		UEditorAssetLibrary::RenameAsset(OldPackagePath, NewPathNameWithPrefix);

		++Counter;
	}

	if (Counter > 0)
	{
		ShowNotifyInfo(TEXT("Successfully renamed ") + FString::FromInt(Counter) + " assets");
	}
}













