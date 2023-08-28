// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/UJumpInteraction.h"
#include "Agent.h"

UJumpInteraction::UJumpInteraction(): UInteractionBase()
{
	JumpFrequency = 2.f;
}

void UJumpInteraction::InteractWithAgent(AAgent* Agent)
{
	if(Agent && JumpFrequency > 0)
	{
		Agent->StartJumping(JumpFrequency);
	}
}

