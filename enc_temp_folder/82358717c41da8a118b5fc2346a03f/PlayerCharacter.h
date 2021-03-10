// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h" 
#include "ProjectileActor.h"
#include "Games1AssignmentGameModeBase.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCustomMovementComponent;
class USceneComponent;
class AGames1AssignmentGameModeBase;

UCLASS()
class GAMES1ASSIGNMENT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* PlayerMovement;

	UPROPERTY(EditAnywhere)
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectileActor> ProjectileClass;

	UPROPERTY(EditAnywhere)
		AGames1AssignmentGameModeBase* GameModeRef;

	UPROPERTY(EditAnywhere)
		USoundBase* FireSound;

private:
	UFUNCTION()
		void CheckForNextLevel();

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		float PlayerHealth = 10.0f;

	int Points;
};
