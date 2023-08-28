// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBase.h"
#include "ColorInteraction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UColorInteraction : public UInteractionBase
{
	GENERATED_BODY()

public:
	UColorInteraction();
	
	virtual void InteractWithAgent(AAgent* Agent) override;

private:
	UPROPERTY(EditDefaultsOnly)
	FLinearColor NewColor;
};
