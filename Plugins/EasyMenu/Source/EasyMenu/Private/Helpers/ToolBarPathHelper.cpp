#include "Helpers/ToolBarPathHelper.h"

#include "EasyMenuGlobal.h"

void FToolBarPathHelper::OnBeginPopUp(FMenuBuilder& InBuilder)
{
	FEasyMenuGlobal::MenuState(true);
}

void FToolBarPathHelper::OnEndPopUp(FMenuBuilder& InBuilder)
{
	FEasyMenuGlobal::CleanState();
	FEasyMenuGlobal::ResolveMenuCommands(InBuilder);
	FEasyMenuGlobal::CleanCommands();
}