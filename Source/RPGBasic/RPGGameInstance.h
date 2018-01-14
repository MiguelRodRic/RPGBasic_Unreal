// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameCharacter.h"
#include "RPGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RPGBASIC_API URPGGameInstance : public UGameInstance
{
	GENERATED_BODY()

	URPGGameInstance(const class FObjectInitializer & ObjectInitializer);

public:

	TArray<UGameCharacter*> PartyMembers;
	
protected:
	bool isInitialized;

public:

	void PrepareReset();

	void Init();
};
