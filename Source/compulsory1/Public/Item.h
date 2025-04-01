// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Character1.h"
#include "Item.generated.h"

UCLASS()
class COMPULSORY1_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(visibleAnywhere)
	UBoxComponent* Box;
	UPROPERTY(visibleAnywhere)
	UStaticMeshComponent* Orb;
	UPROPERTY(visibleAnywhere)
	UStaticMeshComponent* Ring;

	UFUNCTION()
	void OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweeep, const FHitResult& SweepResult);

};

