// Fill out your copyright notice in the Description page of Project Settings.


#include "EInpPlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

AEInpPlayerController::AEInpPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//!< �C���v�b�g�}�b�s���O�R���e�L�X�g�̃A�Z�b�g
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/IMC_Normal.IMC_Normal'"));
	if (IMC.Succeeded())
	{
		IMC_Normal = IMC.Object;
	}
}

void AEInpPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != IMC_Normal)
	{
		for (const auto& i : IMC_Normal->GetMappings()) {}
		if (const auto LP = GetLocalPlayer())
		{
			if (auto InputSystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				//!< �C���v�b�g�}�b�s���O�R���e�L�X�g��ǉ�
				InputSystem->AddMappingContext(IMC_Normal, 0);
			}
		}
	}
}
