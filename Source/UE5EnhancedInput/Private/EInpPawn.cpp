// Fill out your copyright notice in the Description page of Project Settings.


#include "EInpPawn.h"

//#include "GameFramework/PawnMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

// Sets default values
AEInpPawn::AEInpPawn(const FObjectInitializer& ObjectInitializer)
//: Super(ObjectInitializer.SetDefaultSubobjectClass<UPawnMovementComponent>(""))
 : Super(ObjectInitializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//!< インプットアクションのアセット
	static ConstructorHelpers::FObjectFinder<UInputAction> Move(TEXT("/Script/EnhancedInput.InputAction'/Game/IA_Move.IA_Move'"));
	if (Move.Succeeded())
	{
		IA_Move = Move.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> Look(TEXT("/Script/EnhancedInput.InputAction'/Game/IA_Look.IA_Look'"));
	if (Look.Succeeded())
	{
		IA_Look = Look.Object;
	}
}

// Called when the game starts or when spawned
void AEInpPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEInpPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEInpPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//!< インプットアクションをバインド
	if (auto Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (nullptr != IA_Move) 
		{
			Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AEInpPawn::OnMove);
		}
		if (nullptr != IA_Look) 
		{
			Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AEInpPawn::OnLook);
		}
	}
}

void AEInpPawn::OnMove(const FInputActionInstance& Instance)
{
	auto Value = Instance.GetValue().Get<FVector2D>();

	AddMovementInput(GetActorRightVector(), Value.X);
	AddMovementInput(GetActorForwardVector(), Value.Y);

	GEngine->AddOnScreenDebugMessage(0, 0.0f, FColor::White, FString::Printf(TEXT("OnMove = (%2.1f, %2.1f)"), Value.X, Value.Y));
}
void AEInpPawn::OnLook(const FInputActionInstance& Instance)
{
	auto Value = Instance.GetValue().Get<FVector2D>();

	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);

	GEngine->AddOnScreenDebugMessage(0, 0.0f, FColor::White, FString::Printf(TEXT("OnLook = (%2.1f, %2.1f)"), Value.X, Value.Y));
}