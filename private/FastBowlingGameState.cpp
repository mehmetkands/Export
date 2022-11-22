//Game State. Controls in-game functions. Round number, countdown, respawn pins, end screen etc.


#include "FastBowlingGameState.h"
#include "Kismet/GameplayStatics.h"


AFastBowlingGameState::AFastBowlingGameState()
{
	//Set default countdown second. If you want to set a different amount based on level, use the level blueprint.
									
	Second;
}

void AFastBowlingGameState::BeginPlay()
{
	Super::BeginPlay();

	// Create Hud Widget at Start Game. Do not delete.
	HudWidget = CreateWidget< UHudScreen>(GetWorld(), HudWidgetClass);

	if (HudWidget!=NULL)
	{
		HudWidget->AddToViewport();
	}



}

float AFastBowlingGameState::GetRoundNumber()
{
	//Get Round Number
	return RoundNumber;
}

float AFastBowlingGameState::SetRoundNumber(float NewValue)
{
	//if DirectSetup enabled, set round number direct .
	if (DirectSetup==true)
	{
		RoundNumber = NewValue;
	}

	//else, addition current number with new value.
	else
	{
		
		RoundNumber = RoundNumber + NewValue;
		EndGame();
	}


	return RoundNumber;
}

//Get Round Point
float AFastBowlingGameState::GetRoundPoint()
{
	return RoundPoint;
}

//Set Round Point
float AFastBowlingGameState::SetRoundPoint(float NewValue)
{
	RoundPoint = NewValue + RoundPoint;
	TotalPoint = TotalPoint+ NewValue;
	return RoundPoint;
	
}

//Return zero
float AFastBowlingGameState::RoundPointDeleter()
{
	RoundPoint = 0;
	return 0.0f;
}

void AFastBowlingGameState::AddWidgetText()
{
	//If something unusual happened, draw this screen.
	if (IsStrike==true||IsSemiStrike==true || IsEpicFail == true)
	{
		WC = CreateWidget<UShowText>(GetWorld(), WidgetClass);
		if (WC!=NULL)
		{
			WC->AddToViewport();

			if (IsStrike == true)
			{
				if (StrikeSfx != NULL)
				{
					UGameplayStatics::PlaySound2D(this, StrikeSfx);

				}

				if (PointSound != NULL)
				{
					UGameplayStatics::PlaySound2D(this, PointSound);
				}
			}

			else if (IsSemiStrike == true)
			{
				if (SpareSfx != NULL)
				{
					UGameplayStatics::PlaySound2D(this, SpareSfx);
				}
			}
		}
	}

	//If nothing out of the ordinary, draw this screen.
	else
	{
		RoundPointWidget = CreateWidget<UShowText>(GetWorld(), RoundPointWidgetClass);
		if (RoundPointWidget != NULL)
		{
			RoundPointWidget->AddToViewport();
			if (PointSound != NULL)
			{
				UGameplayStatics::PlaySound2D(this, PointSound);
			}
		}
	}

	//Play Epicfall SFX
	if (IsEpicFail == true)
	{
		if (EpicFailSfx != NULL)
		{
			UGameplayStatics::PlaySound2D(this, EpicFailSfx);
		}
	}
	
}

//Get Total Point
float AFastBowlingGameState::GetTotalPoint()
{
	return TotalPoint;
}

//Respawn Pin Actors. 
void AFastBowlingGameState::ReSpawnPins()
{
	//Pins are rebuilt only in integer rounds. The remaining pins are used in the intermediate rounds.
	if (GetRoundNumber() == 2.0f || GetRoundNumber() == 3.0f || GetRoundNumber() == 4.0f || GetRoundNumber() == 5.0f || GetRoundNumber() == 6.0f || GetRoundNumber() == 7.0f || GetRoundNumber() == 8.0f || GetRoundNumber() == 9.0f || GetRoundNumber() == 10.0f|| GetRoundNumber() == 10.6f)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APinActors::StaticClass(), FoundActors);

		for (AActor* Act : FoundActors)
		{
			//Find location Pin Actor Location
			APinActors* PinActor = Cast<APinActors>(Act);
			FVector SpawnLocation= PinActor->GetActorLocation();
			FRotator SpawnRotation= PinActor->GetActorRotation();

			//Destroy old pins
			PinActor->Destroy();

			FActorSpawnParameters TheParam; //Spawn Parameters

			TheParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; //-After all this time? -Always.

			//Spawn New Pins
			RespawnPinsL = GetWorld()->SpawnActor<APinActors>(CharacterClass, SpawnLocation, SpawnRotation, TheParam);

			IsStrike = false;
		}
	}
}

//Delay Respawn Pins
void AFastBowlingGameState::StartTimerDestroy()
{
	GetWorldTimerManager().SetTimer(DestroyTime, this, &AFastBowlingGameState::ReSpawnPins, DestroyandSpawnTimeAmmount, false);

}

//Delay Point Show
void AFastBowlingGameState::StartTimerforPointShower()
{
	GetWorldTimerManager().SetTimer(StartTime, this, &AFastBowlingGameState::PointShower, 3.0f, false);
	
}

//Draw Point on Screen
void AFastBowlingGameState::PointShower()
{
	if (HudWidget)
	{
		HudWidget->ShowPointonTable();
	}
}

//Call when game is over.
void AFastBowlingGameState::EndGame()
{
	if (GetRoundNumber() >= 10.7f)
	{
		//Draw End Screen Widget
		EndScreenWidget = CreateWidget< UUserWidget>(GetWorld(), EndScreen);
		if (EndScreenWidget!=NULL)
		{
			EndScreenWidget->AddToViewport();
		}
	}
}


//Simple countdown function. It works if the round break is false. It goes to sleep in situations such as after the shot.
void AFastBowlingGameState::GameTimer()
{
	if(RoundBreak==false)
	{ 

		if (Second != 0)
		{
			Second = Second - 1;
		}
	}

	
}


