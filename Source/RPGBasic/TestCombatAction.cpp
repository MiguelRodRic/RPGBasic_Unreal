// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCombatAction.h"

TestCombatAction::TestCombatAction(UGameCharacter * target)
{
	this->target = target;
}

void TestCombatAction::BeginExecuteAction(UGameCharacter * character)
{
	this->character = character;

	//target is dead, select another target
	if (this->target->HP <= 0)
	{
		this->target = this->character->SelectTarget();
	}

	//no target, just return
	if (this->target == nullptr) {
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *target->CharacterName);

	target->HP -= 10;

	this->delayTimer = 1.0f;
}

bool TestCombatAction::ExecuteAction(float DeltaSeconds)
{
	this->delayTimer -= DeltaSeconds;
	return this->delayTimer <= 0.0f;
}
