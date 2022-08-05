// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Astronot.generated.h"

UCLASS()
class GAMEJAM_API AAstronot : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAstronot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GoForwardFunction(float Value);

	void GoRightFunction(float Value);

	void Runing();

	void ReleasedRuningKeyFunction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	bool bForBlockMovement;
	
	/*store the default walk speed*/
	float DefaultRuningSpeed;

	//store the speed when you pressed shift key
	UPROPERTY(EditDefaultsOnly ,BlueprintReadOnly ,  Category = "Component" , meta = (AllowPrivateAccess = "true"))
	float SpeedWhileRuning;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USpringArmComponent* SpringArmComp = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UCameraComponent* CameraComp = nullptr;


/*For Getter and setter functions*/
public:
	FORCEINLINE USpringArmComponent* GetSpringArmComp() const { return SpringArmComp; }

	FORCEINLINE UCameraComponent* GetCameraComp() const { return CameraComp; }
};
