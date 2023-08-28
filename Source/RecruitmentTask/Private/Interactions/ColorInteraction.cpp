// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/ColorInteraction.h"

#include "Agent.h"

UColorInteraction::UColorInteraction(): UInteractionBase()
{
	NewColor = FLinearColor::Black;
}

void UColorInteraction::InteractWithAgent(AAgent* Agent)
{
	if(Agent)
	{
		Agent->ChangeColor(NewColor);
	}
}
