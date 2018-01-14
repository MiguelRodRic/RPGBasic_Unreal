// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FCharacterInfo.generated.h"

USTRUCT(BlueprintType)
struct FCharacterInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="CharacterInfo")
FString Character_Name;
UPROPERTY(BlueprintReadOnly, EditAnywhere, Category ="CharacterInfo")
FString Class_ID;

	
	
};
