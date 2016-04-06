// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "Guard.h"


// Sets default values
AGuard::AGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;

}

// Called when the game starts or when spawned
void AGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGuard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (Health <= 0)
	{
		this->Destroy();
	}
}

// Called to bind functionality to input
void AGuard::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

