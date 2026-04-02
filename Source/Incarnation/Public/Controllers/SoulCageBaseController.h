// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SoulCageBaseController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class INCARNATION_API ASoulCageBaseController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere,category = "SoulCage|Input|Movement")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditAnywhere,category = "SoulCage|Input|Movement")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditAnywhere,category = "SoulCage|Input|Movement")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere,category = "SoulCage|Input|Movement")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere,category = "SoulCage|Input|Abilities")
	TObjectPtr<UInputAction> PrimaryAction;
	
	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Primary();
};
