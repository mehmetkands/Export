

#pragma once

#include "CoreMinimal.h"
#include "PinActors.h"
#include "ShowText.h"
#include "HudScreen.h"
#include "GameFramework/GameStateBase.h"
#include "Components/AudioComponent.h"
#include "FastBowlingGameState.generated.h"

/**
 * 
 */
UCLASS()
class FASTBOWLING_API AFastBowlingGameState : public AGameStateBase
{
	GENERATED_BODY()

private:
	//Default Round Number 
	float RoundNumber=1.0f;

	//Round Point
	float RoundPoint;

	//Total Point
	float TotalPoint;

	void BeginPlay() override;

public:
	//Default Settings
	AFastBowlingGameState();

	//Get Round Number
	UFUNCTION(BlueprintCallable)
		float GetRoundNumber();

	//Set Round Number
	UFUNCTION(BlueprintCallable)
		float SetRoundNumber(float NewValue);

	//Get Round Point
	UFUNCTION(BlueprintCallable)
		float GetRoundPoint();

	//Set Round Point
	UFUNCTION(BlueprintCallable)
		float SetRoundPoint(float NewValue);

	//Round Point Deleter. This function makes the round score zero.
	UFUNCTION(BlueprintCallable)
		float RoundPointDeleter();

	//Create Text Widget
	UFUNCTION(BlueprintCallable)
		void AddWidgetText();

	//Get Total Point
	UFUNCTION(BlueprintCallable)
		float GetTotalPoint();

	//Game Timer
	UFUNCTION(BlueprintCallable)
		void GameTimer();

	//Round Break Bool
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool RoundBreak;

	//Strike bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsStrike;

	//Spare boll
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsSemiStrike;

	//Fail bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsEpicFail;

	//Invalid for now.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsHalfRound;

	//Delay Clear Timer 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DestroyandSpawnTimeAmmount=0.7f;

	//Subclass Pins
	UPROPERTY(EditDefaultsOnly, Category = SpawnCharacter)
		TSubclassOf<class APinActors> CharacterClass;

	//Subclass Widget
	UPROPERTY(EditDefaultsOnly, Category = Widgets)
		TSubclassOf<class UShowText> WidgetClass;

	//Subclass Hud Widget
	UPROPERTY(EditDefaultsOnly, Category = Widgets)
		TSubclassOf<class UHudScreen> HudWidgetClass;

	//Subclass End Screen Widget
	UPROPERTY(EditDefaultsOnly, Category = Widgets)
		TSubclassOf<class UUserWidget> EndScreen;

	//Subclass Round Point Widget 
	UPROPERTY(EditDefaultsOnly, Category = Widgets)
		TSubclassOf<class UShowText> RoundPointWidgetClass;


	UHudScreen* HudWidget;

	UUserWidget* EndScreenWidget;

	UShowText* WC;

	UShowText* RoundPointWidget;
	//**

	//Timer Handle
	FTimerHandle DestroyTime;
	FTimerHandle StartTime;

	//Delay Destroy
	void StartTimerDestroy();



	//Delay
	void StartTimerforPointShower();

	//Point Show
	void PointShower();

	//EndGame Function
	void EndGame();

	//Respawn Pin Actor
	void ReSpawnPins();

	//Epic Fail SFX
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class USoundBase* EpicFailSfx;

	//Spare SFX
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class USoundBase* SpareSfx;

	//Strike SFX
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class USoundBase* StrikeSfx;

	//Point SFX
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class USoundBase* PointSound;

	//Ambiance Music
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class USoundBase* GameMusic;

	//Does user allow music ?
	UPROPERTY(EditAnyWhere,BlueprintReadWrite)
		bool IsPlayerWantsMusic=true;

	//Pin Actors
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APinActors* RespawnPinsL;

	//Timer
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float Second;

	//Extra Round Bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool BonusRound;

	//9 Dedecter
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool PreviousRoundNine;

	//Set Direct, Coin Ammount
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DirectSetup;

	//Is Game Over?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Gameover=false;

	//Freeze Timer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool FreezeTimerHandle;
	

};
