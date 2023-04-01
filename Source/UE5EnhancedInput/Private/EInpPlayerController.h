// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EInpPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class AEInpPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	AEInpPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* IMC_Normal;
};
