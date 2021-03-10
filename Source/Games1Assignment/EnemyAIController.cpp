// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);
	if (AIBehaviourTree != nullptr)
	{
		RunBehaviorTree(AIBehaviourTree); // Protects against engine crashes with unassigned behaviour trees
	}
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation()); // Keeps the location the AI spawned at
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (LineOfSightTo(PlayerPawn))
	{
		if (IsInFront(PlayerPawn))
		{
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerPosition"), PlayerPawn->GetActorLocation());
		}
	}
}


void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	GetBlackboardComponent()->ClearValue(TEXT("PlayerPosition"));
	RandomPatrol();
}

AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Waypoints[index];
}

void AEnemyAIController::RandomPatrol()
{
	AActor* ChosenActor = ChooseWaypoint();
	GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolLocation"), ChosenActor->GetActorLocation());
}

bool AEnemyAIController::IsInFront(AActor* ActorToCheck)
{
	APawn* AIPawn = GetPawn();
	FVector AIForwardVector = AIPawn->GetActorForwardVector(); // This vector is already nomalised
	FVector ActorPositionVector = ActorToCheck->GetActorLocation();
	FVector AIPositionVector = AIPawn->GetActorLocation();
	FVector AIToActorVector = ActorPositionVector - AIPositionVector;
	AIToActorVector.Normalize(); // This vector must be explicitly normalised
	float DirectionDotProduct = FVector::DotProduct(AIToActorVector, AIForwardVector);
	if (DirectionDotProduct < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}