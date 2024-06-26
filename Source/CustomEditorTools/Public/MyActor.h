// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
// #include "GameplayMessage/SampleMessage.h"
#include "MyActor.generated.h"

UENUM(BlueprintType)
enum class EMyEnum : uint8
{
	MY_Dance    UMETA(DisplayName = "Dance"),
	MY_Rain     UMETA(DisplayName = "Rain"),
	MY_Song     UMETA(DisplayName = "Song")
};

UCLASS()
class CUSTOMEDITORTOOLS_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	AMyActor(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UPROPERTY(BlueprintReadOnly, Category=PlayerController)
	// AActor* TestProperty;

	UPROPERTY(Replicated)
	int RepProperty;

	UPROPERTY(BlueprintReadWrite)
	FString TestStr;
	UPROPERTY(BlueprintReadWrite)
	FString TestStr2;
	UPROPERTY(BlueprintReadWrite)
	FString TestStr3;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRPC(int a, int b);

	UFUNCTION(Client, Reliable)
	void ClientRPC(int a, int b);

	// 没有执行引脚
	UFUNCTION(BlueprintPure)
	void PuerBlueprintFunc(int& a);

	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintImplFunc();

	// UFUNCTION(BlueprintNativeEvent)
	// void BlueprintNativeFunc();

	// UFUNCTION(BlueprintCallable)
	// void SendMessage(const FSampleMessage& InMessage);

	UFUNCTION(BlueprintCallable)
	FTransform GetTransformTest() const;
	
	UPROPERTY(EditAnywhere)
	FGameplayTag TAG_Sample_Channel;
};
