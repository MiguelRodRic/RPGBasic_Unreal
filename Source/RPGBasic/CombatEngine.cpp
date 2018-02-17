// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatEngine.h"

#include "GameCharacter.h"

CombatEngine::CombatEngine(TArray<UGameCharacter*> playerParty, TArray<UGameCharacter*> EnemyParty)
{
	this->PlayerParty = playerParty;
	this->EnemyParty = EnemyParty;

	//first add all player to combat order
	for (int i = 0; i < playerParty.Num(); ++i) {
		this->combatantOrder.Add(playerParty[i]);
	}
	for (int i = 0; i < EnemyParty.Num(); ++i) {
		this->combatantOrder.Add(EnemyParty[i]);
	}


	for (int i = 0; i < this->combatantOrder.Num(); ++i) {
		this->combatantOrder[i]->combatInstance = this;
	}

	this->tickTargetIndex = 0;
	this->SetPhase(CombatPhase::CPHASE_Decision);
}

CombatEngine::~CombatEngine()
{
	//free enemies 
	for (int i = 0; i < this->EnemyParty.Num(); ++i) {
		this->EnemyParty[i] = nullptr;
	}
	for (int i = 0; i < this->combatantOrder.Num(); ++i) {
		this->combatantOrder[i]->combatInstance = nullptr;
	}
}

bool CombatEngine::Tick(float DeltaSeconds)
{
	switch (phase) {

	case CombatPhase::CPHASE_Decision:
	{		
		
		if (!this->waitingForCharacter) {
			this->currentTickTarget->BeginMakeDecision();
			this->waitingForCharacter = true;
		}

		bool decisionMade = this->currentTickTarget->MakeDecision(DeltaSeconds);

		if (decisionMade) {

			SelectNextCharacter();

			//no next character, switch to action phase
			if (this->tickTargetIndex == -1) {
				this->SetPhase(CombatPhase::CPHASE_Action);
			}
		}
	}
	break;

	case CombatPhase::CPHASE_Action:
	{
		
		if (!this->waitingForCharacter) {
			this->currentTickTarget->BeginExecuteAction();
			this->waitingForCharacter = true;
		}

		bool actionFinished = this->currentTickTarget->ExecuteAction(DeltaSeconds);
		
		if (actionFinished)
		{
			SelectNextCharacter();

			//no next character, go back to decision phase
			if (this->tickTargetIndex == -1) {
				this->SetPhase(CombatPhase::CPHASE_Decision);
			}
		}
	}
	break;

	case CombatPhase::CPHASE_GameOver:
	case CombatPhase::CPHASE_Victory:
		return true;
		break;
	}

	//check for game over
	int deadCount = 0;
	for (int i = 0; i < this->PlayerParty.Num(); ++i){
		if (this->PlayerParty[i]->HP <= 0) {
			++deadCount;
		}
	}

	if (deadCount == this->PlayerParty.Num()) {
		this->SetPhase(CombatPhase::CPHASE_GameOver);
		return false;
	}


	int32 Gold = 0;

	//check for victory
	deadCount = 0;
	for (int i = 0; i < this->EnemyParty.Num(); ++i) {
		if (this->EnemyParty[i]->HP <= 0) {
			++deadCount;
		}
		Gold += this->EnemyParty[i]->Gold;
	}

	if (deadCount == this->EnemyParty.Num()) {
		this->SetPhase(CombatPhase::CPHASE_Victory);
		GoldTotal = Gold;
		return false;
	}

	//if it gets here, combat is still going
	return false;
}

void CombatEngine::SetPhase(CombatPhase phase)
{
	this->phase = phase;

	switch (phase) {
	case CombatPhase::CPHASE_Action:
	case CombatPhase::CPHASE_Decision:
		//Set the active target to the first character in the combat order
		this->tickTargetIndex = 0;
		this->SelectNextCharacter();
		break;
	case CombatPhase::CPHASE_Victory:
		//TODO: handle victory
		break;
	case CombatPhase::CPHASE_GameOver:
		//TODO: handle game over
		break;
	}
}

void CombatEngine::SelectNextCharacter()
{
	this->waitingForCharacter = false;
	for (int i = this->tickTargetIndex; i < this->combatantOrder.Num(); ++i) {
		UGameCharacter * character = this->combatantOrder[i];

		if (character->HP > 0) {
			this->tickTargetIndex = i + 1;
			this->currentTickTarget = character;
			return;
		}
	}

	this->tickTargetIndex = -1;
	this->currentTickTarget = nullptr;
	return;

	
}
