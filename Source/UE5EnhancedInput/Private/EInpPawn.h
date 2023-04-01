// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EInpPawn.generated.h"

class UInputAction;
struct FInputActionInstance;

UCLASS()
class AEInpPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEInpPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnMove(const FInputActionInstance& Instance);
	virtual void OnLook(const FInputActionInstance& Instance);

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Look;
};
