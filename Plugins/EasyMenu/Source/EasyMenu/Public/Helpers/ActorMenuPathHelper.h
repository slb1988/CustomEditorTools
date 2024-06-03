#pragma once
#include "EasyMenuStructs.h"
#include "Helpers/MenuPathHelper.h"

class FActorMenuPathHelper : public FMenuPathHelper
{
public:
	FActorMenuPathHelper()
	{
		Name = TEXT("ActorMenu");
	}
	void RebuildNodes();
protected:
	virtual void OnBeginPopUp(FMenuBuilder& InBuilder) override;
	virtual void OnEndPopUp(FMenuBuilder& InBuilder) override;
	virtual void OnEntryCallBegin() override;
	virtual void OnEntryCallEnd() override;
public:
	UClass*		CurrentClass;
};