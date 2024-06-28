// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataModelBase.h"
#include "Common/NetworkMessageReceiver.h"
#include "MainDataModel.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMEDITORTOOLS_API UMainDataModel : public UDataModelBase, public INetworkMessageReceiver
{
	GENERATED_BODY()

public:
	virtual void OnNetworkMessageReceived(uint64 MsgId, const TArray<uint8>& RawData) override;

	TMap<int32, FString> Items;
};
