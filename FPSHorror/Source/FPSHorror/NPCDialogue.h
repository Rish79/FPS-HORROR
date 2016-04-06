// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "NPCDialogue.generated.h"



UCLASS()
class FPSHORROR_API ANPCDialogue : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCDialogue();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		class USphereComponent* ApproachSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessages)
		FString NPCmessage;

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(AActor* otherActor, UPrimitiveComponent* otherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
