#pragma once
#include "EasyMenuStructs.h"
#include "Containers/Map.h"
#include "Framework/MultiBox/MultiBoxExtender.h"

class FMenuPathHelper
{
public:
	FMenuPathHelper();
    virtual ~FMenuPathHelper() { }

	void AddMenu(const FString& InPath, UFunction* InFunction, UClass* InTargetClass, bool AddToFunctionInfos);

	TSharedPtr<FExtender> GetMenuBarExtender(FName InHookName, EExtensionHook::Position InPosition);
	TSharedPtr<FExtender> GetMenuExtender(FName InHookName, EExtensionHook::Position InPosition);
	TSharedPtr<FExtender> GetToolbarExtender(FName InHookName, EExtensionHook::Position InPosition);
	
	void Reset(bool ResetFunctionInfos = true);

	//创建menu
	void BuildToolBar(FToolBarBuilder& InBuilder);
	void BuildMenuBar(FMenuBarBuilder& InBuilder, TSharedPtr<FMenuNode> InNode);
	void BuildMenu(FMenuBuilder& InBuilder, const TSharedPtr<FMenuNode> InNode);
	
	void CreateSection(FMenuBuilder& InBuilder, TSharedPtr<FMenuNode> InNode);
	void ExtendRootMenu(FMenuBuilder& InBuilder, TArray<TSharedPtr<FMenuNode>>* InEntryNodes);
	
	void AddMenuEntry(FBaseMenuBuilder& InBuilder, const TSharedPtr<FMenuNode> InNode);

	void SortPath();
	void SortPath(TArray<TSharedPtr<FMenuNode>>& ListNodes);

	void SetPathIcon(const FString& InPath, const FString& InIconPath);

	static TSharedPtr<FMenuNode> FindMenuNodeByNodeName(TArray<TSharedPtr<FMenuNode>> MenuList, FString MenuName);
public:
	FString	Name;//HelperName
	private:
	TArray<TSharedPtr<FMenuNode>> MenuNodes;
protected:
	TMap<UFunction*, FMenuFunctionInfo>	FunctionInfos;

protected:
	virtual void OnBeginPopUp(FMenuBuilder& InBuilder) {}
	virtual void OnEndPopUp(FMenuBuilder& InBuilder) {}
	virtual void OnEntryCallBegin() {}
	virtual void OnEntryCallEnd() {}
};
