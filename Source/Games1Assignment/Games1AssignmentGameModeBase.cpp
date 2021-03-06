// Copyright Epic Games, Inc. All Rights Reserved.


#include "Games1AssignmentGameModeBase.h"

void AGames1AssignmentGameModeBase::PointScored()
{

}

void AGames1AssignmentGameModeBase::BeginPlay()
{
	StartGame();
}

void AGames1AssignmentGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Started"));
}

void AGames1AssignmentGameModeBase::GameOver(bool a)
{
	UE_LOG(LogTemp, Warning, TEXT("Game Ended"));
}

void AGames1AssignmentGameModeBase::LevelComplete()
{

}
