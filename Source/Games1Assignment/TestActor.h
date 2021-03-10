// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Games1AssignmentGameModeBase.h"
#include "TestActor.generated.h"

class UBoxComponent;
class AGames1AssignmentGameModeBase;

UCLASS()
class GAMES1ASSIGNMENT_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TestMesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* CollisionBox;

	UPROPERTY()
		AGames1AssignmentGameModeBase* GameModeRef;

	UPROPERTY(EditAnywhere)
		float ActorHealth = 10.0f;

};
