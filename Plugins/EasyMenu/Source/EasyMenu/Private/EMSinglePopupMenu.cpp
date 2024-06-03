#include "EMSinglePopupMenu.h"

#include "EasyMenuStyle.h"

#define LOCTEXT_NAMESPACE "FEMEnumSingleSelectPopupMenu"

FEMEnumSingleSelectPopupMenu::FEMEnumSingleSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle)
{
}

FEMEnumSingleSelectPopupMenu::FEMEnumSingleSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle,
	TSharedPtr<FMenuNode> InMenuNode)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle, InMenuNode)
{
}

FEMEnumSingleSelectPopupMenu::FEMEnumSingleSelectPopupMenu(UEnum* InPopEnum, FOnEMEnumSinglePopupMenuSelected InOnPopupMenuSelected, FText InPopupTitle)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle)
{
	SelectedIndex = 0;
	MenuExtender = MakeShareable(new FExtender());
	OnPopupMenuSelected = InOnPopupMenuSelected;
}

FEMEnumSingleSelectPopupMenu::~FEMEnumSingleSelectPopupMenu()
{
	
}

TSharedRef<SWidget> FEMEnumSingleSelectPopupMenu::FillMenu()
{
	FMenuBuilder MenuBuilder(true, CommandList, MenuExtender);
	MenuBuilder.BeginSection("Switch Text", PopupTitle);
	{
		for (int32 i = 0; i < PopEnum->NumEnums() - 1; i++)
		{
			
			TSharedPtr<FUICommandInfo> CommandInfo;
			FText DisplayName = PopEnum->GetDisplayNameTextByIndex(i);
			MenuBuilder.AddMenuEntry(DisplayName,
			FText::FromString(FString::FromInt(i)),
			FSlateIcon(),
			FUIAction(
			FExecuteAction::CreateRaw(this, &FEMEnumSingleSelectPopupMenu::Selection, i), 
			FCanExecuteAction(),
			FGetActionCheckState::CreateRaw(this, &FEMEnumSingleSelectPopupMenu::IsSelection, i)
			), 
			NAME_None,
			EUserInterfaceActionType::RadioButton
			);
			EnumCommands.Add(i, CommandInfo);
		}
	}
	MenuBuilder.EndSection();
	return MenuBuilder.MakeWidget();
}

void FEMEnumSingleSelectPopupMenu::Selection(int InIndex)
{
	SelectedIndex = InIndex;
	if(OnPopupMenuSelected.IsBound())
		OnPopupMenuSelected.Execute(SelectedIndex);
	if(MenuNode->BoundFunction != nullptr)
	{
		UClass* FunctionOwnerClass = MenuNode->BoundFunction->GetOuterUClass();
		if(FunctionOwnerClass)
		{
			UObject* DefaultObject = FunctionOwnerClass->GetDefaultObject();
			if(DefaultObject)
				DefaultObject->ProcessEvent(MenuNode->BoundFunction, &SelectedIndex);
		}
	}
}

ECheckBoxState FEMEnumSingleSelectPopupMenu::IsSelection(int InIndex) 
{
	return SelectedIndex == InIndex ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}
#undef LOCTEXT_NAMESPACE
