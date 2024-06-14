// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

static int a;
UCLASS()
class CUSTOMEDITORTOOLS_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	AMyActor(const FObjectInitializer& ObjectInitializer);

	static int b;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	FString TestStr;
	UPROPERTY(BlueprintReadWrite)
	FString TestStr2;
};
