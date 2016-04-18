// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "Engine.h"
#include "FPSHorrorCharacter.h"
#include "DrawDebugHelpers.h"
#include "King.h"




// Sets default values
AKing::AKing()
{
	//Super::AGuard();
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 600;

}

void AKing::BeginPlay()
{
	Super::BeginPlay();

}


void AKing::OnAttack()
{
	GEngine->AddOnScreenDebugMessage(5, 3, FColor::Green, FString::FromInt(Damage));

	FCollisionQueryParams Traceparam;
	FCollisionObjectQueryParams CollisionObjectParams;

	//FVector Start = GetActorLocation();

	////for the king 
	FVector Start =  FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 150);
	FVector AForward = GetActorForwardVector();
	FVector End = Start + AForward * range;


	FHitResult HitData(ForceInit);

	AGuard* myGuard = Cast<AGuard>(this);
	Traceparam.AddIgnoredActor(myGuard);

	GetWorld()->LineTraceSingle(HitData, Start, End, Traceparam, CollisionObjectParams);

	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 1);

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