// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */

USTRUCT()
struct FMessage
{
	GENERATED_BODY()

	FString message;
	float time;
	FColor color;

	FMessage()
	{
		// default time
		time = 5.f;
		color = FColor::Green;
	}

	FMessage(FString iMessage, float iTime, FColor iColor)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
	}
};

UCLASS()

class FPSHORROR_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	// font used to render
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
		UFont* hudFont;

	TArray<FMessage> messages;
	// method to draw hud
	virtual void DrawHUD() override;
	// method to add messages
	void addMessage(FMessage msg);
};
