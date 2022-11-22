

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinActors.generated.h"

UCLASS()
class FASTBOWLING_API APinActors : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinActors();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R1Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R2Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R3Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R4Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R5Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R6Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R7Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R8Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R9Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float R10Point;

	//Falling Pin
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR9;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FallR10;

	//Exempt pin bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR9;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool exemptFallR10;

	//SpawnTimeDelay Ammount
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpawnTimeDelay=1.0f;

	//Delay Play Sfx Time Ammount
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PlaySfxTimeDelay = 1.0f;

	//Point Calculator
	UFUNCTION(BlueprintCallable)
		void PointCalculator();

	//Point Exempt Dedecter
	UFUNCTION(BlueprintCallable)
		void PointExemptDedecter();

	//Strike Dedecter
	UFUNCTION(BlueprintCallable)
		void StrikeDedecter();

	//TimerHandle
	FTimerHandle TimerStarter;
	FTimerHandle TimerStarterForHitSFX;

	//Delay Point Exempt Dedecter
	UFUNCTION(BlueprintCallable)
		void StartTimerforPointExemptDedecter();

	//Delay
	UFUNCTION(BlueprintCallable)
		void HitSFXTimer();

	//Pin Hit SFX
	UFUNCTION(BlueprintCallable)
		void HitSFX();

	//Pin Fall SFX Cue
	UPROPERTY(EditAnywhere)
		USoundBase* FallSFXCue;

};
