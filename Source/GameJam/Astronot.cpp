// Fill out your copyright notice in the Description page of Project Settings.


#include "Astronot.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "GameJam/Enemies/Enemy.h"
#include "GameJam/Enemies/Commander.h"
#include "StoneProjectile.h"

// Sets default values
AAstronot::AAstronot() :
	bForBlockMovement(false),
	DefaultRuningSpeed(0.f),
	CharacterActifSkills(ECharacterSkills::ECS_ThrowRock),
	bCanThrowStone(true),
	TimeBetweenThrowingStone(5.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp);

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Spehere component for Player"));
	AreaSphere->SetupAttachment(RootComponent);

	AreaSphereForAssimillitaion = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere comp for assilmilition widget to pop up "));
	AreaSphereForAssimillitaion->SetupAttachment(RootComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn point of Projectile"));
	ProjectileSpawnPoint->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAstronot::BeginPlay()
{
	Super::BeginPlay();

	bEnemyOverlappedWithAssimilation = false;
	
	DefaultRuningSpeed = GetCharacterMovement()->MaxWalkSpeed;

	AreaSphereForAssimillitaion->OnComponentBeginOverlap.AddDynamic(this, &AAstronot::OnAssimillitionSphereOverlapped);
	AreaSphereForAssimillitaion->OnComponentEndOverlap.AddDynamic(this, &AAstronot::OnAssimillitionSphereEndOverlapped);

	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &AAstronot::OnInfoSphereOverlapped);
	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &AAstronot::OnInfoSphereEndOverlapped);

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


void AAstronot::OnInfoSphereOverlapped(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{

	ACommander* CommanderRef = Cast<ACommander>(OtherActor);

	if (CommanderRef)
	{
		CommanderRef->GetInfoWidget()->SetVisibility(true);
	}
}

void AAstronot::OnInfoSphereEndOverlapped(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACommander* CommanderRef = Cast<ACommander>(OtherActor);

	if (CommanderRef)
	{
		CommanderRef->GetInfoWidget()->SetVisibility(false);
	}
}

void AAstronot::OnAssimillitionSphereOverlapped(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{

	ACommander* CommanderRef = Cast<ACommander>(OtherActor);

	if (CommanderRef)
	{
		CommanderRef->GetAssimilitionWidget()->SetVisibility(true);
		CommanderRef->GetInfoWidget()->SetVisibility(false);
	}
}

void AAstronot::OnAssimillitionSphereEndOverlapped(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	ACommander* CommanderRef = Cast<ACommander>(OtherActor);

	if (CommanderRef)
	{
		CommanderRef->GetAssimilitionWidget()->SetVisibility(false);
		CommanderRef->GetInfoWidget()->SetVisibility(true);
		bEnemyOverlappedWithAssimilation = false;
	}
}

void AAstronot::SetTimerBetweenThrowRock()
{
	bCanThrowStone = true;
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

	PlayerInputComponent->BindAction(FName("UseSkill"), EInputEvent::IE_Pressed, this, &AAstronot::UseSkill);

}

void AAstronot::UseSkill()
{

	switch (CharacterActifSkills)
	{
	case ECharacterSkills::ECS_Ghost:
		UE_LOG(LogTemp, Warning, TEXT("Its working 1"));
		break;
	case ECharacterSkills::ECS_ThrowRock:
		if (bCanThrowStone)
		{
			SpawnProjectileToWorld();
			bCanThrowStone = false;
			GetWorld()->GetTimerManager().SetTimer(ThrowStoneTimer, this, &AAstronot::SetTimerBetweenThrowRock, TimeBetweenThrowingStone, false);
		}
		break;
	case ECharacterSkills::ECS_Teleport:
		break;
	case ECharacterSkills::ECS_Dash:
		break;
	case ECharacterSkills::ECS_Hook:
		break;
	case ECharacterSkills::ECS_Stone:
		break;
	case ECharacterSkills::ECS_Max:
		break;
	default:
		break;
	}
}

void AAstronot::SpawnProjectileToWorld()
{
	AStoneProjectile* ProjectileRef = GetWorld()->SpawnActor<AStoneProjectile>(StoneProjectileClass ,
		ProjectileSpawnPoint->GetComponentLocation(),
		ProjectileSpawnPoint->GetComponentRotation());

	ProjectileRef->SetOwner(this);
}

void AAstronot::SetCharacterActiveSkill(ECharacterSkills Skill)
{
	CharacterActifSkills = Skill;
}

