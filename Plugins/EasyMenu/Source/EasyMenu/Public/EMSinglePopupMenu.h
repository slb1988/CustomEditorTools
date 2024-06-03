#pragma once
#include "EMPopupMenuBase.h"

DECLARE_DELEGATE_OneParam(FOnEMEnumSinglePopupMenuSelected, int);
class EASYMENU_API FEMEnumSingleSelectPopupMenu : public FEMPopupMenuBase
{
public:
	FEMEnumSingleSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle);
	FEMEnumSingleSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle, TSharedPtr<FMenuNode> InMenuNode);
	FEMEnumSingleSelectPopupMenu(UEnum* InPopEnum, FOnEMEnumSinglePopupMenuSelected InOnPopupMenuSelected, FText InPopupTitle);
	~FEMEnumSingleSelectPopupMenu();
	virtual TSharedRef<SWidget> FillMenu() override;

	void Selection(int InIndex);
	ECheckBoxState IsSelection(int InIndex);
	
	
private:
	int SelectedIndex;
	FOnEMEnumSinglePopupMenuSelected OnPopupMenuSelected;
};