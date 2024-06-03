#pragma once
#include "Containers/UnrealString.h"

enum EEMCommandType
{
	Unknown ,
	
	Menu_AddEntry ,
	Menu_AddWidget ,
	Menu_BeginSection ,
	Menu_EndSection ,

	Detail_HideCategory ,
	Detail_EditCategory ,
	Detail_HideProperty ,
	Detail_EditProperty ,
	Detail_AddWidget ,
	Detail_AddProperty ,
};

struct FEMCommand
{
	EEMCommandType	CommandType;

	virtual ~FEMCommand(){}
};

struct FEMAddEntry : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Menu_AddEntry;
	FString			EntryName;
	FString			EntryIcon;
	FSimpleDelegate EntryEvent;
};


struct FEMAddWidget : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Menu_AddWidget;
	TSharedPtr<SWidget>		Widget;
};

struct FEMBeginSection : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Menu_BeginSection;
	FString		SectionName;
};

struct FEMEndSection : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Menu_EndSection;
};

struct FEMHideCategory : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Detail_HideCategory;
	FString		Category;
};

struct FEMEditCategory : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Detail_EditCategory;
	FString		Category;
	int32		Priority;
};

struct FEMHideProperty : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Detail_HideProperty;
	FString		PropertyName;
};

struct FEMEditProperty : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Detail_EditProperty;
	FString					PropertyName;
	FString					OverrideName;
	TSharedPtr<SWidget>		NameWidget;
	TSharedPtr<SWidget>		ValueWidget;
};

struct FEMDetailAddWidget : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Detail_AddWidget;
	FString					WidgetName;
	FString					SearchName;
	TSharedPtr<SWidget>		NameWidget;
	TSharedPtr<SWidget>		ValueWidget;
};

struct FEMAddProperty : public FEMCommand
{
	static constexpr auto Type = EEMCommandType::Detail_AddProperty;
	FString					PropertyName;
	FString					OverrideName;
	TSharedPtr<SWidget>		NameWidget;
	TSharedPtr<SWidget>		ValueWidget;
};
