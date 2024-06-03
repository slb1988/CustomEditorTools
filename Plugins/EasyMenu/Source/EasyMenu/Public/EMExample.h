#pragma once
#include "Kismet/KismetSystemLibrary.h"

// oscar:在下面注释头增加一个‘/’进行切换，仅本地测试开启，不要上传P4
#define M_ENABLE_EZMENU_EXAMPLE

#include "EMExample.generated.h"


UCLASS()
class UMenuTest : public UObject
{
	GENERATED_BODY()
public:
	//只需要增加将菜单路径写到EMMenuItem标签内即可
	UFUNCTION(meta=(EMMenuItem="EMExample/Simple/Example1"))
	static void Example1(){ UKismetSystemLibrary::PrintString(GWorld, TEXT("Example1")); }

	//在需要添加分类层级增加'.',前半段是分类，后半段是菜单名
	UFUNCTION(meta=(EMMenuItem="EMExample/haha.heihei/Example2"))
	static void Example2(){ UKismetSystemLibrary::PrintString(GWorld, TEXT("Example2")); }

	//只需要添加ToolTip标签即可
	UFUNCTION(meta=(EMMenuItem="EMExample1/Example5", ToolTip="这只是一个ToolTip"))
	static void Example5(){ UKismetSystemLibrary::PrintString(GWorld, TEXT("Example5")); }
};

//为ToolBar快速添加按钮
UCLASS()
class UTestExample : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(meta=(EMToolbarItem="ToolBarTest", EMIcon="EasyMenu/Resources/Icon128.png"))
	static void ToolBarExample1();


	UFUNCTION(meta=(EMEnumSinglePopupMenu, EMToolbarItem="SingltPopupTest", EMIcon="EasyMenu/Resources/Icon128.png", EMEnum="EShowTextType"))
	static void ToolBarExample2(int index);

	UFUNCTION(meta=(EMEnumMultiPopupMenu, EMToolbarItem="MultiPopupTest", EMIcon="EasyMenu/Resources/Icon128.png", EMEnum="EShowTextType"))
	static void ToolBarExample3(TArray<int> indexs);
};



//为Content Brower中的资产Asset文件添加右键菜单
UCLASS(meta=(EMTargetClass="Object"))//目标文件所属父类
class UMyAssetExample : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(meta=(EMAssetItem="AssetExample.Example/示例", EMIcon="EasyMenu/Resources/Icon128.png"))
	static void Example1();
};


UCLASS(meta=(EMTargetClass="Actor"))
class UMyActorExample : public UObject
{
	GENERATED_BODY()
public:
	// Example1: Actor action
	UFUNCTION(meta=(EMActorItem="ActorExample.Example1", EMIcon="EasyMenu/Resources/Icon128.png"))
	static void Example1();

	// Menu usage same as menu example 
};

UCLASS(meta=(EMTargetClass="AcActorPoiRay"))
class UMyActorExample1 : public UObject
{
	GENERATED_BODY()
public:
	// Example1: Actor action
	UFUNCTION(meta=(EMActorItem="ActorExample.Example2", EMIcon="EasyMenu/Resources/Icon128.png"))
	static void Example1();

	// Menu usage same as menu example 
};
