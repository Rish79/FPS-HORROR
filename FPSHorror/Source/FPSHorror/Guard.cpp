// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "FPSHorrorCharacter.h"
#include "FPSHorrorProjectile.h"
#include "DrawDebugHelpers.h"
#include "Guard.h"


// Sets default values
AGuard::AGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;

	//Start = FVector(GetActorLocation().X, GetActorLocation().Y - 100, GetActorLocation().Z);

	//Start = GetActorLocation();
	////for the king //FVector Start =  FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 100);
	//AForward = GetActorForwardVector();
	//End = Start + AForward * range;
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
	////for the king //FVector Start =  FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 100);
	FVector AForward = GetActorForwardVector();
	FVector End = Start + AForward * range;

	
	FHitResult HitData(ForceInit);

	AGuard* myGuard = Cast<AGuard>(this);
	Traceparam.AddIgnoredActor(myGuard);

	GetWorld()->LineTraceSingle(HitData, Start, End, Traceparam, CollisionObjectParams);

	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 1);

	const FName TraceTag("MyTraceTag");

	GetWorld()->DebugDrawTraceTag = TraceTag;

	FCollisionQueryParams CollisionParams;

	CollisionParams.TraceTag = TraceTag;
	
	//Traceparam.TraceTag = TraceTag;

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

void AGuard::OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//AFPSHorrorProjectile* newGuard = Cast<AFPSHorrorProjectile>(OtherActor);
	//if (newGuard)
	//{
	//	newGuard->Health -= 30;
	//	GEngine->AddOnScreenDebugMessage(8, 2, FColor::Yellow, FString::FromInt(newGuard->Health));
	//	this->Destroy();
	//}
}

