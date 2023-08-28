// Fill out your copyright notice in the Description page of Project Settings.


#include "Agent.h"

#include "Building.h"
#include "Components/AudioComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RecruitmentTask/RecruitmentTaskGameModeBase.h"

AAgent::AAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetCapsuleComponent()->SetNotifyRigidBodyCollision(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetCapsuleComponent()->SetCollisionObjectType(ECC_EngineTraceChannel1);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Overlap);
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AAgent::OnCapsuleHit);
	
	AudioComponent = CreateDefaultSubobject<UAudioComponent>("AudioComponent");
	
	AssignedBuilding = nullptr;
	AgentStatus = EAgentStatus::Walking;
	WalkingSpeed = 100.f;
}

void AAgent::BeginPlay()
{
	Super::BeginPlay();

	MIDynamic = GetMesh()->CreateAndSetMaterialInstanceDynamic(0);
	
	if (const UWorld* World = GetWorld())
	{
		if (ARecruitmentTaskGameModeBase* GameMode = Cast<ARecruitmentTaskGameModeBase>(UGameplayStatics::GetGameMode(World)))
		{
			GameMode->SetAgent(this);
		}
	}
}

void AAgent::OnCapsuleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor && OtherActor == AssignedBuilding)
	{
		AssignedBuilding->ResolveInteractions(this);
		AgentStatus = EAgentStatus::ResolvingInteractions;
	}
}

void AAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AgentStatus == EAgentStatus::Walking && AssignedBuilding)
	{
		SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(),AssignedBuilding->GetActorLocation(),DeltaTime, WalkingSpeed),true);
	}
}

void AAgent::WalkToBuilding(ABuilding* Building)
{
	if(AssignedBuilding != Building)
	{
		AssignedBuilding = Building;
		AgentStatus = EAgentStatus::Walking;

		if(AudioComponent)
		{
			AudioComponent->Stop();
		}
		if(JumpTimerHandle.IsValid())
		{
			GetWorld()->GetTimerManager().ClearTimer(JumpTimerHandle);
		}
	}
}

void AAgent::StartJumping(const float JumpFrequency)
{
	GetWorld()->GetTimerManager().SetTimer(JumpTimerHandle, this, &AAgent::PerformJump, JumpFrequency, true);
}

void AAgent::PerformJump()
{
	if(AgentStatus == EAgentStatus::ResolvingInteractions)
	{
		Jump();
	}
}

void AAgent::ChangeColor(const FLinearColor NewColor) const
{
	if(MIDynamic)
	{
		MIDynamic->SetVectorParameterValue("ColorParameter", NewColor);
	}
}
	
void AAgent::PlaySoundBase(USoundBase* SoundToPlay) const
{
	if (SoundToPlay && AudioComponent)
	{
		AudioComponent->SetSound(SoundToPlay);
		AudioComponent->Play();
	}
}

