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
	
public:
	UFUNCTION()
		void PointScored();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void StartGame();

	UFUNCTION()
		void GameOver(bool a);

	UFUNCTION()
		void LevelComplete();
};
