

#pragma once

#include "CoreMinimal.h"
#include "FBPlayerState.h"
#include "GameFramework/PlayerController.h"
#include "FastBowlPlayerController.generated.h"

/**
 *
 */
UCLASS()
class FASTBOWLING_API AFastBowlPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;
public:

	virtual void Tick(float DeltaTime) override;

	//Set Coin Function
	UFUNCTION(BlueprintCallable)
		float SetCoin(float Value);

	//Get Coin Function
	UFUNCTION(BlueprintCallable)
		float GetCoin();

	//Set Total Point Function
	UFUNCTION(BlueprintCallable)
		float SetTotalPoint(float Value);

	//Get Total Point Function
	UFUNCTION(BlueprintCallable)
		float GetTotalPoint();

	//Set Direct Coin Function
	UFUNCTION(BlueprintCallable)
		float SetDirectCoin(float Value);

	//Get Level
	UFUNCTION(BlueprintCallable)
		float GetLevelSystem();

	//Timer
	UFUNCTION(BlueprintCallable)
		void Timer();

	//Delay
	UFUNCTION(BlueprintCallable)
		void StartTimer();

	//saves
	UFUNCTION(BlueprintCallable)
		void SaveCoin();

	UFUNCTION(BlueprintCallable)
		void SaveLevel();

	UFUNCTION(BlueprintCallable)
		void SaveTotalPoint();

	UFUNCTION(BlueprintCallable)
		void SaveTime();

	UFUNCTION(BlueprintCallable)
		void SaveEvent();

	UFUNCTION(BlueprintCallable)
		void SaveUnlockMap();

	UFUNCTION(BlueprintCallable)
		void SaveUnlockSkin();

	UFUNCTION(BlueprintCallable)
		void SaveBallTexture();



	//loads
	UFUNCTION(BlueprintCallable)
		void LoadCoin();
	UFUNCTION(BlueprintCallable)
		void LoadLevel();
	UFUNCTION(BlueprintCallable)
		void LoadTotalPoint();
	UFUNCTION(BlueprintCallable)
		void LoadTime();
	UFUNCTION(BlueprintCallable)
		void LoadEvent();
	UFUNCTION(BlueprintCallable)
		void LoadUnlockMap();
	UFUNCTION(BlueprintCallable)
		void LoadUnlockSkin();
	UFUNCTION(BlueprintCallable)
		void LoadBallTexture();


	UFUNCTION(BlueprintCallable)
		void ChangePoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Point)
		float Coin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Point)
		float PlayerLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Point)
		float TotalPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Point)
		float JumpCount;

	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool goldenball;
	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool silverball;
	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool Diamondball;
	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool fastball;
	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool magicball;

	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool isAvailableChangeball;
	UPROPERTY(BlueprintReadWrite, Category = Events)
		bool IsEventBegin;

	//Level Bools
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelClassic = true;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelSnowball = true;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelTempleball;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelIsland;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelDesert;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelNature;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelMoon;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelDanger;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelRooftop;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelCity;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelOrange;
	UPROPERTY(BlueprintReadWrite, Category = Levels)
		bool LevelHall;

	//Skin Bools
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureRed;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureGreen;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureBlue = true;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureYellow;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureOrange;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TexturePurple;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureWhite;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureBlack;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureGolden;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureSilver;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureEarth;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureMoon;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureCloud;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureFlower;
	UPROPERTY(BlueprintReadWrite, Category = Textures)
		bool TextureCactus;

	//Unlock Skin Bools
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockRed = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockGreen = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockBlue = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockYellow = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockOrange = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockPurple = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockWhite = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockBlack = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockGolden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockSilver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockEarth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockMoon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockCloud;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockFlower;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = UnlockTextures)
		bool UnlockCactus;

	//Timer Bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OtherBooleansSettings)
		bool ActiveTimer;

	//Event Second
	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Second;

	//Event Mimute
	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Minute;

	//Points
	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point1;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point2;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point3;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point4;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point5;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point6;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point7;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point8;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point9;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float Point10;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float PointSpare;

	//Total Points
	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint1;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint2;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint3;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint4;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint5;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint6;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint7;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint8;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint9;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPoint10;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalPointSpare;


	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalSpareCount;

	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float TotalStrikeCount;


	UPROPERTY(BlueprintReadWrite, Category = TimeData)
		float RoundEarnedCoin;

	AFBPlayerState* MyPlayerState;

	FTimerHandle StartCounter;

	//Edition Ct Bool
	bool EditionController();

private:
	UPROPERTY(EditAnywhere)
		bool ProEdition;

};