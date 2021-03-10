// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "CustomMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Player Mesh"));
	CharacterMesh->SetupAttachment(RootComponent);
	CharacterMesh->SetNotifyRigidBodyCollision(true);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(CharacterMesh);
	SpringArm->SetRelativeLocationAndRotation(FVector(-400.0f, 0.0f, 350.0f), FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bEnableCameraLag = false;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	PlayerMovement = CreateDefaultSubobject<UCustomMovementComponent>(TEXT("Player Movement"));
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(CharacterMesh);
	GameModeRef = Cast<AGames1AssignmentGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	Points = 0;
}

float APlayerCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) 
{
	PlayerHealth -= DamageAmount;
	if (PlayerHealth <= 0)
	{
		Destroy();
		Points += 1;
		CheckForNextLevel();
	}
	return DamageAmount;
}

void APlayerCharacter::CheckForNextLevel()
{
	GameModeRef->LevelComplete(Points);
}