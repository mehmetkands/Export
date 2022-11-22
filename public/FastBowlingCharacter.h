

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FastBowlingCharacter.generated.h"

UCLASS(config=Game)
class AFastBowlingCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	//Ball Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* StaticMeshC;


	//Material Types
	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material1;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material2;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material3;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material4;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material5;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material6;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material7;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material8;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material9;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material10;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material11;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material12;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material13;


public:
	AFastBowlingCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void SpeedPlus();
	void SpeedNega();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void BeginPlay() override;

	virtual void Tick(float Deltasecond) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	//Destroyer
	void Destroyer();

	//Start Destroy
	void StartDestroy();

	//Ball Destroy Time Delay Ammount
	UPROPERTY(EditAnyWhere)
		float BallDestroyTimeDelay = 1.0f;

	//This Function Change the Ball Mesh Color
	UFUNCTION(BlueprintCallable)
	void ChangeBallColor();

	//Music
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InGameMusic)
		USoundBase* MusicType;

};

