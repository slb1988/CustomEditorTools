// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MySourceControlSettings.generated.h"

/**
 * 
 */
UCLASS(Config=MySourceControlSetting, DefaultConfig, meta=(DisplayName="SourceControl Setting"))
class CUSTOMEDITORTOOLS_API UMySourceControlSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere)
	TArray<FString> BranchNames;

	UPROPERTY(Config, EditAnywhere)
	FString ContentRootIn;
};
