// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameCharacter.h"

enum class CombatPhase : uint8
{
	CPHASE_Decision,
	CPHASE_Action,
	CPHASE_Victory,
	CPHASE_GameOver,
};

/**
 * 
 */
class RPGBASIC_API CombatEngine
{
public:
	TArray<UGameCharacter*> combatantOrder;
	TArray<UGameCharacter*> PlayerParty;
	TArray<UGameCharacter*> EnemyParty;

	CombatPhase phase;

	bool waitingForCharacter;

	int32 GoldTotal;

protected:
	UGameCharacter * currentTickTarget;
	int tickTargetIndex;

public:
	CombatEngine(TArray<UGameCharacter*> playerParty, TArray<UGameCharacter*> EnemyParty);
	~CombatEngine();


	bool Tick(float DeltaSeconds);

protected:
	void SetPhase(CombatPhase phase);
	void SelectNextCharacter();
};
