// Fill out your copyright notice in the Description page of Project Settings.


#include "DataModelSubsystem.h"

#include "MainDataModel.h"
#include "TaskDataModel.h"

void UDataModelSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	const auto MainDataModel = NewObject<UMainDataModel>(this, "MainDataModel");
	const auto TaskDataModel = NewObject<UTaskDataModel>(this, "TaskDataModel");

	NetworkMessageReceivers.Reset();
	NetworkMessageReceivers.Add(TScriptInterface<INetworkMessageReceiver>(MainDataModel));
	NetworkMessageReceivers.Add(TScriptInterface<INetworkMessageReceiver>(TaskDataModel));

	// TODO 注册网络事件，作为DataModel的数据驱动 OnNetworkMessageReceived

	// 捕获特定游戏事件，对DataModel进行清理
}

void UDataModelSubsystem::Deinitialize()
{
	NetworkMessageReceivers.Reset();
	
	Super::Deinitialize();	
}

UDataModelSubsystem::~UDataModelSubsystem()
{
}

void UDataModelSubsystem::OnNetworkMessageReceived(uint64 MsgId, const TArray<uint8>& RawData)
{
	for (const auto Receiver : NetworkMessageReceivers)
	{
		Receiver->OnNetworkMessageReceived(MsgId, RawData);
	}
}
