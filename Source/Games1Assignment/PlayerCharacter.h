// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h" 
#include "ProjectileActor.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCustomMovementComponent;
class USceneComponent;

UCLASS()
class GAMES1ASSIGNMENT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* PlayerMovement;

	UPROPERTY(EditAnywhere)
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectileActor> ProjectileClass;

private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
};
