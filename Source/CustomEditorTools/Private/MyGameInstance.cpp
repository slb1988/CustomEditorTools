// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "text_cn_generated.h"

#define PROJECT_CONFIG_FILE TEXT("Config.json")

void UMyGameInstance::Init()
{
	Super::Init();

	if (IsRunningDedicatedServer())
	{
		FCoreDelegates::OnFEngineLoopInitComplete.AddWeakLambda(this, [this]()
		{
			DedicatedServerReady();
		});
	}
	else
	{
		LoadServerDispatchUrl();
	}

	LoadFlatBuffersDataTest();
}

void UMyGameInstance::LoadServerDispatchUrl()
{
	FString StrContent;
#if PLATFORM_ANDROID
	StrContent = FAndroidMisc::LoadTextFileFromPlatformPackage(PROJECT_CONFIG_FILE);
#elif PLATFORM_IOS
	StrContent = FIOSPlatformMisc::LoadTextFileFromPlatformPackage(PROJECT_CONFIG_FILE);
#else
	IFileManager& FileManager = IFileManager::Get();

	const FString FilePath = FPaths::Combine(FPaths::ProjectContentDir(), PROJECT_CONFIG_FILE);;
	if (FileManager.FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("LoadServerDispatchUrl Got it %s"), *FilePath);

		FFileHelper::LoadFileToString(StrContent, *FilePath);

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LoadServerDispatchUrl Cannot find %s"), *FilePath);
	}
#endif
	if (StrContent.IsEmpty() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("find content : %s"), *StrContent);
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(StrContent);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		const TSharedPtr<FJsonValue> Url = JsonObject.Get()->GetField<EJson::String>(TEXT("dispatch_url"));

		UE_LOG(LogTemp, Warning, TEXT("LoadServerDispatchUrl Url: %s"), *Url.Get()->AsString());
	}
}

void UMyGameInstance::LoadFlatBuffersDataTest()
{
	fb::text_cnT table;
	//table.text_cns
	
}
