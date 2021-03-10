// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Games1AssignmentGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMES1ASSIGNMENT_API AGames1AssignmentGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void StartGame();

public:
	UFUNCTION()
		void LevelComplete(int PointsScored);
};
