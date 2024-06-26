// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSuperManagerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

#pragma region ContentBrowserMenuExtension

	void InitCBMenuExtention();

	TArray<FString> FolderPathsSelected;
	TSharedRef<FExtender> CustomCBMenuExtender(const TArray<FString>& SelectedPaths);
	void AddCBMenuEntry(class FMenuBuilder& MenuBuilder);
	void OnDeleteUnusedAssetButtonClicked();

	static void FixUpRedirectors();
#pragma endregion 
};
