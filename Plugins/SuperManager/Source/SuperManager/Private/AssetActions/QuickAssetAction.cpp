// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetActions/QuickAssetAction.h"

#include "AssetToolsModule.h"
#include "DebugHeader.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UQuickAssetAction::DuplicateAssets(int32 NumOfDuplicates)
{
    if (NumOfDuplicates <= 0)
    {
        DebugHeader::ShowMsgDialog(EAppMsgType::Type::Ok, TEXT("Please enter a VALID number"));
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
        DebugHeader::ShowNotifyInfo(TEXT("Successfully duplicated ") + FString::FromInt(Counter) + TEXT(" files."));
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
			DebugHeader::Print(TEXT("Failed to find prefix for class ") + SelectedObject->GetClass()->GetName(), FColor::Red);
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
			DebugHeader::Print(OldPathName + TEXT(" already has prefix added"), FColor::Red);
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
		DebugHeader::ShowNotifyInfo(TEXT("Successfully renamed ") + FString::FromInt(Counter) + " assets");
	}
}

void UQuickAssetAction::RemoveUnusedAssets()
{
	TArray<FAssetData> SelectedAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
	TArray<FAssetData> UnusedAssetsData;

	FixUpRedirectors();

	for (const FAssetData& SelectedAssetData : SelectedAssetsData)
	{
		const FString AssetPath = SelectedAssetData.GetSoftObjectPath().ToString();
		TArray<FString> AssetRefrencers = UEditorAssetLibrary::FindPackageReferencersForAsset(AssetPath);
		if (AssetRefrencers.Num() == 0)
		{
			UnusedAssetsData.Add(SelectedAssetData);
		}
	}
	if (UnusedAssetsData.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("No unused asset found among selected assets"), false);
		return;
	}

	int32 NumOfAssetsDeleted = ObjectTools::DeleteAssets(UnusedAssetsData, true);
	if (NumOfAssetsDeleted == 0) return;

	DebugHeader::ShowNotifyInfo(TEXT("Successfully deleted ") + FString::FromInt(NumOfAssetsDeleted) + TEXT(" unused assets."));
}

void UQuickAssetAction::FixUpRedirectors()
{
	TArray<UObjectRedirector*> RedirectorsToFixArray;

	const FAssetRegistryModule& AssetRegistryModule =
		FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

	FARFilter Filter;
	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Emplace("/Game");
	Filter.ClassPaths.Emplace("/Script/CoreUObject/ObjectRedirector");

	TArray<FAssetData> OutRedirectors;

	AssetRegistryModule.Get().GetAssets(Filter, OutRedirectors);

	for (const FAssetData& RedirectorData : OutRedirectors)
	{
		if (UObjectRedirector* RedirectorToFix = Cast<UObjectRedirector>(RedirectorData.GetAsset()))
		{
			RedirectorsToFixArray.Add(RedirectorToFix);
		}
	}

	FAssetToolsModule& AssetToolsModule
		= FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));

	AssetToolsModule.Get().FixupReferencers(RedirectorsToFixArray, true);
}













