#include "Controllers/SoulCageBaseController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void ASoulCageBaseController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//将输入系统绑定为EnhancedInputSystem
	UEnhancedInputLocalPlayerSubsystem* InputSubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (!IsValid(InputSubSystem))	return;
	
	if(IsValid(InputSubSystem))
	{
		for (UInputMappingContext* Context : InputMappingContexts)
		{
			//添加输入映射上下文
			InputSubSystem->AddMappingContext(Context,0);
		}
	}
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent))	return;
	
	//绑定行为，并执行回调函数
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,&ThisClass::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ThisClass::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&ThisClass::Look);
	EnhancedInputComponent->BindAction(PrimaryAction,ETriggerEvent::Triggered,this,&ThisClass::Primary);
}

void ASoulCageBaseController::Jump()
{
	if (!IsValid(GetCharacter()))	return;
	GetCharacter()->Jump();
}

void ASoulCageBaseController::StopJumping()
{
	if (!IsValid(GetCharacter()))	return;
	GetCharacter()->StopJumping();
}

void ASoulCageBaseController::Move(const FInputActionValue& Value)
{
	if (!IsValid(GetCharacter()))	return;
	
	//获取输入的值，并转换为方向变量
	const FVector2D MovementVector = Value.Get<FVector2D>();
	
	//分解为向前向量和向右向量
	const FRotator YawRotation(0.f,GetControlRotation().Yaw,0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	//移动角色
	GetPawn()->AddMovementInput(ForwardDirection,MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection,MovementVector.X);
}

void ASoulCageBaseController::Look(const FInputActionValue& Value)
{
	//获取输入值转换为视角方向变量
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	//Yaw为左右看，Pitch为上下看，还有一个Roll为滚动，和视角无关
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void ASoulCageBaseController::Primary()
{
	UE_LOG(LogTemp,Warning,TEXT("Primary Action Started"));
}
