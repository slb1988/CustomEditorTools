// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMEDITORTOOLS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	UFUNCTION(Exec)
	void TestLoadPak(FString InPakFullPath);

private:
	TSharedPtr<class FPakPlatformFile> PakPlatformFile;
	IPlatformFile* InnerPlatformFile;
};
