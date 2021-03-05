// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "PlayerCharacter.h"
#include "ProjectileActor.h"
#include "CustomMovementComponent.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = Cast<APlayerCharacter>(GetPawn());

}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &ACustomPlayerController::CallForwards);
	InputComponent->BindAxis("MoveSideways", this, &ACustomPlayerController::CallSideways);
	InputComponent->BindAxis("Yaw", this, &ACustomPlayerController::CallYaw);
	InputComponent->BindAxis("Pitch", this, &ACustomPlayerController::CallPitch);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACustomPlayerController::CallFire);
}

void ACustomPlayerController::CallForwards(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->PlayerMovement->MoveForward(Value);
	}
}

void ACustomPlayerController::CallSideways(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->PlayerMovement->MoveSideways(Value);
	}
}


void ACustomPlayerController::CallYaw(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->PlayerMovement->Yaw(Value);
	}
}

void ACustomPlayerController::CallPitch(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->PlayerMovement->Pitch(Value);
	}
}

void ACustomPlayerController::CallFire()
{
	if (MyCharacter)
	{
		MyCharacter->PlayerMovement->Fire();
	}
}