// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameJam/Enemies/Enemy.h"
#include "Commander.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API ACommander : public AEnemy
{
	GENERATED_BODY()
	
public:
	ACommander();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/*will pop up when enemy is overlap with assimilitionSphere*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* AssimillitionWidget = nullptr;

	/*will pop up when enemy is overlap with InfoSphere*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* InfoWidgetForSkills = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	FString TheInfoMassage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	class UTexture2D* Thumbnail = nullptr;

public://for getter and setter

//	TEnumAsByte<PlayerState> GrantedAbility;

	FORCEINLINE UWidgetComponent* GetAssimilitionWidget() const { return AssimillitionWidget; }
	FORCEINLINE UWidgetComponent* GetInfoWidget() const { return InfoWidgetForSkills; }
};
