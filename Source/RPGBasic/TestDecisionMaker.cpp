// Fill out your copyright notice in the Description page of Project Settings.

#include "TestDecisionMaker.h"
#include "TestCombatAction.h"

void TestDecisionMaker::BeginMakeDecision(UGameCharacter * character)
{
	//pick a target
	UGameCharacter* target = character->SelectTarget();
	character->combatAction = new TestCombatAction(target);
}

bool TestDecisionMaker::MakeDecision(float DeltaSeconds)
{
	return true;
}
