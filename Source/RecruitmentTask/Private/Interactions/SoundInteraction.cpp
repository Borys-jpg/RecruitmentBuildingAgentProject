// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/SoundInteraction.h"
#include "Agent.h"

USoundInteraction::USoundInteraction(): UInteractionBase()
{
	SoundToPlay = nullptr;
}

void USoundInteraction::InteractWithAgent(AAgent* Agent)
{
	if (SoundToPlay && Agent)
	{
		Agent->PlaySoundBase(SoundToPlay);
	}
}
