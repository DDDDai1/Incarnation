// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SoulCageCharacterBase.generated.h"

//添加后无法在编辑器被实例化
UCLASS(Abstract)
class INCARNATION_API ASoulCageCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASoulCageCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
