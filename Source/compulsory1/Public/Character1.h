// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "Character1.generated.h"

UCLASS()
class COMPULSORY1_API ACharacter1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter1();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere , Category = "mInput")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "mInput")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "mInput")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "mInput")
	UInputAction* JumpAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void JumpFunc(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;


};
