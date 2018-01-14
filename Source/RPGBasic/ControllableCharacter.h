// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "UObject/Interface.h"
#include "ControllableCharacter.generated.h"

UINTERFACE()
class RPGBASIC_API UControllableCharacter : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class RPGBASIC_API IControllableCharacter
{
	GENERATED_IINTERFACE_BODY()

	virtual void MoveVertical(float Value);
	virtual void MoveHorizontal(float Value);
};