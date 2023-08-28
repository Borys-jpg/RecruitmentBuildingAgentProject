// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBase.h"
#include "SoundInteraction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class USoundInteraction : public UInteractionBase
{
	GENERATED_BODY()

public:
	USoundInteraction();
	
	virtual void InteractWithAgent(AAgent* Agent) override;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundBase> SoundToPlay;
};
