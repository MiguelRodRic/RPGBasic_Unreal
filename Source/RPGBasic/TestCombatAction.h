// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ICombatAction.h"
#include "GameCharacter.h"
/**
 * 
 */
class RPGBASIC_API TestCombatAction : public ICombatAction
{
protected:
	float delayTimer;

	UGameCharacter* character;
	UGameCharacter* target;

public:
	TestCombatAction(UGameCharacter* target);

	virtual void BeginExecuteAction(UGameCharacter * character) override;

	virtual bool ExecuteAction(float DeltaSeconds) override;
};
