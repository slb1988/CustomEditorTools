#pragma once
#include "Containers/UnrealString.h"
#include "Command/CommandBuffer.h"


#define TEXT_EM_ICON "EMIcon"
#define TEXT_EM_ICON_SIZE "EMIconSize"
#define TEXT_EM_STYLE "EMStyleSet"
#define TEXT_EM_MENU_ITEM "EMMenuItem"
#define TEXT_EM_ASSET_ITEM "EMAssetItem"
#define TEXT_EM_ACTOR_ITEM "EMActorItem"
#define TEXT_EM_TOOLBAR_ITEM "EMToolbarItem"
#define TEXT_EM_ENUM "EMEnum"
#define TEXT_EM_PROJECT "Project"
#define TEXT_EM_REROUTE "EMTargetClass"


class EASYMENU_API FEasyMenuGlobal
{
public:
	// Global 
	static bool IsMenuState;
	static bool IsDetailState;
	static bool IsActorState;
	static bool IsAssetState;
	static bool IsAssetNewState;
	static bool IsWindowState;
	static FEMCommandBuffer	CommdBuffer;
	
public:
	static void MenuState(bool InMenuState);
	static void AssetState(bool InAssetState);
	static void ActorState(bool InEnable);
	static void CleanState();
	static void CleanCommands();

	static void ResolveAssetCommands(FMenuBuilder& InBuilder);
	static void ResolveActorCommands(FMenuBuilder& InBuilder);
	static void ResolveMenuCommands(FMenuBuilder& InBuilder);


	static FString GetIconRealPath(const FString& InPath);
	static void AddEntry(const FString& InEntryName, const FString& InEntryIcon, const FSimpleDelegate& InEntryEvent);
	static void AddWidget(TSharedPtr<SWidget> InWidget);
	static void BeginSection(const FString& InSecName);
	static void EndSection();

public:
	static TArray<AActor*>	SelectedActors;
	static TArray<UObject*>	SelectedAssets;
private:
	static void ResolveMenuCommand(FMenuBuilder& InBuilder, const FEMCommand& InCmd, int CommandID);

};




