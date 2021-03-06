// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UCustomMovementComponent::UCustomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCustomMovementComponent::MoveForward(float AxisX)
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(GetOwner());
	Character->AddMovementInput(Character->GetActorForwardVector() * AxisX * MoveSpeed);
}

void UCustomMovementComponent::MoveSideways(float AxisX)
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(GetOwner());
	Character->AddMovementInput(Character->GetActorRightVector() * AxisX * MoveSpeed);
}

void UCustomMovementComponent::Yaw(float AxisZ)
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(GetOwner());
	Character->AddControllerYawInput(AxisZ);
}

void UCustomMovementComponent::Pitch(float AxisY)
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(GetOwner());
	Character->AddControllerPitchInput(AxisY);
}

void UCustomMovementComponent::Fire()
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(GetOwner());
	FVector SpawnLocation = Character->ProjectileSpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = Character->ProjectileSpawnPoint->GetComponentRotation();
	AProjectileActor* TempProjectile = GetWorld()->SpawnActor<AProjectileActor>(Character->ProjectileClass, SpawnLocation, SpawnRotation);
	TempProjectile->SetOwner(Character);
}