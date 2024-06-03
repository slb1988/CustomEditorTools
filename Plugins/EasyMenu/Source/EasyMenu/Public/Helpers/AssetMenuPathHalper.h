#pragma once
#include "EasyMenuStructs.h"
#include "MenuPathHelper.h"

class FAssetMenuPathHalper : public FMenuPathHelper
{
public:
	FAssetMenuPathHalper()
	{
		Name = TEXT("AssetMenu");
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

