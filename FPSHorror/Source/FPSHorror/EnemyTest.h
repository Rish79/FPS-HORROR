// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "EnemyTest.generated.h"

UCLASS()
class FPSHORROR_API AEnemyTest : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyTest();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
protected:
	//collider to detect player
	UPROPERTY(EditAnywhere)
		USphereComponent* DetectionCollider;

	//collider for the character
	UPROPERTY(EditAnywhere)
		UCapsuleComponent* Collider;

	UPROPERTY(EditAnywhere)
		float DetectionRadius = 45.0f;

	UPROPERTY(EditAnywhere)
		float ColliderHalfHeight = 25.0f;

	UPROPERTY(EditAnywhere)
		float ColliderRadius = 10.0f;

protected:
	void DetectPlayer(AActor* OtherActor);

	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
