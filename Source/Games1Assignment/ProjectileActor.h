// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileActor.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class GAMES1ASSIGNMENT_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
		float MovementSpeed = 1000.0f;

	UPROPERTY(EditAnywhere)
		float ProjectileDamage = 10.0f;

};
