
#include "Helpers/AssetMenuPathHalper.h"

#include "ContentBrowserModule.h"
#include "EasyMenuGlobal.h"
#include "Editor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Textures/SlateIcon.h"
#include "IContentBrowserSingleton.h"


void FAssetMenuPathHalper::RebuildNodes()
{
	Reset(false);
	for (auto& Info : FunctionInfos)
	{
		if (CurrentClass->IsChildOf(Info.Value.TargetClass))
		{
			AddMenu(Info.Value.Path, Info.Key, Info.Value.TargetClass, false);
		}
	}
}

void FAssetMenuPathHalper::OnBeginPopUp(FMenuBuilder& InBuilder)
{
	FEasyMenuGlobal::MenuState(true);
	OnEntryCallBegin();
}

void FAssetMenuPathHalper::OnEndPopUp(FMenuBuilder& InBuilder)
{
	OnEntryCallEnd();
	FEasyMenuGlobal::CleanState();
	FEasyMenuGlobal::ResolveAssetCommands(InBuilder);
	FEasyMenuGlobal::CleanCommands();
}

void FAssetMenuPathHalper::OnEntryCallBegin()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetData> SelectedAssets;
	ContentBrowserModule.Get().GetSelectedAssets(SelectedAssets);
	for (FAssetData& Asset : SelectedAssets)
	{
		FEasyMenuGlobal::SelectedAssets.Add(Asset.GetAsset());
	}
	FEasyMenuGlobal::AssetState(true);
}

void FAssetMenuPathHalper::OnEntryCallEnd()
{
	FEasyMenuGlobal::SelectedAssets.Reset();
	FEasyMenuGlobal::AssetState(false);
}

