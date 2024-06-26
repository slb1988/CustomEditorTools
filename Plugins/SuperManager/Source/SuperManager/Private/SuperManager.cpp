// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperManager.h"

#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "EditorAssetLibrary.h"
#include "DebugHeader.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"

#define LOCTEXT_NAMESPACE "FSuperManagerModule"

void FSuperManagerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	InitCBMenuExtention();
}

void FSuperManagerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#pragma region ContentBrowserMenuExtension

void FSuperManagerModule::InitCBMenuExtention()
{
	FContentBrowserModule& ContentBrowserModule =
		FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	TArray<FContentBrowserMenuExtender_SelectedPaths>& ContextMenuExtenders = ContentBrowserModule.GetAllPathViewContextMenuExtenders();

	FContentBrowserMenuExtender_SelectedPaths CustomCBMenuDelegate;
	// Define the position for inserting menu entry
	CustomCBMenuDelegate.BindRaw(this, &FSuperManagerModule::CustomCBMenuExtender);
	ContextMenuExtenders.Add(CustomCBMenuDelegate);
}

TSharedRef<FExtender> FSuperManagerModule::CustomCBMenuExtender(const TArray<FString>& SelectedPaths)
{
	TSharedRef<FExtender> MenuExtender ((new FExtender()));

	if (SelectedPaths.Num() > 0)
	{
		FolderPathsSelected = SelectedPaths;
		// Define the details for the menu entry eg. Title,Tooltip,Function
		MenuExtender->AddMenuExtension(FName(TEXT("Delete")), EExtensionHook::After,
			TSharedPtr<FUICommandList>(),
			FMenuExtensionDelegate::CreateRaw(this, &FSuperManagerModule::AddCBMenuEntry));
	}

	return MenuExtender;
}

void FSuperManagerModule::AddCBMenuEntry(FMenuBuilder& MenuBuilder)
{
	// The actual function to execute.
	MenuBuilder.AddMenuEntry(
		FText::FromString(TEXT("Delete Unused Assets")),
		FText::FromString(TEXT("Safely delete all Unused Assets under folder")),
		FSlateIcon(),
		FExecuteAction::CreateRaw(this,
			&FSuperManagerModule::OnDeleteUnusedAssetButtonClicked)
		);
}

void FSuperManagerModule::OnDeleteUnusedAssetButtonClicked()
{
	FixUpRedirectors();
	
	if (FolderPathsSelected.Num() > 1)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("You only do this to one folder"));
		return;	
	}
	
	TArray<FString> AssetsPathNames = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0]);
	if (AssetsPathNames.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("No asset found under selected folder"));
		return;
	}

	TArray<FAssetData> UnusedAssetsDataArray;

	for (const FString& AssetPathName : AssetsPathNames)
	{
		// Don't touch root folder avoid crash，Developer, Collections
		if (AssetPathName.Contains("Developers")
			|| AssetPathName.Contains("Collections"))
		{
			continue;
		}
		if (!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;

		TArray<FString> AssetReferencers =
			UEditorAssetLibrary::FindPackageReferencersForAsset(AssetPathName);

		if (AssetReferencers.Num() == 0)
		{
			const FAssetData UnusedAssetData = UEditorAssetLibrary::FindAssetData(AssetPathName);
			UnusedAssetsDataArray.Add(UnusedAssetData);
		}
	}

	EAppReturnType::Type ConfirmResult =
		DebugHeader::ShowMsgDialog(EAppMsgType::YesNo, TEXT("A total of ") + FString::FromInt(UnusedAssetsDataArray.Num()) + TEXT(" found.\nWould you like to procceed?"));
	if (ConfirmResult == EAppReturnType::No) return;
	
	if (UnusedAssetsDataArray.Num() > 0)
	{
		ObjectTools::DeleteAssets(UnusedAssetsDataArray);
	}
	else
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("No unused asset found under selected folder"));
	}
	
}

void FSuperManagerModule::FixUpRedirectors()
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


#pragma endregion

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSuperManagerModule, SuperManager)
