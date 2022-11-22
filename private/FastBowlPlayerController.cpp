// Player Controller. It has information about player. Coin, player total point, settings etc.


#include "FastBowlPlayerController.h"
#include "lSaveSystemFastBow.h"
#include "Kismet/GameplayStatics.h"



void AFastBowlPlayerController::BeginPlay()
{
	Super::BeginPlay();

	MyPlayerState = Cast<AFBPlayerState>(GetPlayerState<AFBPlayerState>());
}

void AFastBowlPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	MyPlayerState = Cast<AFBPlayerState>(GetPlayerState<AFBPlayerState>());

	if (MyPlayerState)
	{
		PlayerLevel = MyPlayerState->InGameLevel;
	}



	if (goldenball == true || silverball == true || Diamondball == true || fastball == true || magicball == true)
	{
		ActiveTimer = true;
	}

	else
	{
		ActiveTimer = false;
	}

	ChangePoint();


}

//Set Player Coin
float AFastBowlPlayerController::SetCoin(float Value)
{
	Coin = Coin + Value;
	RoundEarnedCoin = RoundEarnedCoin + Value;
	return Coin;
}

//Get Player Coin
float AFastBowlPlayerController::GetCoin()
{
	return Coin;
}

//Set Total Point
float AFastBowlPlayerController::SetTotalPoint(float Value)
{
	TotalPoint = TotalPoint + Value;

	
	if (MyPlayerState)
	{
		MyPlayerState->Point = TotalPoint;
	}

	return TotalPoint;
}

//Get Total Point
float AFastBowlPlayerController::GetTotalPoint()
{
	return TotalPoint;
}

//Set Direct Coin Function. It does not perform addition. Set Direct.
float AFastBowlPlayerController::SetDirectCoin(float Value)
{
	Coin = Value;
	return Value;
}

//Get Player Level
float AFastBowlPlayerController::GetLevelSystem()
{

	return PlayerLevel;
}

//Event Timer.
void AFastBowlPlayerController::Timer()
{
	//If any event is active.
	if (goldenball == true || silverball == true || Diamondball == true || fastball == true || magicball == true)
	{
		//Simple Timer
		ActiveTimer = true;
		if (Second > 0)
		{
			Second = Second - 1;
		}

		if (Second == 0 && Minute > 0)
		{
			Minute = Minute - 1;
			Second = 59;
		}

		SaveTime(); //Save Time

		if (Second == 0 && Minute == 0)
		{
			//Finish events.
			goldenball = false;
			silverball = false;
			Diamondball = false;
			fastball = false;
			magicball = false;

			//Return the scoring to normal.
			Point1 = 5.0f;
			Point2 = 5.0f;
			Point3 = 5.0f;
			Point4 = 5.0f;
			Point5 = 5.0f;
			Point6 = 5.0f;
			Point7 = 5.0f;
			Point8 = 10.0f;
			Point9 = 25.0f;
			PointSpare = 50.0f;
			Point10 = 100.0f;

			//Return the scoring to normal.
			TotalPoint1 = 10.0f;
			TotalPoint2 = 10.0f;
			TotalPoint3 = 10.0f;
			TotalPoint4 = 10.0f;
			TotalPoint5 = 10.0f;
			TotalPoint6 = 10.0f;
			TotalPoint7 = 10.0f;
			TotalPoint8 = 10.0f;
			TotalPoint9 = 30.0f;
			TotalPointSpare = 50.0f;
			TotalPoint10 = 100.0f;

		}
	}
}

//Start Event Timer
void AFastBowlPlayerController::StartTimer()
{
	GetWorldTimerManager().SetTimer(StartCounter, this, &AFastBowlPlayerController::Timer, 1.0f, true);
}


//SAVE FUNCTIONS

//Save Player Coin
void AFastBowlPlayerController::SaveCoin()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data on the savegame object.
		SaveGameInstance->Coin = Coin;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveCoin"), 0);
	}
}

//Save Player Level
void AFastBowlPlayerController::SaveLevel()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data on the savegame object.
		if (MyPlayerState)
		{
			SaveGameInstance->PlayerLevel = MyPlayerState->InGameLevel;
		}
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveLevel"), 0);


	}
}

//Save Player Total Point
void AFastBowlPlayerController::SaveTotalPoint()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data on the savegame object.
		SaveGameInstance->TotalPoint = TotalPoint;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveTotalPoint"), 0);

		// Save the data immediately.
	}
}

//Save Event Second and Minute
void AFastBowlPlayerController::SaveTime()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data on the savegame object.
		SaveGameInstance->Second = Second;
		SaveGameInstance->Minute = Minute;


		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveTime"), 0);
	}
}

