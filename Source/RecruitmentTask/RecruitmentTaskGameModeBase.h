// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RecruitmentTaskGameModeBase.generated.h"


class AAgent;
class ABuilding;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBuildingRegisteredDelegate, ABuilding*, BuildingParam);
/**
 * 
 */
UCLASS()
class RECRUITMENTTASK_API ARecruitmentTaskGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	void AddBuilding(ABuilding* Building);

	void SetAgent(AAgent* NewAgent);
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void PassAgentDestination(ABuilding* Building) const;
	
	UPROPERTY(BlueprintAssignable, Category = "Delegate")
	FBuildingRegisteredDelegate BuildingRegisteredDelegate;

private:
	UPROPERTY()
	TObjectPtr<AAgent> Agent;

	UPROPERTY()
	TArray<TObjectPtr<ABuilding>> Buildings;

	UPROPERTY()
	TObjectPtr<UUserWidget> BuildingAssignmentWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> AssignmentWidgetClass;
};
