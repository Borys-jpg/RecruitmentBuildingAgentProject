// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBase.h"
#include "Ujumpinteraction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UJumpInteraction : public UInteractionBase
{
	GENERATED_BODY()

public:
	UJumpInteraction();
	virtual void InteractWithAgent(AAgent* Agent) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	float JumpFrequency; 
};
