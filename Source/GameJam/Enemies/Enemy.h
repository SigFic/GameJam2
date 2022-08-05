// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class GAMEJAM_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:

	AEnemy();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	virtual void BeginPlay() override;

	virtual void GiveAlaram();

	UFUNCTION()
	virtual void OnEnemyDetected(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndEnemyDetected(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* VisionCone = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UDecalComponent* VisionDecal = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
	FVector TargetPatrolLocation;

	UPROPERTY(BlueprintReadWrite)
	FVector StartingLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (InlineEditConditionToggle))
	bool bMakePatrolWaitingDeflection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bMakePatrolWaitingDeflection", Units = "s"));
	float WaitingDeflectionRange;

	

};

