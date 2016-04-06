// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "FPSHorrorCharacter.h"
#include "MyHUD.h"
#include "NPCDialogue.h"


// Sets default values
ANPCDialogue::ANPCDialogue()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ApproachSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	ApproachSphere->AttachTo(RootComponent);
	ApproachSphere->SetSphereRadius(25.0f);
	// when it overlaps another actor
	ApproachSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPCDialogue::Prox);

	NPCmessage = "Hello good sir! Welcome to my bar, what'll it be tonight?";

}

// Called when the game starts or when spawned
void ANPCDialogue::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCDialogue::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ANPCDialogue::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ANPCDialogue::Prox_Implementation(AActor* otherActor, UPrimitiveComponent* 
	otherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<AFPSHorrorCharacter>(otherActor) == nullptr)
	{
		return;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(FMessage(NPCmessage, 5.0f, FColor::White));
	}
}

