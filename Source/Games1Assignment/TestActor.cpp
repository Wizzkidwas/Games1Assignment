// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	TestMesh->SetupAttachment(RootComponent);
	TestMesh->SetSimulatePhysics(true);
	TestMesh->SetNotifyRigidBodyCollision(true);
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(TestMesh);
	CollisionBox->SetCollisionProfileName("Trigger");
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATestActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATestActor::OnOverlapEnd);
	GameModeRef = Cast<AGames1AssignmentGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

float ATestActor::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage Taken"));
	ActorHealth -= DamageAmount;
	if (ActorHealth <= 0)
	{
		Destroy();
	}
	return DamageAmount;
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap begin"));
	GameModeRef->PointScored();
}

void ATestActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap end"));
}