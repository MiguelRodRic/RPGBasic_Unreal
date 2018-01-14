// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FEnemyInfo.generated.h"

USTRUCT(BlueprintType)
struct FEnemyInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EnemyInfo")
FString EnemyName;
	
UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")
int32 MHP;

UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")
int32 ATK;

UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")
int32 DEF;

UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")
int32 Luck;

UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")
TArray<FString> Abilities;


};
