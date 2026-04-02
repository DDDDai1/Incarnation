// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SoulCageCharacterBase.h"
#include "SoulCageHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class INCARNATION_API ASoulCageHeroCharacter : public ASoulCageCharacterBase
{
	GENERATED_BODY()

public:
	ASoulCageHeroCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//在角色被控制时就获取能力系统组件,并注册Actor
	//这里是在服务器端
	virtual void PossessedBy(AController* NewController) override;
	//那么这里就是在客户端
	virtual void OnRep_PlayerState() override;
	
private:
	UPROPERTY(VisibleAnywhere,Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere,Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
