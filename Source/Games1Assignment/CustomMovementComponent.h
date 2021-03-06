// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMES1ASSIGNMENT_API UCustomMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCustomMovementComponent();
	void MoveForward(float AxisValue);
	void MoveSideways(float AxisValue);
	void Yaw(float AxisValue);
	void Pitch(float AxisValue);
	void Fire();
private:
	UPROPERTY(EditAnywhere)
		float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere)
		float RotationSpeed = 500.0f;
};
