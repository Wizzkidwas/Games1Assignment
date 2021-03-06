// Copyright Epic Games, Inc. All Rights Reserved.


#include "Games1AssignmentGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void AGames1AssignmentGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}

void AGames1AssignmentGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Started"));
}