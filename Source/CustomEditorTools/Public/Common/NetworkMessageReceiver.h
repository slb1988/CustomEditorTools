// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NetworkMessageReceiver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNetworkMessageReceiver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CUSTOMEDITORTOOLS_API INetworkMessageReceiver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/**
	 * Function to handle the received network message
	 * @param MsgId 消息ID
	 * @param RawData 消息RawData
	 */
	virtual void OnNetworkMessageReceived(uint64 MsgId, const TArray<uint8>& RawData) = 0; 
};
