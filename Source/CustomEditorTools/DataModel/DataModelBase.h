// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataModelBase.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMEDITORTOOLS_API UDataModelBase : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * 是否需要持续保存，不要释放
	 */
	bool IsPersistent;

	/**
	 * 数据是否展开，按需展开，在第一次接到RawData时可能不展开
	 * 也可以通过展开的数据是否有内容来判断
	 */
	bool IsFirstInit = false;

	void Clear();
};
