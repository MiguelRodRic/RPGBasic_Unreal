// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UGameCharacter;

class RPGBASIC_API ICombatAction
{
public:

	virtual void BeginExecuteAction(UGameCharacter * character) = 0;

	virtual bool ExecuteAction(float DeltaSeconds) = 0;
};