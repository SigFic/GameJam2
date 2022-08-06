// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Astronot.generated.h"

UENUM()
enum class ECharacterSkills
{
	ECS_Ghost UMETA(DisplayName = "Ghost"),
	ECS_ThrowRock UMETA(DisplayName = "ThrowRock"),
	ECS_Teleport UMETA(DisplayName = "Teleport"),
	ECS_Dash UMETA(DisplayName = "Dash"),
	ECS_Hook UMETA(DisplayName = "Hook"),
	ECS_Stone UMETA(DisplayName = "Stone"),
	ECS_Assimilation UMETA(DisplayName = "Assimilation"),

	ECS_Max UMETA(DisplayName = "Max"),

};

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


	UFUNCTION()
	void OnInfoSphereOverlapped(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepHitResult);


	UFUNCTION()
	void OnInfoSphereEndOverlapped(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	
	UFUNCTION()
		void OnAssimillitionSphereOverlapped(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepHitResult);


	UFUNCTION()
		void OnAssimillitionSphereEndOverlapped(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	void SetTimerBetweenThrowRock();
	

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	ECharacterSkills CharacterActifSkills;

	/*attaced to RootComponent*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* AreaSphere;

	/*attaced to RootComponent*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* AreaSphereForAssimillitaion;

	bool bEnemyOverlappedWithAssimilation;

	void UseSkill();

	void SpawnProjectileToWorld();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AStoneProjectile> StoneProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint = nullptr;

	bool bCanThrowStone;

	FTimerHandle ThrowStoneTimer;

	UPROPERTY(EditDefaultsOnly , BlueprintReadWrite , Category = "Component" , meta = (AllowPrivateAccess = "true"))
	float TimeBetweenThrowingStone;
/*For Getter and setter functions*/
public:
	FORCEINLINE USpringArmComponent* GetSpringArmComp() const { return SpringArmComp; }

	FORCEINLINE UCameraComponent* GetCameraComp() const { return CameraComp; }
	
	FORCEINLINE ECharacterSkills GetCharacterActiveSkill() const { return CharacterActifSkills; }
	
	void SetCharacterActiveSkill(ECharacterSkills Skill);
};
