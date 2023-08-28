// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractionBase.generated.h"

class AAgent;
/**
 * 
 */
UCLASS(Abstract)
class UInteractionBase : public UObject
{
	GENERATED_BODY()
	
public:
	UInteractionBase();
	
	virtual void InteractWithAgent(AAgent* Agent) PURE_VIRTUAL(UInteractionBase::InteractWithAgent, )
	
};
