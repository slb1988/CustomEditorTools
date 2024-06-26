#include "EasyMenuSubSystem.h"

#include "ContentBrowserModule.h"
#include "Factories.h"
#include "LevelEditor.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Subsystems/SubsystemCollection.h"
#include "EasyMenuGlobal.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "EasySystem"


UEasyMenuSubSystem::UEasyMenuSubSystem()
{
	
}


void UEasyMenuSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	StyleSet = MakeShareable(new FSlateStyleSet(FName(TEXT(TEXT_EM_STYLE))));
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);

	CollectIcons();
	CollectMenuPath();

	InitAssetEditMenu();
	InitActorEditMenu();
	InitToolBar();
}

void UEasyMenuSubSystem::Deinitialize()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet);
}

//收集所有类标记的icon
void UEasyMenuSubSystem::CollectIcons()
{
	for (TObjectIterator<UClass> ItClass; ItClass; ++ItClass)
	{
		for (TFieldIterator<UFunction> ItFunction(*ItClass); ItFunction; ++ItFunction)
		{
			if (ItFunction->HasMetaData(TEXT(TEXT_EM_ICON)))
			{
				FString IconPathStr = ItFunction->GetMetaData(TEXT(TEXT_EM_ICON));
				FString IconSizeStr = ItFunction->GetMetaData(TEXT(TEXT_EM_ICON_SIZE));
				
				IconPathStr = FEasyMenuGlobal::GetIconRealPath(IconPathStr);
				
				FVector2D IconSize(32, 32);
				if (!IconSizeStr.IsEmpty())
				{
					FString XSize, YSize;
					IconSizeStr.Split(TEXT(","), &XSize, &YSize);
					IconSize.X = FCString::Atof(*XSize);
					IconSize.Y = FCString::Atof(*YSize);
				}
				
				FSlateImageBrush* Brush = new FSlateImageBrush(IconPathStr, IconSize);
				FString StyleName = (*ItFunction)->GetOuter()->GetName() + TEXT(".") + (*ItFunction)->GetName();
				StyleSet->Set(FName(*StyleName), Brush);
			}
		}
	}
}

void UEasyMenuSubSystem::CollectMenuPath()
{
	for (TObjectIterator<UClass> ItClass; ItClass; ++ItClass)
	{
		UClass* TargetClass = *ItClass;
		
		if (ItClass->HasMetaData(TEXT(TEXT_EM_REROUTE)))
		{
			FString TargetClassName = ItClass->GetMetaData(TEXT(TEXT_EM_REROUTE));
			TargetClass = FindObjectSafe<UClass>(ANY_PACKAGE, *TargetClassName);
			if(TargetClass == nullptr)
			{
				TargetClass = FindObjectSafe<UClass>(ANY_PACKAGE, TEXT("Object"));
				UE_LOG(LogClass, Error, TEXT("Can't find Class: %s, Replace with Object "), *TargetClass->GetName())
			}
		}
		
		for (TFieldIterator<UFunction> ItFunction(*ItClass); ItFunction; ++ItFunction)
		{
			if (ItFunction->HasMetaData(TEXT(TEXT_EM_MENU_ITEM)))
			{
				CHECK_IS_STATIC_FUNCTION(ItFunction, ItClass);
				FString Path = ItFunction->GetMetaData(TEXT(TEXT_EM_MENU_ITEM));

				MenuHelper.AddMenu(Path, *ItFunction, TargetClass, true); 
			}
			else if (ItFunction->HasMetaData(TEXT_EM_ASSET_ITEM))
			{
				CHECK_IS_STATIC_FUNCTION(ItFunction, ItClass);
				FString Path = ItFunction->GetMetaData(TEXT(TEXT_EM_ASSET_ITEM));

				AssetEditorHelper.AddMenu(Path, *ItFunction, TargetClass, true); 
			}
			else if (ItFunction->HasMetaData(TEXT_EM_ACTOR_ITEM))
			{
				CHECK_IS_STATIC_FUNCTION(ItFunction, ItClass);
				FString Path = ItFunction->GetMetaData(TEXT(TEXT_EM_ACTOR_ITEM));

				ActorEditorHelper.AddMenu(Path, *ItFunction, TargetClass, true);
			}
			else if (ItFunction->HasMetaData(TEXT_EM_TOOLBAR_ITEM))
			{
				CHECK_IS_STATIC_FUNCTION(ItFunction, ItClass);
				FString Path = ItFunction->GetMetaData(TEXT(TEXT_EM_TOOLBAR_ITEM));

				ToolBarEditorHelper.AddMenu(Path, *ItFunction, TargetClass, true);
			}
		}
	}

	MenuHelper.SortPath();
	AssetEditorHelper.SortPath();
	ToolBarEditorHelper.SortPath();
	ActorEditorHelper.SortPath();
	
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuHelper.GetMenuBarExtender(TEXT("Help"), EExtensionHook::After));
}

