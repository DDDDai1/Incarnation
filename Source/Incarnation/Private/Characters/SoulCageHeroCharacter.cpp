// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SoulCageHeroCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerState/SoulCagePlayerState.h"
#include "AbilitySystemComponent.h"

ASoulCageHeroCharacter::ASoulCageHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	//胶囊体大小
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	//角色不随着摄像头转动而移动，标准第三人称RPG游戏视角
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	//朝向旋转方向移动，角色随移动方向转动
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.0f;
	//相机吊杆的‘角色控制旋转’开启
	CameraBoom->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	//相机吊杆的‘角色控制旋转’关闭
	FollowCamera->bUsePawnControlRotation = false;
}

UAbilitySystemComponent* ASoulCageHeroCharacter::GetAbilitySystemComponent() const
{
	//从玩家状态转换成SoulCage玩家状态
	ASoulCagePlayerState* SoulCagePlayerState = Cast<ASoulCagePlayerState>(GetPlayerState());
	if (!IsValid(SoulCagePlayerState))	return nullptr;
	
	//通过SoulCage玩家状态获取能力系统组件
	return SoulCagePlayerState->GetAbilitySystemComponent();
}

void ASoulCageHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (!IsValid(GetAbilitySystemComponent()))	return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(),this);
}

void ASoulCageHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (!IsValid(GetAbilitySystemComponent()))	return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(),this);
}
