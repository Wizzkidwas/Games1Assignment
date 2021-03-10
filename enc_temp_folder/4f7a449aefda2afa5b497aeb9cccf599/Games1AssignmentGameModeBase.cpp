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

void AGames1AssignmentGameModeBase::LevelComplete(int PointsScored)
{
	if (PointsScored == 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Changing to Level 2"));
		UGameplayStatics::OpenLevel(GetWorld(), "Level_2");
	}
	return;
	if (PointsScored == 3)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "Level_3");
	}
}