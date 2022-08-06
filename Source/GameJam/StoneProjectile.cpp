// Fill out your copyright notice in the Description page of Project Settings.


#include "StoneProjectile.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AStoneProjectile::AStoneProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentOfStone"));
	SetRootComponent(StoneMesh);

	ProjectileCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision of Stone"));
	ProjectileCollision->SetupAttachment(StoneMesh);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Comp"));


}

// Called when the game starts or when spawned
void AStoneProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	ProjectileMovementComp->InitialSpeed = ProjectileSpeed;
	ProjectileMovementComp->MaxSpeed = ProjectileSpeed;

}

// Called every frame
void AStoneProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

