// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "GameFramework/GameplayMessageSubsystem.h"
#include "UObject/UnrealTypePrivate.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AMyActor::AMyActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	// UClass* CharacterClass = LoadClass<ACharacter>(this, TEXT(""));
	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	int a = 2;
	PuerBlueprintFunc(a);
	UE_LOG(LogTemp, Warning, TEXT("puer change a -> %d"), a);
	
	int size = sizeof(UObject);
	UE_LOG(LogTemp, Warning, TEXT("%d"), size);

	TArray<UObject*> result;
	GetObjectsOfClass(UClass::StaticClass(), result);

	result.Reset();
	GetObjectsOfClass(UEnum::StaticClass(), result);
	
	result.Reset();
	GetObjectsOfClass(UScriptStruct::StaticClass(), result);

	const UClass* Class = AMyActor::StaticClass();
	//遍历属性
	for (TFieldIterator<UProperty> j(Class); j; ++j)
	{
		UProperty* prop = *j;
		UE_LOG(LogTemp, Log, TEXT("%s"), *prop->GetName());
	}

	TArray<FString> classNames;
	classNames.Add(Class->GetName());
	UClass* superClass = Class->GetSuperClass();
	while (superClass)
	{
		classNames.Add(superClass->GetName());
		superClass = superClass->GetSuperClass();
	}
	FString str = FString::Join(classNames, TEXT("->"));
	UE_LOG(LogTemp, Log, TEXT("%s"), *str);
	
	//遍历函数
	for (TFieldIterator<UFunction> i(Class); i; ++i)
	{
		UFunction* func=*i; 
		//遍历函数的参数
		for (TFieldIterator<UProperty> j(func); j; ++j)
		{
			UProperty* param=*j; 
			if( param->PropertyFlags & CPF_ReturnParm ) //这是返回值
			{
				UE_LOG(LogTemp, Log, TEXT("%s"), *param->GetName());
			}
		}
	}
	for (const FImplementedInterface& ii : Class->Interfaces)
	{
		UClass* interfaceClass = ii.Class;
		UE_LOG(LogTemp, Log, TEXT("%ls"), *interfaceClass->GetName());
	}

	const UEnum* enumClass = StaticEnum<EMyEnum>();
	for (int i = 0; i < enumClass->NumEnums(); ++i)
	{
		UE_LOG(LogTemp, Log, TEXT("Enum %s %d"), *enumClass->GetNameByIndex(i).ToString(), enumClass->GetValueByIndex(i))
	}

#if WITH_METADATA
	const UObject* obj = this;
	UMetaData* metaData = obj->GetOutermost()->GetMetaData();
	TMap<FName, FString>* keyValues = metaData->GetMapForObject(obj);
	if (keyValues != nullptr && keyValues->Num() > 0)
	{
		
	}
#endif
	

	UE_LOG(LogTemp, Log, TEXT("%d"), result.Num());
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::PuerBlueprintFunc(int& a)
{
	a = 2;
}

// void AMyActor::SendMessage(const FSampleMessage& InMessage)
// {
// 	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(GetWorld());
// 	MessageSubsystem.BroadcastMessage(TAG_Sample_Channel, InMessage);
// }

FTransform AMyActor::GetTransformTest() const
{
	return this->GetTransform();
}

// void AMyActor::BlueprintNativeFunc_Implementation()
// {
// }

void AMyActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void AMyActor::ClientRPC_Implementation(int a, int b)
{
}

void AMyActor::ServerRPC_Implementation(int a, int b)
{
}

bool AMyActor::ServerRPC_Validate(int a, int b)
{
	return true;
}

