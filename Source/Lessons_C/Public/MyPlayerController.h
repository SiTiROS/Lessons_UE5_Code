// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LESSONS_C_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
    virtual void SetupInputComponent() override;
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TArray<AActor*> Pawns;

    int32 CurrentPawnIndex = 0;

    void ChangePawn();
};
