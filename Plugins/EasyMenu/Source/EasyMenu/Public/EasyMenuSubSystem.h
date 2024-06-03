#pragma once
#include "Editor.h"
#include "EditorSubsystem.h"
#include "Helpers/ActorMenuPathHelper.h"
#include "Helpers/AssetMenuPathHalper.h"
#include "Helpers/ToolBarPathHelper.h"
#include "Styling/SlateStyle.h"

#include "EasyMenuSubSystem.generated.h"


#define COND_ERR(Cond , FmtText, ...) while(!Cond) { UE_LOG(LogClass, Error, FmtText, __VA_ARGS__); break; }
#define CHECK_IS_STATIC_FUNCTION(InFunc, InClass) COND_ERR(InFunc->HasAnyFunctionFlags(EFunctionFlags::FUNC_Static),\
TEXT("Class [%s]: The function [%s] must be static function"), *(InClass->GetName()), *InFunc->GetName());

UCLASS()
class UEasyMenuSubSystem : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	UEasyMenuSubSystem(); 

	static UEasyMenuSubSystem* Instance()
	{
		return GEditor->GetEditorSubsystem<UEasyMenuSubSystem>();
	}

	void AddIcon(const FString& InName, const FString& InPath, FVector2D Size = FVector2D(40, 40));
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
private:
	void CollectIcons();
	void CollectMenuPath();
	
	void InitAssetEditMenu();
	void InitActorEditMenu();
	void InitToolBar();

	FString ResolveIconPath(const FString& InPath);
	
	TSharedRef<FExtender> OnSelectAsset(const TArray<FAssetData>& InAssets);
	TSharedRef<FExtender> OnSelectActor(const TSharedRef<FUICommandList> InCommandList, const TArray<AActor*> InActors);

private:
	TSharedPtr<FSlateStyleSet>	StyleSet;
	
	FMenuPathHelper	MenuHelper;
	FAssetMenuPathHalper AssetEditorHelper;
	FActorMenuPathHelper ActorEditorHelper;
	FToolBarPathHelper ToolBarEditorHelper;
};

