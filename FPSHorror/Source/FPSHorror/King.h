// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Guard.h"
#include "King.generated.h"

/**
 * 
 */
UCLASS()
class FPSHORROR_API AKing : public AGuard
{
	GENERATED_BODY()
	
	
	// Sets default values for this character's properties
	AKing();
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


};
