// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

class APlayerCharacter;
/**
 * 
 */
UCLASS()
class GAMES1ASSIGNMENT_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void SetupInputComponent();
	virtual void CallForwards(float Value);
	virtual void CallSideways(float Value);
	virtual void CallYaw(float Value);
	virtual void CallPitch(float Value);
	virtual void CallFire();
	APlayerCharacter* MyCharacter;

};
