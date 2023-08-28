// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Agent.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

class UBoxComponent;
class UInteractionBase;

UCLASS()
class ABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	ABuilding();

	void ResolveInteractions(AAgent* Agent);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> CubePrimitive;
	
	UPROPERTY(EditInstanceOnly, Category = "Interaction")
	TSet<TSubclassOf<UInteractionBase>> InteractionsClassSet;

	UPROPERTY()
	TArray<TObjectPtr<UInteractionBase>> PossibleInteractions;
};



