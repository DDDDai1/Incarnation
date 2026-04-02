// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SoulCageCharacterBase.h"

// Sets default values
ASoulCageCharacterBase::ASoulCageCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	//始终更新姿势并刷新骨骼
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* ASoulCageCharacterBase::GetAbilitySystemComponent() const
{
	return nullptr;
}


