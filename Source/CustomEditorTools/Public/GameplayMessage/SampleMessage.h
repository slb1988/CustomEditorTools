// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SampleMessage.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSampleMessage
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MyNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MyString;
};
