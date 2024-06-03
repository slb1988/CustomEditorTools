# EasyMenu
UE界面代码简化插件，只需要少量代码就能实现很多UE界面的功能。


 __UE4在增加各种菜单栏的时候，需要写一大堆代码来增加，不能像Unity一样只需要增加一行标签即可。于是诞生了这个插件。__ 
以下是插件使用方法：
Tips：该类方法需要写在父类为UObject的类里面。

## （1）增加菜单栏

Meta关键词： `EMMenuItem` 

```
//只需要增加将菜单路径写到EMMenuItem标签内即可
UFUNCTION(meta=(EMMenuItem="EMExample/Simple/Example1"))
static void Example1(){ UKismetSystemLibrary::PrintString(GWorld, TEXT("Example1")); }
```

## （2）增加菜单栏分割

Meta关键词： `EMMenuItem` 

```
//在需要添加分类层级增加'.',前半段是分类，后半段是菜单名
UFUNCTION(meta=(EMMenuItem="EMExample/haha.heihei/Example2"))
static void Example2(){ UKismetSystemLibrary::PrintString(GWorld, TEXT("Example2")); }
```

## （3）ToolTip

Meta关键词： `EMMenuItem`   `ToolTip` 

```
//只需要添加ToolTip标签即可
UFUNCTION(meta=(EMMenuItem="EMExample1/Example5", ToolTip="这只是一个ToolTip"))
static void Example5(){ UKismetSystemLibrary::PrintString(GWorld, TEXT("Example5")); }
```

## （4）在ToolBar中快速添加按钮


Meta关键词： `EMToolbarItem` 

```
UCLASS()
class UTestExample : public UObject
{
   GENERATED_BODY()
public:
   UFUNCTION(meta=(EMToolbarItem="ToolBarTest", EMIcon="EasyMenu/Resources/Icon128.png"))
   static void ToolBarExample1();
};
```

## (5) 为Content Brower中的资产Asset文件添加右键菜单

Class中添加EMTargetClass可指定为某类资产（是该类或者继承于该关键字的类）添加右键菜单。
Meta关键词： `EMAssetItem` 

```
//为Content Brower中的资产Asset文件添加右键菜单
UCLASS(meta=(EMTargetClass="Object"))//目标文件所属父类
class UMyAssetExample : public UObject
{
   GENERATED_BODY()
public:
   UFUNCTION(meta=(EMAssetItem="AssetExample.Example/示例", EMIcon="EasyMenu/Resources/Icon128.png"))
   static void Example1();
};
```

## (6) 为World Outliner中的资产Actor添加右键菜单

Class中添加EMTargetClass可指定为某类资产（是该类或者继承于该关键字的类）添加右键菜单。
Meta关键词： `EMActorItem` 

```

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
```

## 更多功能详见WIKI： https://iwiki.woa.com/pages/viewpage.action?pageId=1524209237
