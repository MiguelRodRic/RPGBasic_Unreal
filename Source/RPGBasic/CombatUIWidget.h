// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameCharacter.h"
#include "Blueprint/UserWidget.h"
#include "CombatEngine.h"
#include "CombatUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class RPGBASIC_API UCombatUIWidget : public UUserWidget, public IDecisionMaker
{
	GENERATED_BODY()
	
public:
	void BeginMakeDecision(UGameCharacter* target);

	bool MakeDecision(float DeltaSeconds);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
	void AddPlayerCharacterPanel(UGameCharacter * target);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
	void AddEnemyCharacterPanel(UGameCharacter * target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
	void ShowActionsPanel(UGameCharacter* target);

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
	TArray<UGameCharacter*> GetCharacterTargets();

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
	void AttackTarget(UGameCharacter* target);

protected:
	bool finishedDecision;

public:
	UGameCharacter* currentTarget;
};
