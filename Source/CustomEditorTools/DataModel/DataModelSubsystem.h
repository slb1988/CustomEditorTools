// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Common/NetworkMessageReceiver.h"
#include "Subsystems/Subsystem.h"
#include "DataModelSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMEDITORTOOLS_API UDataModelSubsystem : public UGameInstanceSubsystem, public INetworkMessageReceiver
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	virtual ~UDataModelSubsystem() override;
	
	virtual void OnNetworkMessageReceived(uint64 MsgId, const TArray<uint8>& RawData) override;

private:

	TArray<TScriptInterface<INetworkMessageReceiver>> NetworkMessageReceivers;
};
