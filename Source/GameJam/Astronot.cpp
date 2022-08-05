// Fill out your copyright notice in the Description page of Project Settings.


#include "Astronot.h"

// Sets default values
AAstronot::AAstronot() :
	bForMovement(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAstronot::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AAstronot::GoForwardFunction(float Value)
{
	AddMovementInput(FVector(1, 0, 0), Value);
}

void AAstronot::GoRightFunction(float Value)
{
	AddMovementInput(FVector(0,1, 0), Value);
}

// Called every frame
void AAstronot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAstronot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("Forward"), this, &AAstronot::GoForwardFunction);
	PlayerInputComponent->BindAxis(FName("Right"), this, &AAstronot::GoRightFunction);

}