////Save Active Event
void AFastBowlPlayerController::SaveEvent()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{

		// Set data on the savegame object.
		SaveGameInstance->goldenball = goldenball;
		SaveGameInstance->silverball = silverball;
		SaveGameInstance->Diamondball = Diamondball;
		SaveGameInstance->fastball = fastball;
		SaveGameInstance->magicball = magicball;


		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveEvent"), 0);

	}
}

//Save Unlock Maps
void AFastBowlPlayerController::SaveUnlockMap()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{

		// Set data on the savegame object.
		SaveGameInstance->LevelClassic = LevelClassic;
		SaveGameInstance->LevelSnowball = LevelSnowball;
		SaveGameInstance->LevelTempleball = LevelTempleball;
		SaveGameInstance->LevelIsland = LevelIsland;
		SaveGameInstance->LevelDesert = LevelDesert;

		SaveGameInstance->LevelNature = LevelNature;
		SaveGameInstance->LevelMoon = LevelMoon;
		SaveGameInstance->LevelDanger = LevelDanger;
		SaveGameInstance->LevelRooftop = LevelRooftop;
		SaveGameInstance->LevelCity = LevelCity;
		SaveGameInstance->LevelOrange = LevelOrange;
		SaveGameInstance->LevelHall = LevelHall;


		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveUnlockMap"), 0);

	}
}

//Save Skins
void AFastBowlPlayerController::SaveUnlockSkin()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data on the savegame object.
		SaveGameInstance->UnlockRed = UnlockRed;
		SaveGameInstance->UnlockGreen = UnlockGreen;
		SaveGameInstance->UnlockBlue = UnlockBlue;
		SaveGameInstance->UnlockYellow = UnlockYellow;
		SaveGameInstance->UnlockPurple = UnlockPurple;

		SaveGameInstance->UnlockWhite = UnlockWhite;
		SaveGameInstance->UnlockBlack = UnlockBlack;
		SaveGameInstance->UnlockGolden = UnlockGolden;
		SaveGameInstance->UnlockEarth = UnlockEarth;
		SaveGameInstance->UnlockMoon = UnlockMoon;

		SaveGameInstance->UnlockCloud = UnlockCloud;
		SaveGameInstance->UnlockFlower = UnlockFlower;
		SaveGameInstance->UnlockCactus = UnlockCactus;

		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveUnlockSkin"), 0);

	}
}

