#include "EasyMenuGlobal.h"

#include "ContentBrowserModule.h"
#include "EasyMenuSubSystem.h"
#include "Editor.h"
#include "IContentBrowserSingleton.h"
#include "Engine/Selection.h"
#include "Interfaces/IPluginManager.h"


bool FEasyMenuGlobal::IsMenuState = false;
bool FEasyMenuGlobal::IsDetailState = false;
bool FEasyMenuGlobal::IsActorState = false;
bool FEasyMenuGlobal::IsAssetState = false;
bool FEasyMenuGlobal::IsAssetNewState = false;
bool FEasyMenuGlobal::IsWindowState = false;
FEMCommandBuffer FEasyMenuGlobal::CommdBuffer;

TArray<AActor*>	FEasyMenuGlobal::SelectedActors;
TArray<UObject*> FEasyMenuGlobal::SelectedAssets;

void FEasyMenuGlobal::MenuState(bool InMenuState)
{
	IsMenuState = InMenuState;
}

void FEasyMenuGlobal::AssetState(bool InAssetState)
{
	IsAssetState = InAssetState;
}

void FEasyMenuGlobal::ActorState(bool InEnable)
{
	IsActorState = InEnable;
}

void FEasyMenuGlobal::CleanState()
{
	IsMenuState = false;
	IsDetailState = false;
	IsActorState = false;
	IsAssetState = false;
}

void FEasyMenuGlobal::CleanCommands()
{
	CommdBuffer.Reset();
}

void FEasyMenuGlobal::ResolveAssetCommands(FMenuBuilder& InBuilder)
{
	FEMCommandBuffer& Buffer = FEasyMenuGlobal::CommdBuffer;

	EEMCommandType Cmd = Buffer.Peek();

	int32 Count = 0;
	while (Cmd != EEMCommandType::Unknown)
	{
		switch (Cmd)
		{
		case EEMCommandType::Menu_AddEntry:
			{
				FEMAddEntry AddEntry = Buffer.Read<FEMAddEntry>();
				AddEntry.EntryEvent = FSimpleDelegate::CreateLambda([Event=AddEntry.EntryEvent]
				{
					FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
					TArray<FAssetData> SelectedAssets;
					ContentBrowserModule.Get().GetSelectedAssets(SelectedAssets);
					for (FAssetData& Asset : SelectedAssets)
					{
						FEasyMenuGlobal::SelectedAssets.Add(Asset.GetAsset());
					}
					FEasyMenuGlobal::AssetState(true);

					Event.ExecuteIfBound();
				
					FEasyMenuGlobal::SelectedAssets.Reset();
					FEasyMenuGlobal::AssetState(false);
				});
				ResolveMenuCommand(InBuilder, AddEntry, Count);
				break;
			}
		case EEMCommandType::Menu_AddWidget:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMAddWidget>(), Count); break;
		case EEMCommandType::Menu_BeginSection:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMBeginSection>(), Count); break;
		case EEMCommandType::Menu_EndSection:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMEndSection>(), Count);break;
		default: checkNoEntry();
		}
		Cmd = Buffer.Peek();
		++Count;
	}
}



void FEasyMenuGlobal::ResolveMenuCommand(FMenuBuilder& InBuilder, const FEMCommand& InCmd, int CommandID)
{
	switch (InCmd.CommandType)
	{
	case EEMCommandType::Menu_AddEntry:
		{
			const FEMAddEntry& Cmd = static_cast<const FEMAddEntry&>(InCmd);

			FString StyleSet, StyleName;
			if (!Cmd.EntryIcon.Split(TEXT("::"), &StyleSet, &StyleName))
			{
				StyleSet = TEXT(TEXT_EM_STYLE);
				StyleName = TEXT("Entry.") + Cmd.EntryIcon;
				UEasyMenuSubSystem::Instance()->AddIcon(StyleName, Cmd.EntryIcon);
			}

			InBuilder.AddMenuEntry(
				FText::FromString(Cmd.EntryName),
				FText::GetEmpty(),
				FSlateIcon(*StyleSet, *StyleName),
				FUIAction(Cmd.EntryEvent));
			break;
		}
	case EEMCommandType::Menu_AddWidget:
		{
			const FEMAddWidget& Cmd = static_cast<const FEMAddWidget&>(InCmd);

			InBuilder.AddWidget(Cmd.Widget.ToSharedRef(), FText::GetEmpty());
			break;
		}
	case EEMCommandType::Menu_BeginSection:
		{
			const FEMBeginSection& Cmd = static_cast<const FEMBeginSection&>(InCmd);

			InBuilder.BeginSection(*Cmd.SectionName, FText::FromString(Cmd.SectionName));
			break;
		}
	case EEMCommandType::Menu_EndSection:
		{
			InBuilder.EndSection();
			break;
		}
	default: checkNoEntry();
	}
}


