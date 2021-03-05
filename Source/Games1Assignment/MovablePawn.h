// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h" 
#include "ProjectileActor.h"
#include "MovablePawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCustomMovementComponent;
class USceneComponent;

UCLASS()
class GAMES1ASSIGNMENT_API AMovablePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovablePawn();
	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* PawnMovement;

	UPROPERTY(EditAnywhere)
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectileActor> ProjectileClass;

private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* PawnMesh;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
};
