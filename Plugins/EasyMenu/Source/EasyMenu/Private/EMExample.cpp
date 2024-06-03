#include "EMExample.h"
#if defined(M_ENABLE_EZMENU_EXAMPLE)
#include "Kismet/KismetSystemLibrary.h"

void UTestExample::ToolBarExample1()
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个ToolBar菜单例子，代码中搜索我"));
}

void UTestExample::ToolBarExample2(int index)
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个ToolBar菜单例子，点击了Enum: ") + FString::FromInt(index));
}

void UTestExample::ToolBarExample3(TArray<int> indexs)
{
	FString StrIndexs;
	for(int index : indexs)
	{
		StrIndexs +=  FString::FromInt(index) + ",";
	}
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个ToolBar菜单例子，点击了Enum: ") + StrIndexs);
}

void UMyAssetExample::Example1()
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个Asset菜单例子，代码中搜索我"));
}

void UMyActorExample::Example1()
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个Actor菜单例子，代码中搜索我"));
}

void UMyActorExample1::Example1()
{
}

#endif