// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPGBASIC_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
protected:
	void MoveVertical(float Value);

	void MoveHorizontal(float Value);
	
	virtual void SetupInputComponent() override;
	
};
