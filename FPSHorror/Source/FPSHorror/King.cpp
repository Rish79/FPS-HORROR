// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "King.h"




// Sets default values
AKing::AKing()
{
	//Super::AGuard();
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 600;

}

// Called every frame
void AKing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Health <= 0)
	{
		this->Destroy();
		UGameplayStatics::OpenLevel(this, FName(TEXT("MainMenu")));
	}
}

// Called to bind functionality to input
void AKing::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}