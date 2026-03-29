// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SoulCageCharacterBase.h"

// Sets default values
ASoulCageCharacterBase::ASoulCageCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoulCageCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoulCageCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASoulCageCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

