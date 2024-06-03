
#include "Helpers/ActorMenuPathHelper.h"

#include "EasyMenuGlobal.h"
#include "Editor.h"
#include "Engine/Selection.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"


void FActorMenuPathHelper::OnBeginPopUp(FMenuBuilder& InBuilder)
{
	FEasyMenuGlobal::MenuState(true);
	OnEntryCallBegin();
}

void FActorMenuPathHelper::OnEndPopUp(FMenuBuilder& InBuilder)
{
	OnEntryCallEnd();
	FEasyMenuGlobal::CleanState();
	FEasyMenuGlobal::ResolveActorCommands(InBuilder);
	FEasyMenuGlobal::CleanCommands();
}

void FActorMenuPathHelper::OnEntryCallBegin()
{
	GEditor->GetSelectedActors()->GetSelectedObjects(FEasyMenuGlobal::SelectedActors);
	FEasyMenuGlobal::ActorState(true);
}

void FActorMenuPathHelper::OnEntryCallEnd()
{
	FEasyMenuGlobal::ActorState(false);
	FEasyMenuGlobal::SelectedActors.Reset();
}

void FActorMenuPathHelper::RebuildNodes()
{
	Reset(false);
	for (auto& Info : FunctionInfos)
	{
		if (CurrentClass->IsChildOf(Info.Value.TargetClass))
		{
			AddMenu(Info.Value.Path, Info.Key, Info.Value.TargetClass, false);
		}
	}
}

