// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHorror.h"
#include "MyHUD.h"

void AMyHUD::DrawHUD()
{
	// call superclass draw method
	Super::DrawHUD();

	//TESTING our draw functions
	//DrawLine(200, 300, 400, 500, FLinearColor::Green);
	//// draw text now
	//DrawText("MY HUD", FVector2D(0, 0), hudFont, FVector2D(1, 1), FColor::Black);

	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		float outputWidth, outputHeight, pad = 10.0f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.0f);

		float messageHeight = outputHeight + 2.0f * pad;
		float x = 0.0f, y = c * messageHeight;

		//DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageHeight);
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);

		// reduce lifetime
		messages[c].time -= GetWorld()->GetDeltaSeconds();

		// if times up remove message
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}

void AMyHUD::addMessage(FMessage msg)
{
	messages.Add(msg);
}


