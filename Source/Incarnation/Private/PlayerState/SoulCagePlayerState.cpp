// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/SoulCagePlayerState.h"
#include "AbilitySystemComponent.h"

ASoulCagePlayerState::ASoulCagePlayerState()
{
	//网络更新频率,每秒100次
	NetUpdateFrequency = 100.f;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	//设置混合复制模式，用于多人游戏
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ASoulCagePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

