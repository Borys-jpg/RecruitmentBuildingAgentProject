// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Agent.generated.h"


class UCapsuleComponent;
class ABuilding;

UENUM()
enum class EAgentStatus  : uint8
{
	Walking,
	ResolvingInteractions,
};

UCLASS()
class AAgent : public ACharacter
{
	GENERATED_BODY()

public:
	AAgent();

	virtual void Tick(float DeltaTime) override;
	
	void WalkToBuilding(ABuilding* Building);

	void StartJumping(const float JumpFrequency);
	
	void ChangeColor(const FLinearColor NewColor) const;

	void PlaySoundBase(USoundBase* SoundToPlay) const;

protected:
	virtual void BeginPlay() override;

private:	
	UPROPERTY()
	TObjectPtr<ABuilding> AssignedBuilding;
	
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float WalkingSpeed;

	UPROPERTY()
	TObjectPtr<UAudioComponent>  AudioComponent;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MIDynamic;
	
	EAgentStatus AgentStatus;

	FTimerHandle JumpTimerHandle;
	
	UFUNCTION()
	void OnCapsuleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	void PerformJump();
	
};
