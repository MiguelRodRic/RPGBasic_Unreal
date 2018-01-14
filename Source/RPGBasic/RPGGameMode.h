// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CombatEngine.h"
#include "RPGBasic.h"
#include "CombatUIWidget.h"
#include "RPGGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RPGBASIC_API ARPGGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ARPGGameMode(const class FObjectInitializer &ObjectInitializer);
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UFUNCTION(exec)
	void TestCombat();

public:
	CombatEngine * currentCombatInstance;
	TArray<UGameCharacter*> enemyParty;

	UPROPERTY()
	UCombatUIWidget* CombatUIInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UCombatUIWidget> CombatUIClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> GameOverUIClass;
};
