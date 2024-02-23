// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyPawn, All, All);

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
    SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
    StaticMeshComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!VelocityVector.IsZero())
	{
        const FVector NewLocation = GetActorLocation() + Velocity * DeltaTime * VelocityVector;
        SetActorLocation(NewLocation);
        VelocityVector = FVector::ZeroVector;
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (PlayerInputComponent)
    {
        PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
        PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);
    }
}

void AMyPawn::MoveForward(float Amount)
{
    //UE_LOG(LogMyPawn, Display, TEXT("Move forward: %f"), Amount);
    VelocityVector.X = Amount;
}

void AMyPawn::MoveRight(float Amount)
{
    //UE_LOG(LogMyPawn, Display, TEXT("Move right: %f"), Amount);
    VelocityVector.Y = Amount;
}

void AMyPawn::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    if (!NewController) return;
    UE_LOG(LogMyPawn, Error, TEXT("%s possessed %s"), *GetName(), *NewController->GetName());
}

void AMyPawn::UnPossessed()
{
    Super::UnPossessed();

    UE_LOG(LogMyPawn, Warning, TEXT("%s unpossessed %s"), *GetName());
}