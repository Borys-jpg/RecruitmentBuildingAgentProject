// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"

#include "Interactions/InteractionBase.h"
#include "Kismet/GameplayStatics.h"
#include "RecruitmentTask/RecruitmentTaskGameModeBase.h"

// Sets default values
ABuilding::ABuilding()
{
	CubePrimitive = CreateDefaultSubobject<UStaticMeshComponent>("BuildingPrimitive");
	RootComponent = CubePrimitive;
	
	CubePrimitive->SetNotifyRigidBodyCollision(true);
	CubePrimitive->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CubePrimitive->SetCollisionObjectType(ECC_EngineTraceChannel1);
	CubePrimitive->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Block);

	PossibleInteractions.Empty();
}

void ABuilding::ResolveInteractions(AAgent* Agent)
{
	if(Agent)
	{
		for (UInteractionBase* Interaction : PossibleInteractions)
		{
			if(Interaction)
			{
				Interaction->InteractWithAgent(Agent);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Interaction is nullptr"));
			}
		}
	}
}

void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
	if (const UWorld* World = GetWorld())
	{
		if (ARecruitmentTaskGameModeBase* GameMode = Cast<ARecruitmentTaskGameModeBase>(UGameplayStatics::GetGameMode(World)))
		{
			GameMode->AddBuilding(this);
		}
	}
	for (const TSubclassOf<UInteractionBase>& ClassInteraction : InteractionsClassSet)
	{
		//PossibleInteractions.Add(NewObject<UInteractionBase>(this,ClassInteraction));
		PossibleInteractions.Add(Cast<UInteractionBase>(ClassInteraction->ClassDefaultObject));
	}
}