void FEasyMenuGlobal::ResolveActorCommands(FMenuBuilder& InBuilder)
{
	FEMCommandBuffer& Buffer = FEasyMenuGlobal::CommdBuffer;

	EEMCommandType Cmd = Buffer.Peek();

	int32 Count = 0;
	while (Cmd != EEMCommandType::Unknown)
	{
		switch (Cmd)
		{
		case EEMCommandType::Menu_AddEntry:
			{
				FEMAddEntry AddEntry = Buffer.Read<FEMAddEntry>();
				AddEntry.EntryEvent = FSimpleDelegate::CreateLambda([Event=AddEntry.EntryEvent]
				{
					GEditor->GetSelectedActors()->GetSelectedObjects(SelectedActors);
					ActorState(true);

					Event.ExecuteIfBound();

					ActorState(false);
					SelectedActors.Reset();
				});
				ResolveMenuCommand(InBuilder, AddEntry, Count);
				break;
			}
		case EEMCommandType::Menu_AddWidget:	ResolveMenuCommand(InBuilder, Buffer.Read<FEMAddWidget>(), Count); break;
		case EEMCommandType::Menu_BeginSection:	ResolveMenuCommand(InBuilder, Buffer.Read<FEMBeginSection>(), Count); break;
		case EEMCommandType::Menu_EndSection:	ResolveMenuCommand(InBuilder, Buffer.Read<FEMEndSection>(), Count);break;
		default: checkNoEntry();
		}
		Cmd = Buffer.Peek();
		++Count;
	}
}


void FEasyMenuGlobal::ResolveMenuCommands(FMenuBuilder& InBuilder)
{
	FEMCommandBuffer& Buffer = FEasyMenuGlobal::CommdBuffer;

	EEMCommandType Cmd = Buffer.Peek();

	int32 Count = 0;
	while (Cmd != EEMCommandType::Unknown)
	{
		switch (Cmd)
		{
		case EEMCommandType::Menu_AddEntry:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMAddWidget>(), Count);
			break;
		case EEMCommandType::Menu_AddWidget:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMAddWidget>(), Count);
			break;
		case EEMCommandType::Menu_BeginSection:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMBeginSection>(), Count);
			break;
		case EEMCommandType::Menu_EndSection:
			ResolveMenuCommand(InBuilder, Buffer.Read<FEMEndSection>(), Count);
			break;
		default: checkNoEntry();
		}
		Cmd = Buffer.Peek();
		++Count;
	}
}


FString FEasyMenuGlobal::GetIconRealPath(const FString& InPath)
{
	FString LeftPath;
	FString RightPath;
	InPath.Split(TEXT("/"), &LeftPath, &RightPath);

	FString IconRealPath = "";
	if (LeftPath == TEXT(TEXT_EM_PROJECT))
	{
		IconRealPath = FPaths::Combine(FPaths::ProjectDir(), RightPath);
	}
	else
	{
		IconRealPath = FPaths::Combine(IPluginManager::Get().FindPlugin(LeftPath)->GetBaseDir(), RightPath);
	}
	return FPaths::ConvertRelativePathToFull(IconRealPath);
}

void FEasyMenuGlobal::AddEntry(const FString& InEntryName, const FString& InEntryIcon,
	const FSimpleDelegate& InEntryEvent)
{
	FEMAddEntry Cmd;
	Cmd.EntryName = InEntryName;
	Cmd.EntryIcon = InEntryIcon;
	Cmd.EntryEvent = InEntryEvent;
	FEasyMenuGlobal::CommdBuffer.Write(Cmd);
}

void FEasyMenuGlobal::AddWidget(TSharedPtr<SWidget> InWidget)
{
	FEMAddWidget Cmd;
	Cmd.Widget = InWidget;
	FEasyMenuGlobal::CommdBuffer.Write(Cmd);
}

void FEasyMenuGlobal::BeginSection(const FString& InSecName)
{
	FEMBeginSection Cmd;
	Cmd.SectionName = InSecName;
	FEasyMenuGlobal::CommdBuffer.Write(Cmd);
}

void FEasyMenuGlobal::EndSection()
{
	FEMEndSection Cmd;
	FEasyMenuGlobal::CommdBuffer.Write(Cmd);
}