void UEasyMenuSubSystem::InitToolBar()
{	
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolBarEditorHelper.GetToolbarExtender(TEXT("Settings"), EExtensionHook::After));
}

void UEasyMenuSubSystem::InitAssetEditMenu()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));
    	auto& ExtendArr = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
	
	ExtendArr.Add(FContentBrowserMenuExtender_SelectedAssets::CreateUObject(this, &UEasyMenuSubSystem::OnSelectAsset));
}

TSharedRef<FExtender> UEasyMenuSubSystem::OnSelectAsset(const TArray<FAssetData>& InAssets)
{
	UClass* LowestClass = nullptr;
	for (auto& Asset : InAssets)
	{
		if (LowestClass == nullptr)
		{
			LowestClass = Asset.GetClass();
			continue;
		}
		while (!Asset.GetClass()->IsChildOf(LowestClass))
		{
			LowestClass = LowestClass->GetSuperClass();
		}
	}
    
	AssetEditorHelper.CurrentClass = LowestClass;
	AssetEditorHelper.RebuildNodes();
	return AssetEditorHelper.GetMenuExtender(TEXT("AssetContextSourceControl"),EExtensionHook::After).ToSharedRef();
}


void UEasyMenuSubSystem::InitActorEditMenu()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::Get().LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	auto& MenuExtenders = LevelEditorModule.GetAllLevelViewportContextMenuExtenders();
	
	MenuExtenders.Add(FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors::CreateUObject(this, &UEasyMenuSubSystem::OnSelectActor));
}

TSharedRef<FExtender> UEasyMenuSubSystem::OnSelectActor(const TSharedRef<FUICommandList> InCommandList, const TArray<AActor*> InActors)
{
	UClass* LowestClass = nullptr;
	for (auto& Actor : InActors)
	{
		if (LowestClass == nullptr)
		{
			LowestClass = Actor->GetClass();
			continue;
		}
		while (!Actor->GetClass()->IsChildOf(LowestClass))
		{
			LowestClass = LowestClass->GetSuperClass();
		}
	}

	ActorEditorHelper.CurrentClass = LowestClass;
	ActorEditorHelper.RebuildNodes();
	return ActorEditorHelper.GetMenuExtender(TEXT("ActorControl"), EExtensionHook::Before).ToSharedRef();
}

void UEasyMenuSubSystem::AddIcon(const FString& InName, const FString& InPath, FVector2D Size)
{
	if (StyleSet->GetBrush(FName(*InName)) != StyleSet->GetDefaultBrush())
		return;
	FString Path = InPath;
	if (FPaths::IsRelative(InPath))
	{
		Path = ResolveIconPath(InPath);
	}
	FSlateImageBrush* Brush = new FSlateImageBrush(Path, Size);

	// combine style name 
	StyleSet->Set(FName(*InName), Brush);
}


FString UEasyMenuSubSystem::ResolveIconPath(const FString& InPath)
{
	FString IconPath = InPath;
	FString Root;
	FString RelativePath;
	IconPath.Split(TEXT("/"), &Root, &RelativePath);
	if (Root == TEXT(TEXT_EM_PROJECT))
	{
		IconPath = FPaths::Combine(FPaths::ProjectDir(), RelativePath);
	}
	else
	{
		IconPath = FPaths::Combine(IPluginManager::Get().FindPlugin(Root)->GetBaseDir(), RelativePath);
	}
	return FPaths::ConvertRelativePathToFull(IconPath);
}

#undef LOCTEXT_NAMESPACE