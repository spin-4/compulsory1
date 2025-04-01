// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	Orb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Orb"));
	Ring = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ring"));


	Box->SetupAttachment(GetRootComponent());
	Orb->SetupAttachment(Box);
	Ring->SetupAttachment(Orb);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	Orb->SetWorldRotation(FRotator(0, UKismetMathLibrary::RandomIntegerInRange(0, 360), 0));
	Box->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnPlayerEnter);

}

void AItem::OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweeep, const FHitResult& SweepResult)
{
	ACharacter1* Player = Cast<ACharacter1>(OtherActor);
	if (Player)
	{
		Destroy();
	}


}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

