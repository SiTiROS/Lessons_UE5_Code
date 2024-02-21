// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

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

	UPROPERTY(EditAnywhere, Category = "Settings|Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Settings|Movement")
	float Frequency = 2.0f;

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

	void printTypes();
	void printStringTypes();
	void printTransform();
};
