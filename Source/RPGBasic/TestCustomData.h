// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "TestCustomData.generated.h"

USTRUCT(BlueprintType)
struct FTestCustomData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadOnly, Category = "TestCustomData")
	int32 SomeNumber;
	UPROPERTY(BlueprintReadOnly, Category = "TestCustomData")
	FString SomeString;
};
