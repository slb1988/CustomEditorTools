#pragma once
#include "EasyMenuStructs.h"

class EASYMENU_API FEMPopupMenuBase
{

public:
	FEMPopupMenuBase(UEnum* InPopEnum, FText InPopupTitle);
	FEMPopupMenuBase(UEnum* InPopEnum, FText InPopupTitle, TSharedPtr<FMenuNode> InMenuNode);
	virtual TSharedRef<SWidget> FillMenu() { return SNew(SSpacer);};

public:
	TSharedPtr<FMenuNode> MenuNode;
protected:
	UEnum* PopEnum;
	TMap<int, TSharedPtr<FUICommandInfo>> EnumCommands;
	TSharedPtr<FExtender> MenuExtender;
	FText PopupTitle;
	
	TSharedPtr<FUICommandList> CommandList;
};
