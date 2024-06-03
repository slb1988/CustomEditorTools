#pragma once
#include "MenuPathHelper.h"

class FToolBarPathHelper : public FMenuPathHelper
{
public:
	FToolBarPathHelper()
	{
		Name = TEXT("ToolBar");
	}
protected:
	virtual void OnBeginPopUp(FMenuBuilder& InBuilder) override;
	virtual void OnEndPopUp(FMenuBuilder& InBuilder) override;
};
