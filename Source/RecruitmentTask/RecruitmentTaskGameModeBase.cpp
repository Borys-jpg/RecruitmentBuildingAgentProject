// Copyright Epic Games, Inc. All Rights Reserved.


#include "RecruitmentTaskGameModeBase.h"

#include "Agent.h"
#include "Blueprint/UserWidget.h"


void ARecruitmentTaskGameModeBase::AddBuilding(ABuilding* Building)
{
	if(Building)
	{
		Buildings.Add(Building);

		if(!BuildingAssignmentWidget && AssignmentWidgetClass )
		{
			BuildingAssignmentWidget = CreateWidget<UUserWidget>(GetWorld(),AssignmentWidgetClass);
			if(BuildingAssignmentWidget)
			{
				BuildingAssignmentWidget->AddToViewport();
			}
		}
		BuildingRegisteredDelegate.Broadcast(Building);
	}
}

void ARecruitmentTaskGameModeBase::PassAgentDestination(ABuilding* Building) const
{
	Agent->WalkToBuilding(Building);
}

void ARecruitmentTaskGameModeBase::SetAgent(AAgent* NewAgent)
{
	Agent = NewAgent;
}