//Save Current Skin
void AFastBowlPlayerController::SaveBallTexture()
{
	UlSaveSystemFastBow* SaveGameInstance = Cast<UlSaveSystemFastBow>(UGameplayStatics::CreateSaveGameObject(UlSaveSystemFastBow::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data on the savegame object.

		SaveGameInstance->TextureRed = TextureRed;
		SaveGameInstance->TextureGreen = TextureGreen;
		SaveGameInstance->TextureBlue = TextureBlue;
		SaveGameInstance->TextureYellow = TextureYellow;
		SaveGameInstance->TexturePurple = TexturePurple;

		SaveGameInstance->TextureWhite = TextureWhite;
		SaveGameInstance->TextureBlack = TextureBlack;
		SaveGameInstance->TextureGolden = TextureGolden;
		SaveGameInstance->TextureEarth = TextureEarth;
		SaveGameInstance->TextureMoon = TextureMoon;

		SaveGameInstance->TextureCloud = TextureCloud;
		SaveGameInstance->TextureFlower = TextureFlower;
		SaveGameInstance->TextureCactus = TextureCactus;




		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveBallTexture"), 0);

	}
}


//LOAD FUNCTION

//Load Player Coin
void AFastBowlPlayerController::LoadCoin()
{

	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveCoin"), 0));
	if (LoadedGame)
	{
		Coin = LoadedGame->Coin;

	}

}

//Load Player Level
void AFastBowlPlayerController::LoadLevel()
{
	MyPlayerState = Cast<AFBPlayerState>(GetPlayerState<AFBPlayerState>());
	if (MyPlayerState)
	{
		UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveLevel"), 0));
		if (LoadedGame)
		{
			MyPlayerState->InGameLevel = LoadedGame->PlayerLevel;
		}
	}
}

//Load Player Total Point
void AFastBowlPlayerController::LoadTotalPoint()
{

	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveTotalPoint"), 0));
	if (LoadedGame)
	{
		TotalPoint = LoadedGame->TotalPoint;
	}

}

//Load Event Time
void AFastBowlPlayerController::LoadTime()
{


	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveTime"), 0));
	if (LoadedGame)
	{
		Second = LoadedGame->Second;
		Minute = LoadedGame->Minute;
	}

}

//Load Active Event
void AFastBowlPlayerController::LoadEvent()
{

	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveEvent"), 0));
	if (LoadedGame)
	{
		//ActiveTimer= LoadedGame->IsActiveTimer;
		goldenball = LoadedGame->goldenball;
		silverball = LoadedGame->silverball;
		Diamondball = LoadedGame->Diamondball;
		fastball = LoadedGame->fastball;
		magicball = LoadedGame->magicball;
	}

}

//Load Unlocked Map
void AFastBowlPlayerController::LoadUnlockMap()
{

	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveUnlockMap"), 0));
	if (LoadedGame)
	{
		LevelClassic = LoadedGame->LevelClassic;
		LevelSnowball = LoadedGame->LevelSnowball;
		LevelTempleball = LoadedGame->LevelTempleball;
		LevelIsland = LoadedGame->LevelIsland;
		LevelDesert = LoadedGame->LevelDesert;

		LevelNature = LoadedGame->LevelNature;
		LevelMoon = LoadedGame->LevelMoon;
		LevelDanger = LoadedGame->LevelDanger;
		LevelRooftop = LoadedGame->LevelRooftop;
		LevelCity = LoadedGame->LevelCity;
		LevelOrange = LoadedGame->LevelOrange;
		LevelHall = LoadedGame->LevelHall;
	}

}

//Load unlocked skin.
void AFastBowlPlayerController::LoadUnlockSkin()
{

	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveUnlockSkin"), 0));
	if (LoadedGame)
	{
		UnlockRed = LoadedGame->UnlockRed;
		UnlockGreen = LoadedGame->UnlockGreen;
		UnlockBlue = LoadedGame->UnlockBlue;
		UnlockYellow = LoadedGame->UnlockYellow;
		UnlockPurple = LoadedGame->UnlockPurple;

		UnlockWhite = LoadedGame->UnlockWhite;
		UnlockBlack = LoadedGame->UnlockBlack;
		UnlockGolden = LoadedGame->UnlockGolden;
		UnlockEarth = LoadedGame->UnlockEarth;
		UnlockMoon = LoadedGame->UnlockMoon;

		UnlockCloud = LoadedGame->UnlockCloud;
		UnlockFlower = LoadedGame->UnlockFlower;
		UnlockCactus = LoadedGame->UnlockCactus;
	}

}

//Load Player Skin
void AFastBowlPlayerController::LoadBallTexture()
{

	UlSaveSystemFastBow* LoadedGame = Cast<UlSaveSystemFastBow>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveBallTexture"), 0));
	if (LoadedGame)
	{
		TextureRed = LoadedGame->TextureRed;
		TextureGreen =  LoadedGame->TextureGreen;
		TextureBlue = LoadedGame->TextureBlue;
		TextureYellow = LoadedGame->TextureYellow;
		TexturePurple = LoadedGame->TexturePurple;

		TextureWhite = LoadedGame->TextureWhite;
		TextureBlack = LoadedGame->TextureBlack;
		TextureGolden = LoadedGame->TextureGolden;
		TextureEarth = LoadedGame->TextureEarth;
		TextureMoon = LoadedGame->TextureMoon;

		TextureCloud = LoadedGame->TextureCloud;
		TextureFlower = LoadedGame->TextureFlower;
		TextureCactus = LoadedGame->TextureCactus;
	}

}

//Change the coin ammount according to the active event. Change the amount of points according to the event type.
void AFastBowlPlayerController::ChangePoint()
{

	if (fastball == true&&magicball == false && silverball == false && Diamondball == false &&goldenball==false)
	{
		Point1 = 7.5f;
		Point2 = 7.5f;
		Point3 = 7.5f;
		Point4 = 7.5f;
		Point5 = 7.5f;
		Point6 = 7.5f;
		Point7 = 7.5f;
		Point8 = 7.5f;
		Point9 = 37.5f;
		PointSpare = 75.0f;
		Point10 = 150.0f;

		TotalPoint1 = 15.0f;
		TotalPoint2 = 15.0f;
		TotalPoint3 = 15.0f;
		TotalPoint4 = 15.0f;
		TotalPoint5 = 15.0f;
		TotalPoint6 = 15.0f;
		TotalPoint7 = 15.0f;
		TotalPoint8 = 15.0f;
		TotalPoint9 = 45.0f;
		TotalPointSpare = 75.0f;
		TotalPoint10 = 150.0f;
	}


	if (fastball == false && magicball == true && silverball == false && Diamondball == false && goldenball == false)
	{
		Point1 = 10.0f;
		Point2 = 10.0f;
		Point3 = 10.0f;
		Point4 = 10.0f;
		Point5 = 10.0f;
		Point6 = 10.0f;
		Point7 = 10.0f;
		Point8 = 10.0f;
		Point9 = 50.0f;
		PointSpare = 100.0f;
		Point10 = 200.0f;

		TotalPoint1 = 20.0f;
		TotalPoint2 = 20.0f;
		TotalPoint3 = 20.0f;
		TotalPoint4 = 20.0f;
		TotalPoint5 = 20.0f;
		TotalPoint6 = 20.0f;
		TotalPoint7 = 20.0f;
		TotalPoint8 = 20.0f;
		TotalPoint9 = 60.0f;
		TotalPointSpare = 100.0f;
		TotalPoint10 = 200.0f;
	}


	if (fastball == false && magicball == false && silverball == true && Diamondball == false && goldenball == false)
	{
		Point1 = 15.0f;
		Point2 = 15.0f;
		Point3 = 15.0f;
		Point4 = 15.0f;
		Point5 = 15.0f;
		Point6 = 15.0f;
		Point7 = 15.0f;
		Point8 = 15.0f;
		Point9 = 75.0f;
		PointSpare = 150.0f;
		Point10 = 300.0f;


		TotalPoint1 = 30.0f;
		TotalPoint2 = 30.0f;
		TotalPoint3 = 30.0f;
		TotalPoint4 = 30.0f;
		TotalPoint5 = 30.0f;
		TotalPoint6 = 30.0f;
		TotalPoint7 = 30.0f;
		TotalPoint8 = 30.0f;
		TotalPoint9 = 90.0f;
		TotalPointSpare = 150.0f;
		TotalPoint10 = 300.0f;
	}


	if (fastball == false && magicball == false && silverball == false && Diamondball == true && goldenball == false)
	{
		Point1 = 20.0f;
		Point2 = 20.0f;
		Point3 = 20.0f;
		Point4 = 20.0f;
		Point5 = 20.0f;
		Point6 = 20.0f;
		Point7 = 20.0f;
		Point8 = 20.0f;
		Point9 = 100.0f;
		PointSpare = 200.0f;
		Point10 = 400.0f;

		TotalPoint1 = 40.0f;
		TotalPoint2 = 40.0f;
		TotalPoint3 = 40.0f;
		TotalPoint4 = 40.0f;
		TotalPoint5 = 40.0f;
		TotalPoint6 = 40.0f;
		TotalPoint7 = 40.0f;
		TotalPoint8 = 40.0f;
		TotalPoint9 = 120.0f;
		TotalPointSpare = 200.0f;
		TotalPoint10 = 400.0f;
	}


	if (fastball == false && magicball == false && silverball == false && Diamondball == false && goldenball == true)
	{
		Point1 = 25.0f;
		Point2 = 25.0f;
		Point3 = 25.0f;
		Point4 = 25.0f;
		Point5 = 25.0f;
		Point6 = 25.0f;
		Point7 = 25.0f;
		Point8 = 25.0f;
		Point9 = 125.0f;
		PointSpare = 250.0f;
		Point10 = 500.0f;


		TotalPoint1 = 50.0f;
		TotalPoint2 = 50.0f;
		TotalPoint3 = 50.0f;
		TotalPoint4 = 50.0f;
		TotalPoint5 = 50.0f;
		TotalPoint6 = 50.0f;
		TotalPoint7 = 50.0f;
		TotalPoint8 = 50.0f;
		TotalPoint9 = 150.0f;
		TotalPointSpare = 250.0f;
		TotalPoint10 = 500.0f;
	}


	if (fastball == false && magicball == false && silverball == false && Diamondball == false && goldenball == false)
	{
		Point1 = 5.0f;
		Point2 = 5.0f;
		Point3 = 5.0f;
		Point4 = 5.0f;
		Point5 = 5.0f;
		Point6 = 5.0f;
		Point7 = 5.0f;
		Point8 = 10.0f;
		Point9 = 25.0f;
		PointSpare = 50.0f;
		Point10 = 100.0f;


		TotalPoint1 = 10.0f;
		TotalPoint2 = 10.0f;
		TotalPoint3 = 10.0f;
		TotalPoint4 = 10.0f;
		TotalPoint5 = 10.0f;
		TotalPoint6 = 10.0f;
		TotalPoint7 = 10.0f;
		TotalPoint8 = 10.0f;
		TotalPoint9 = 30.0f;
		TotalPointSpare = 50.0f;
		TotalPoint10 = 100.0f;
	}
}

//Control Pro edition.
bool AFastBowlPlayerController::EditionController()
{
	return ProEdition;
}
