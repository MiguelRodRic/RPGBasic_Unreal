// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "RPGCameraComponent.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class RPGBASIC_API URPGCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraProperties)
	float CameraPitch;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraProperties)
	float CameraDistance;

	virtual void GetCameraView(float DeltaTime, FMinimalViewInfo &DesiredView) override;
};
