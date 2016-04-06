// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "FPSHorror.h"
#include "FPSHorrorGameMode.h"
#include "FPSHorrorHUD.h"
#include "FPSHorrorCharacter.h"

AFPSHorrorGameMode::AFPSHorrorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHorrorHUD::StaticClass();
}
