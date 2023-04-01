// Fill out your copyright notice in the Description page of Project Settings.


#include "EInpGameMode.h"

#include "EInpPlayerController.h"
#include "EInpPawn.h"

AEInpGameMode::AEInpGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = AEInpPlayerController::StaticClass();
	DefaultPawnClass = AEInpPawn::StaticClass();
}