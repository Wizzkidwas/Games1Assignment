// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ShootAtPlayer.h"
#include "PlayerCharacter.h"
#include "EnemyAIController.h"
#include "CustomMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_ShootAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	APlayerCharacter* AIActor = Cast<APlayerCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("Shot"));
	AIActor->PlayerMovement->Fire();
	return EBTNodeResult::Succeeded;
}