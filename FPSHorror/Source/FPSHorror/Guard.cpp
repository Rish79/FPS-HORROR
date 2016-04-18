// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "FPSHorrorCharacter.h"
#include "DrawDebugHelpers.h"
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

void AGuard::OnAttack()
{
	FCollisionQueryParams Traceparam;
	FCollisionObjectQueryParams CollisionObjectParams;

	FVector Start = GetActorLocation();
	FVector AForward = GetActorForwardVector();
	FVector End = Start + AForward * range;
	
	FHitResult HitData(ForceInit);

	AGuard* myGuard = Cast<AGuard>(this);
	Traceparam.AddIgnoredActor(myGuard);

	GetWorld()->LineTraceSingle(HitData, Start, End, Traceparam, CollisionObjectParams);

	const FName TraceTag("MyTraceTag");

	GetWorld()->DebugDrawTraceTag = TraceTag;
	Traceparam.TraceTag = TraceTag;

	if (HitData.GetActor() != NULL)
	{
		AFPSHorrorCharacter* newChar = Cast<AFPSHorrorCharacter>(HitData.GetActor());
		if (newChar)
		{
			newChar->Health -= Damage;
		}
	}

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

