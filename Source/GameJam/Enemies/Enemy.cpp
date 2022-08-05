// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJam/Enemies/Enemy.h"
#include "Components/DecalComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisionCone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vision Cone"));
	VisionCone->SetupAttachment(RootComponent);
	VisionCone->SetVisibility(false);
	VisionCone->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnEnemyDetected);
	VisionCone->OnComponentEndOverlap.AddDynamic(this, &AEnemy::EndEnemyDetected);

	VisionDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("Vision Decal"));
	VisionDecal->SetupAttachment(VisionCone);



}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	StartingLocation = GetActorLocation();

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::GiveAlaram()
{

}

void AEnemy::OnEnemyDetected(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AEnemy::EndEnemyDetected(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
