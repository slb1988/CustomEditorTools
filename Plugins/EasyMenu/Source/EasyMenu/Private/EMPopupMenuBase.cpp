#include "EMPopupMenuBase.h"


#define LOCTEXT_NAMESPACE "EMPopupMenuBase"

FEMPopupMenuBase::FEMPopupMenuBase(UEnum* InPopEnum, FText InPopupTitle)
{
	PopEnum = InPopEnum;
	PopupTitle = InPopupTitle;
	CommandList = MakeShareable(new FUICommandList);
}

FEMPopupMenuBase::FEMPopupMenuBase(UEnum* InPopEnum, FText InPopupTitle, TSharedPtr<FMenuNode> InMenuNode)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle)
{
	MenuNode = InMenuNode;
}

#undef LOCTEXT_NAMESPACE

