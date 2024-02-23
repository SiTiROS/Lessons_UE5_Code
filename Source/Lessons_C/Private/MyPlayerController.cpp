// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyPlayerController, All, All)

void AMyPlayerController::SetupInputComponent() 
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindAction("ChangePawn", IE_Pressed, this, &AMyPlayerController::ChangePawn);
    }
}

void AMyPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyPawn::StaticClass(), Pawns);
}

void AMyPlayerController::ChangePawn()
{
    if (Pawns.Num() <= 1) return;

    AMyPawn* CurrentPawn = Cast<AMyPawn>(Pawns[CurrentPawnIndex]);
    CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();
    if (!CurrentPawn) return;

    UE_LOG(LogMyPlayerController, Error, TEXT("Change player pawn"));
    Possess(CurrentPawn);
}
