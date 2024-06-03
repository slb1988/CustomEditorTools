#include "EMMultiPopupMenu.h"

#include "EasyMenuStyle.h"

#define LOCTEXT_NAMESPACE "FEMEnumSingleSelectPopupMenu"

FEMEnumMultiSelectPopupMenu::FEMEnumMultiSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle)
{
	MenuExtender = MakeShareable(new FExtender());
	for (int32 i = 0; i < PopEnum->NumEnums() - 1; i++)
	{
		Selected.Add(i, false);
	}
}

FEMEnumMultiSelectPopupMenu::FEMEnumMultiSelectPopupMenu(UEnum* InPopEnum, FText InPopupTitle,TSharedPtr<FMenuNode> InMenuNode)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle, InMenuNode)
{
	MenuExtender = MakeShareable(new FExtender());
	for (int32 i = 0; i < PopEnum->NumEnums() - 1; i++)
	{
		Selected.Add(i, false);
	}
}

FEMEnumMultiSelectPopupMenu::FEMEnumMultiSelectPopupMenu(UEnum* InPopEnum, FOnEMEnumMultiPopupMenuSelected InOnPopupMenuSelected, FText InPopupTitle)
	: FEMPopupMenuBase(InPopEnum, InPopupTitle)
{
	MenuExtender = MakeShareable(new FExtender());
	OnPopupMenuSelected = InOnPopupMenuSelected;
	for (int32 i = 0; i < PopEnum->NumEnums() - 1; i++)
	{
		Selected.Add(i, false);
	}
}

TSharedRef<SWidget> FEMEnumMultiSelectPopupMenu::FillMenu()
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
			FExecuteAction::CreateRaw(this, &FEMEnumMultiSelectPopupMenu::Selection, i), 
			FCanExecuteAction(),
			FGetActionCheckState::CreateRaw(this, &FEMEnumMultiSelectPopupMenu::IsSelection, i)
			), 
			NAME_None,
			EUserInterfaceActionType::Check
			);
			EnumCommands.Add(i, CommandInfo);
		}
	}
	MenuBuilder.EndSection();
	return MenuBuilder.MakeWidget();
}

void FEMEnumMultiSelectPopupMenu::Selection(int InIndex)
{
	Selected[InIndex] = !Selected[InIndex];

	TArray<int> SelectedIndexs;
	for(TPair<int, bool> Select : Selected)
	{
		if(Select.Value)
			SelectedIndexs.Add(Select.Key);
	}
	
	if(OnPopupMenuSelected.IsBound())
	{
		OnPopupMenuSelected.Execute(SelectedIndexs);
	}
	if(MenuNode->BoundFunction != nullptr)
	{
		UClass* FunctionOwnerClass = MenuNode->BoundFunction->GetOuterUClass();
		if(FunctionOwnerClass)
		{
			UObject* DefaultObject = FunctionOwnerClass->GetDefaultObject();
			if(DefaultObject)
				DefaultObject->ProcessEvent(MenuNode->BoundFunction, &SelectedIndexs);
		}
	}
}

ECheckBoxState FEMEnumMultiSelectPopupMenu::IsSelection(int InIndex) 
{
	return Selected[InIndex] ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}
#undef LOCTEXT_NAMESPACE
