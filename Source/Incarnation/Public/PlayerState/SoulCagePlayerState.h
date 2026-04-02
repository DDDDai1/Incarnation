// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "SoulCagePlayerState.generated.h"

class UAbilitySystemComponent;

UCLASS()
class INCARNATION_API ASoulCagePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ASoulCagePlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:
	UPROPERTY(VisibleAnywhere,Category = "SoulCage|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
