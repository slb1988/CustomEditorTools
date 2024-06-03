#pragma once
#include "Templates/SharedPointer.h"
#include "Containers/UnrealString.h"

class FEMPopupMenuBase;

enum EMenuType
{
	Normal = 0,
	SingleEnumPopup = 1,
	MultiEnumPopup = 2
};

//菜单节点信息
struct FMenuNode
{
//public:
	FString	MenuName;
	FString	SectionName;
	FString	StyleSet;
	FString	StyleName;
	FString	TargetEnum;
	UFunction* BoundFunction;
	TArray<TSharedPtr<FMenuNode>> ChildNodes;
	FMenuNode* Parent;
	EMenuType MenuType;

	TSharedPtr<FEMPopupMenuBase> PopupMenu;
};

struct FMenuFunctionInfo
{
	FString	Path;
	FString	ToolTip;
	UClass*	TargetClass;
};
