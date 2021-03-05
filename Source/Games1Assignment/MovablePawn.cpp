// Fill out your copyright notice in the Description page of Project Settings.


#include "MovablePawn.h"
#include "CustomMovementComponent.h"

// Sets default values
AMovablePawn::AMovablePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PawnMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Player Mesh"));
	PawnMesh->SetupAttachment(RootComponent);
	PawnMesh->SetNotifyRigidBodyCollision(true);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(PawnMesh);
	SpringArm->SetRelativeLocationAndRotation(FVector(-400.0f, 0.0f, 350.0f), FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bEnableCameraLag = false;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	PawnMovement = CreateDefaultSubobject<UCustomMovementComponent>(TEXT("Pawn Movement"));
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(PawnMesh);
}
