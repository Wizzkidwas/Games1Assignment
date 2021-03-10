// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UBlackboardComponent;


UCLASS()
class GAMES1ASSIGNMENT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
	AActor* ChooseWaypoint();
	void RandomPatrol();
	bool IsInFront(AActor* ActorToCheck);

	UPROPERTY()
		TArray<AActor*> Waypoints;
	
	UPROPERTY(EditAnywhere)
		UBehaviorTree* AIBehaviourTree;
};
