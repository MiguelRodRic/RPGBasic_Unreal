// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCharacter.h"
#include "CombatEngine.h"

UGameCharacter * UGameCharacter::CreateGameCharacter(FCharacterInfo * characterInfo, UObject * outer)
{
	UGameCharacter * character = NewObject<UGameCharacter>(outer);
	//character->decisionMaker = new TestDecisionMaker();
	//locate character classes asset
	UDataTable * characterClasses = Cast<UDataTable>(
		StaticLoadObject(UDataTable::StaticClass(), NULL, 
		TEXT("DataTable'/Game/DataTables/CharacterClasses.CharacterClasses'")));

	if (characterClasses == NULL) {
		UE_LOG(LogTemp, Error, TEXT("Character classes datatable not found!"));
	}
	else {
		character->CharacterName = characterInfo->Character_Name;
		FCharacterClassInfo* row = characterClasses->FindRow<FCharacterClassInfo>(*(characterInfo->Class_ID), TEXT("LookupCharacterClass"));
		character->ClassInfo = row;

		character->MHP = character->ClassInfo->StartMHP;
		character->MMP = character->ClassInfo->StartMMP;
		character->HP = character->MHP;
		character->MP = character->MMP;

		character->ATK = character->ClassInfo->StartATK;
		character->DEF = character->ClassInfo->StartDEF;
		character->LUCK = character->ClassInfo->StartLuck;

		character->XP = character->ClassInfo->XP;
		character->MXP = character->ClassInfo->MXP;
		character->Lvl = character->ClassInfo->Lvl;

		character->isPlayer = true;
	}
	
	return character;
}

UGameCharacter * UGameCharacter::CreateGameCharacter(FEnemyInfo * enemyInfo, UObject * outer)
{
	UGameCharacter * character = NewObject<UGameCharacter>(outer);
	character->decisionMaker = new TestDecisionMaker();
	character->CharacterName = enemyInfo->EnemyName;
	character->ClassInfo = nullptr;

	character->MHP = enemyInfo->MHP;
	character->MMP = 0;
	character->HP = enemyInfo->MHP;
	character->MP = 0;

	character->ATK = enemyInfo->ATK;
	character->DEF = enemyInfo->DEF;
	character->LUCK = enemyInfo->Luck;
	character->Gold = enemyInfo->Gold;
	character->XP = enemyInfo->XP;
	
	character->isPlayer = false;

	return character;
}

UGameCharacter * UGameCharacter::SelectTarget()
{
	UGameCharacter * target = nullptr;
	TArray<UGameCharacter*> targetList = this->combatInstance->EnemyParty;
	if (!this->isPlayer) {
		targetList = this->combatInstance->PlayerParty;
	}

	for (int i = 0; i < targetList.Num(); ++i) {
		if (targetList[i]->HP > 0) {
			target = targetList[i];
			break;
		}
	}

	if (target->HP <= 0) {
		return nullptr;
	}
	return target;
}

void UGameCharacter::BeginDestroy()
{
	Super::BeginDestroy();
	if (!this->isPlayer) {
		delete(this->decisionMaker);
	}
}

void UGameCharacter::BeginMakeDecision()
{
	this->decisionMaker->BeginMakeDecision(this);
}

bool UGameCharacter::MakeDecision(float DeltaSeconds)
{
	return this->decisionMaker->MakeDecision(DeltaSeconds);
}

void UGameCharacter::BeginExecuteAction()
{
	this->combatAction->BeginExecuteAction(this);
}

bool UGameCharacter::ExecuteAction(float DeltaSeconds)
{
	bool finishedAction = this->combatAction->ExecuteAction(DeltaSeconds);
	if (finishedAction) {
		delete(this->combatAction);
		return true;
	}
	return false;
}
