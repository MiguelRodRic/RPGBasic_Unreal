// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FCharacterClassInfo.generated.h"

USTRUCT(BlueprintType)
struct FCharacterClassInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	FString Class_Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 StartMHP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 StartMMP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 StartATK;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 StartDEF;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 StartLuck;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 EndMHP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 EndMMP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 EndATK;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 EndDEF;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 EndLuck;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	TArray<FString> StartingAbilities;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	TArray<FString> LearnedAbilities;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	TArray<int32> LearnedAbilityLevels;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 XP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 MXP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassInfo")
	int32 Lvl;
};
