

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PinActors.h"
#include "FastBowlingCharacter.h"
#include "Engine/World.h"
#include "Components/BoxComponent.h"
#include "DedectedBox.generated.h"


UCLASS()
class FASTBOWLING_API ADedectedBox : public ATriggerBox
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
	class UBoxComponent* TriggerVolume;

public:
	ADedectedBox();

	TArray<AActor*> FoundActors;

	TArray<AActor*> FoundActorsSecond;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FVector SpawnLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FRotator SpawnRotation;

	UFUNCTION()
		void Beginoverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
		void Respawn();

	UFUNCTION()
		void PointCalculate();

	UFUNCTION(BlueprintCallable)
		void TimerRespawner();



	UPROPERTY(EditDefaultsOnly, Category = SpawnCharacter)
		TSubclassOf<class AFastBowlingCharacter> CharacterClass;

	//Spawn Time Delay Ammount
	UPROPERTY(EditAnyWhere)
		float SpawnTimeDelay=5.0f;


	UPROPERTY(EditAnyWhere)
		float PCTimeDelay = 1.0f;

	//Gameplay Time Ammount
	UPROPERTY(EditAnyWhere,BlueprintReadWrite)
		float GameTime = 30.0f;

	//Start Sound Base
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class USoundBase* StartSound;


	//Timer Handles
	FTimerHandle FunctionTimer;
	FTimerHandle FunctionTimerSecond;
	FTimerHandle TimeController;

protected:
	virtual void BeginPlay() override;
	
};
