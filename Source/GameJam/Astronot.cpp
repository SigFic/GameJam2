// Fill out your copyright notice in the Description page of Project Settings.


#include "Astronot.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AAstronot::AAstronot() :
	bForBlockMovement(false),
	DefaultRuningSpeed(0.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp);

	

}

// Called when the game starts or when spawned
void AAstronot::BeginPlay()
{
	Super::BeginPlay();
	
	DefaultRuningSpeed = GetCharacterMovement()->MaxWalkSpeed;
	
}

void AAstronot::GoForwardFunction(float Value)
{
	if (!bForBlockMovement)
	{
		AddMovementInput(FVector(1, 0, 0), Value);
	}
}

void AAstronot::GoRightFunction(float Value)
{
	if (!bForBlockMovement)
	{
		AddMovementInput(FVector(0,1, 0), Value);
	}
}

void AAstronot::Runing()
{
	GetCharacterMovement()->MaxWalkSpeed = SpeedWhileRuning;
}

void AAstronot::ReleasedRuningKeyFunction()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultRuningSpeed;
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

	PlayerInputComponent->BindAction(FName("Runing"), EInputEvent::IE_Pressed, this, &AAstronot::Runing);
	PlayerInputComponent->BindAction(FName("Runing"), EInputEvent::IE_Released, this, &AAstronot::ReleasedRuningKeyFunction);

}

