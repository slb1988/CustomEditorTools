// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMEDITORTOOLS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    // Function to print UObject properties with indentation
    UFUNCTION(BlueprintCallable, Category = "Debug")
    static void PrintObjectProperties(UObject* Object, int32 Indent = 4);

private:
    static void PrintProperty(FProperty* Property, void* PropertyValue, int32 Indent);
};
