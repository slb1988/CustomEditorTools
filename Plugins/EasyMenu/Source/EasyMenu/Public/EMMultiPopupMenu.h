#pragma once
#include "EMPopupMenuBase.h"

DECLARE_DELEGATE_OneParam(FOnEMEnumMultiPopupMenuSelected, TArray<int>);
class EASYMENU_API FEMEnumMultiSelectPopupMenu : public FEMPopupMenuBase
{
public:
	FEMEnumMultiSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle);
	FEMEnumMultiSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle, TSharedPtr<FMenuNode> InMenuNode);
	FEMEnumMultiSelectPopupMenu(UEnum* InPopEnum, FOnEMEnumMultiPopupMenuSelected InOnPopupMenuSelected, FText InPopupTitle);
	~FEMEnumMultiSelectPopupMenu() {};
	virtual TSharedRef<SWidget> FillMenu() override;

	void Selection(int InIndex);
	ECheckBoxState IsSelection(int InIndex);
	
	
private:
	TMap<int, bool> Selected;
	FOnEMEnumMultiPopupMenuSelected OnPopupMenuSelected;
};