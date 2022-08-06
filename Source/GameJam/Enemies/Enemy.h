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

	UFUNCTION(BlueprintCallable)
	FVector GetNextPatrolLocation();

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GiveAlarm();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnAlarm();

	UPROPERTY(BlueprintReadWrite)
	FVector StartingLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (InlineEditConditionToggle))
	bool bMakePatrolWaitingDeflection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bMakePatrolWaitingDeflection", Units = "s"));
	float WaitingDeflectionRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
	TArray<FVector> TargetPatrolLocations;
	
	UPROPERTY(BlueprintReadWrite)
	int LastPatrolIndex = 0;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float AdditionalAlarmSpeed = 900.0f;

	UPROPERTY(BlueprintReadWrite)
	bool bInAlarm = false;


};


