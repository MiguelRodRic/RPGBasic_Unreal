// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCharacterClassInfo.h"
#include "FCharacterInfo.h"
#include "FEnemyInfo.h"
#include "TestCombatAction.h"
#include "ICombatAction.h"
#include "TestDecisionMaker.h"
#include "IDecisionMaker.h"
#include "GameCharacter.generated.h"

/**
 * 
 */
class CombatEngine;

UCLASS( BlueprintType)
class RPGBASIC_API UGameCharacter : public UObject
{
	GENERATED_BODY()
	
public:
	CombatEngine * combatInstance;

	FCharacterClassInfo * ClassInfo;

	ICombatAction * combatAction;

	IDecisionMaker * decisionMaker;

	float testDelayTimer;

	bool isPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	FString CharacterName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 MHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 MMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 MP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 ATK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 DEF;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 LUCK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	int32 Gold;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterInfo")
	int32 XP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterInfo")
	int32 MXP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterInfo")
	int32 Lvl;

public:
	static UGameCharacter* CreateGameCharacter(FCharacterInfo *characterInfo, UObject *outer);

	static UGameCharacter* CreateGameCharacter(FEnemyInfo *enemyInfo, UObject *outer);

	UGameCharacter * SelectTarget();

	void BeginDestroy() override;

	void BeginMakeDecision();

	bool MakeDecision(float DeltaSeconds);

	void BeginExecuteAction();

	bool ExecuteAction(float DeltaSeconds);


	
};
