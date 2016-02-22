// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "EnemyTest.h"
#include "FPSHorrorCharacter.h"
#include "Engine.h"


// Sets default values
AEnemyTest::AEnemyTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
	
	DetectionCollider = CreateAbstractDefaultSubobject<USphereComponent>(TEXT("Detection Collider"));
	DetectionCollider->SetSphereRadius(DetectionRadius);
	DetectionCollider->AttachTo(RootComponent);

//	FComponentBeginOverlapSignature* OnComponentBeginOverlap = Cast<FComponentBeginOverlapSignature>(DetectionCollider);

	
	//DetectionCollider->BeginComponentOverlap.execDynArrayAdd(this, &AEnemyTest::OnBeginOverlap);

	DetectionCollider->OnComponentBeginOverlap.AddDynamic(this, &AEnemyTest::OnBeginOverlap);


	//Collider = CreateAbstractDefaultSubobject<UCapsuleComponent>(TEXT("COllider"));
	//Collider->SetCapsuleHalfHeight(ColliderHalfHeight);
	//Collider->SetCapsuleRadius(ColliderRadius);


}

// Called when the game starts or when spawned
void AEnemyTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyTest::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AEnemyTest::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AEnemyTest::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	DetectPlayer(OtherActor);
	const FString Message = "PlayerWalked In";
	GEngine->AddOnScreenDebugMessage(3, 2, FColor::Green, Message);
}

void AEnemyTest::DetectPlayer(AActor* OtherActor)
{
	AFPSHorrorCharacter* PlayerCharacter = Cast<AFPSHorrorCharacter>(OtherActor);
	if(PlayerCharacter)
	{
		const FString Message = "DetectedPlayer";
		GEngine->AddOnScreenDebugMessage(2, 2, FColor::Green, Message);

		if (PlayerCharacter->Health <= 85)
		{
			const FString Message = "Player is Noticable";
			GEngine->AddOnScreenDebugMessage(2, 2, FColor::Green, Message);
			return;
		}

	}
}


