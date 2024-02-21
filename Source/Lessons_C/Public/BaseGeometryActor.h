// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Settings|Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Settings|Movement")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Settings|Movement")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere, Category = "Settings|Design")
	FLinearColor Color = FLinearColor::Black;

	UPROPERTY(EditAnywhere, Category = "Settings|Design")
	float TimerRate = 3.0f;
};


UCLASS()
class LESSONS_C_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Settings|GeometryData")
	FGeometryData GeometryData;

	UPROPERTY(EditAnywhere, Category = "Settings|Weapon")
	int32 WeaponsNum = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Stat")
	int32 KillsNum = 7;

	UPROPERTY(EditInstanceOnly, Category = "Settings|Health")
	float Health = 34.4536473435f;

	UPROPERTY(EditAnywhere, Category = "Settings|Health")
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Settings|Weapon")
	bool HasWeapon = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;
	FTimerHandle TimerHandle;

	const int32 MaxTimerCount = 5;
	int32 TimerCount = 0;

	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();
	void HandleMovement();

	void SetColor(const FLinearColor& Color);

	void OnTimerFired();
};
