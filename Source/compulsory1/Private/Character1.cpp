// Fill out your copyright notice in the Description page of Project Settings.


#include "Character1.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ACharacter1::ACharacter1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform);

	SpringArm->TargetArmLength = 500;
	SpringArm->SocketOffset = FVector(0, 0, 120);
	SpringArm->bUsePawnControlRotation = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->MaxWalkSpeed = 500;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ACharacter1::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Begin Play"));

	//float ExampleFloat = 0.5f;
	//int ExampleInteger = 20;
	//FVector ExampleVector = FVector(1, 2, 3);


	//UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), ExampleFloat);
	//UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), ExampleInteger);
	//UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *ExampleVector.ToString());



	APlayerController* Character1Controller = Cast<APlayerController>(GetController());
	
	if (Character1Controller)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Character1Controller->GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->ClearAllMappings(); Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	

}



// Called every frame
void ACharacter1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACharacter1::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACharacter1::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter1::JumpFunc);
	}
}

void ACharacter1::Move(const FInputActionValue& Value)
{
	FVector2D RCVValue = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *RCVValue.ToString());


	FRotator ControlRotation = GetControlRotation();

	FVector ForwardVector = FRotationMatrix(FRotator(0, ControlRotation.Yaw, 0)).GetUnitAxis(EAxis::X);
	FVector RightVector = FRotationMatrix(FRotator(0, ControlRotation.Yaw, ControlRotation.Roll)).GetUnitAxis(EAxis::Y);


	AddMovementInput(ForwardVector, RCVValue.Y);
	AddMovementInput(RightVector, RCVValue.X);

}

void ACharacter1::Look(const FInputActionValue& Value)
{
	FVector2D RCVValue = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *RCVValue.ToString());

	AddControllerPitchInput(RCVValue.Y);
	AddControllerYawInput(RCVValue.X);


}

void ACharacter1::JumpFunc(const FInputActionValue& Value)
{

	Jump();

}
