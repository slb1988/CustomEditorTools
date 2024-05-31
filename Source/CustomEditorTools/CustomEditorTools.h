// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


class ISourceControlProvider;

class FCustomEditorToolModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;

	virtual bool IsGameModule() const override;

private:
#if UE_EDITOR
	void SourceControlRegisterStateBranches();

	static FDelegateHandle ModifyCookDelegateHandle;
	void OnModifyCook(TArrayView<const ITargetPlatform* const> InTargetPlatforms, TArray<FName>& InOutPackagesToCook, TArray<FName>& InOutPackagesToNeverCook);
#endif

	FDelegateHandle DelegateHandle;
};