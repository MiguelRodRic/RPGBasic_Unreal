// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UGameCharacter;

/**
 * 
 */
class RPGBASIC_API IDecisionMaker
{
public:
	virtual void BeginMakeDecision(UGameCharacter * character) = 0;
	virtual bool MakeDecision(float DeltaSeconds) = 0;
};
