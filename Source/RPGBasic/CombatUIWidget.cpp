// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatUIWidget.h"

void UCombatUIWidget::BeginMakeDecision(UGameCharacter* target)
{
	this->currentTarget = target;
	this->finishedDecision = false;

	ShowActionsPanel(target);
}

bool UCombatUIWidget::MakeDecision(float DeltaSeconds)
{
	return this->finishedDecision;
}

TArray<UGameCharacter*> UCombatUIWidget::GetCharacterTargets()
{
	if (this->currentTarget->isPlayer)
	{
		return this->currentTarget->combatInstance->EnemyParty;
	}
	else 
	{
		return this->currentTarget->combatInstance->PlayerParty;
	}
}

void UCombatUIWidget::AttackTarget(UGameCharacter * target)
{
	TestCombatAction* action = new TestCombatAction(target);
	this->currentTarget->combatAction = action;

	this->finishedDecision = true;
}



