//Pin Actor.


#include "PinActors.h"
#include "Kismet/GameplayStatics.h"
#include "FastBowlingCharacter.h"
#include "FastBowlingGameState.h"

// Sets default values
APinActors::APinActors()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APinActors::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APinActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	StrikeDedecter();

}

//Point Calculator Function
void APinActors::PointCalculator()
{
	AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));
	
	if (TheGameState)
	{
		//Call if round number is integer
		if (TheGameState->GetRoundNumber() != 1.5f || TheGameState->GetRoundNumber() != 2.5f || TheGameState->GetRoundNumber() != 3.5f || TheGameState->GetRoundNumber() != 4.5f
			|| TheGameState->GetRoundNumber() != 5.5f || TheGameState->GetRoundNumber() != 6.5f|| TheGameState->GetRoundNumber() != 7.5f || TheGameState->GetRoundNumber() != 8.5f ||
			TheGameState->GetRoundNumber() != 9.5f || TheGameState->GetRoundNumber() != 10.5f)

		{
			//Sets Point 
			if (FallR1==true && exemptFallR1 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			 if (FallR2 == true && exemptFallR2 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR3 == true && exemptFallR3 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR4 == true && exemptFallR4 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR5 == true && exemptFallR5 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR6 == true && exemptFallR6 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR7 == true && exemptFallR7 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR8 == true && exemptFallR8 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR9 == true && exemptFallR9 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 if (FallR10 == true && exemptFallR10 == false)
				{
					TheGameState->SetRoundPoint(1);
				}

			 //Fail...
			 if (FallR1 == false && FallR2 == false && FallR3 == false && FallR4 == false && FallR5 == false && 
				 FallR6 == false && FallR7 == false && FallR8 == false && FallR9 == false && FallR10 == false)
			 {
				 TheGameState->IsEpicFail = true;
			 }


			 
			 //We do not include knocked down pins in the previous round in scoring in this round. So set round return 0.
			 if (FallR1 == true && exemptFallR1 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR2 == true && exemptFallR2 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR3 == true && exemptFallR3 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR4 == true && exemptFallR4 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR5 == true && exemptFallR5 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR6 == true && exemptFallR6 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR7 == true && exemptFallR7 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR8 == true && exemptFallR8 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR9 == true && exemptFallR9 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

			 if (FallR10 == true && exemptFallR10 == true)
			 {
				 TheGameState->SetRoundPoint(0);
			 }

		}

		//else, round number is float
		else
		{

			if (FallR1 == true && exemptFallR1 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR2 == true && exemptFallR2 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR3 == true && exemptFallR3 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR4 == true && exemptFallR4 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR5 == true && exemptFallR5 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR6 == true && exemptFallR6 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR7 == true && exemptFallR7 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR8 == true && exemptFallR8 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR9 == true && exemptFallR9 == false)
			{
				TheGameState->SetRoundPoint(1);
			}

			if (FallR10 == true && exemptFallR10 == false)
			{
				TheGameState->SetRoundPoint(1);
			}


			//We do not include knocked down pins in the previous round in scoring in this round. So set round return 0.
			if (FallR1 == true && exemptFallR1 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR2 == true && exemptFallR2 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR3 == true && exemptFallR3 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR4 == true && exemptFallR4 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR5 == true && exemptFallR5 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR6 == true && exemptFallR6 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR7 == true && exemptFallR7 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR8 == true && exemptFallR8 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR9 == true && exemptFallR9 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			if (FallR10 == true && exemptFallR10 == true)
			{
				TheGameState->SetRoundPoint(0);
			}

			//Fail...
			 if (FallR1 == false && FallR2 == false && FallR3 == false && FallR4 == false && FallR5 == false && FallR6 == false && FallR7 == false && FallR8 == false && FallR9 == false && FallR10 == false)
			 {
				 TheGameState->IsEpicFail = true;
			 }

		}
			
	}
}

//Point Exempt Creater. While calculating the points of newly fall pins in the second shots, the previous dropped pins are exempted.
void APinActors::PointExemptDedecter()
{
	AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (TheGameState)
	{
		//We only need the exempt function in float rounds.
		if (TheGameState->GetRoundNumber() == 1.5f || TheGameState->GetRoundNumber() == 2.5f || TheGameState->GetRoundNumber() == 3.5f || TheGameState->GetRoundNumber() == 4.5f
			|| TheGameState->GetRoundNumber() == 5.5f || TheGameState->GetRoundNumber() == 6.5f || TheGameState->GetRoundNumber() == 7.5f || TheGameState->GetRoundNumber() == 8.5f ||
			TheGameState->GetRoundNumber() == 9.5f || TheGameState->GetRoundNumber() == 10.5f)
		{

			if (FallR1)
			{
				exemptFallR1 = true;
			}

			 if (FallR2)
			{
				exemptFallR2 = true;
			}

			 if (FallR3)
			{
				exemptFallR3 = true;
			}

			 if (FallR4)
			{
				exemptFallR4 = true;
			}

			 if (FallR5)
			{
				exemptFallR5 = true;
			}

			 if (FallR6)
			{
				exemptFallR6 = true;
			}

			 if (FallR7)
			{
				exemptFallR7 = true;
			}

			 if (FallR8)
			{
				exemptFallR8 = true;
			}

			 if (FallR9)
			{
				exemptFallR9 = true;
			}

			 if (FallR10)
			{
				exemptFallR10 = true;
			}
		}
	}
}

//Strike Dedecter
void APinActors::StrikeDedecter()
{
	AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (TheGameState)
	{
		//Strike only happens in int rounds.
		if (TheGameState->GetRoundNumber() == 1 || TheGameState->GetRoundNumber() == 2 || TheGameState->GetRoundNumber() == 3 || TheGameState->GetRoundNumber() == 4 ||
			TheGameState->GetRoundNumber() == 5 || TheGameState->GetRoundNumber() == 6 || TheGameState->GetRoundNumber() == 7 || TheGameState->GetRoundNumber() == 8 ||
			TheGameState->GetRoundNumber() == 9 || TheGameState->GetRoundNumber() == 10|| TheGameState->BonusRound==true)
		{
			if (FallR1 && FallR2 && FallR3 && FallR4 && FallR5 && FallR6 && FallR7 && FallR8 && FallR9 && FallR10)
			{

				TheGameState->IsStrike = true;
				if (TheGameState->GetRoundNumber() == 10&& TheGameState->IsStrike ==true&& TheGameState->IsSemiStrike == false)
				{
					if (TheGameState->PreviousRoundNine == false)
					{

						if (TheGameState->GetRoundNumber() !=10.6)
						{
							TheGameState->BonusRound = true;
						}

					}
					
				}
			}
		}

		//if not, it will be spare.
		else	
		{

				if (FallR1 && FallR2 && FallR3 && FallR4 && FallR5 && FallR6 && FallR7 && FallR8 && FallR9 && FallR10)
				{
					if (TheGameState->BonusRound == false)
					{
						TheGameState->IsSemiStrike = true;
						if (TheGameState->GetRoundNumber() == 10.5 && TheGameState->IsSemiStrike == true)
						{
							TheGameState->BonusRound = true;
						}
					}

				}
			
		}
	}
}

//Delay Point Exempt
void APinActors::StartTimerforPointExemptDedecter()
{
	GetWorldTimerManager().SetTimer(TimerStarter, this, &APinActors::PointExemptDedecter, SpawnTimeDelay, false);
}

void APinActors::HitSFXTimer()
{
	GetWorldTimerManager().SetTimer(TimerStarterForHitSFX, this, &APinActors::HitSFX, SpawnTimeDelay, false);
}

void APinActors::HitSFX()
{
	//Play fall sfx
		
		if (FallR1 == true && exemptFallR1 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}
			
		}

		else if (FallR2 == true && exemptFallR2 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR3 == true && exemptFallR3 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR4 == true && exemptFallR4 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR5 == true && exemptFallR5 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR6 == true && exemptFallR6 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR7 == true && exemptFallR7 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR8 == true && exemptFallR8 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR9 == true && exemptFallR9 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}

		else if (FallR10 == true && exemptFallR10 == false)
		{
			if (FallSFXCue != NULL)
			{
				UGameplayStatics::PlaySound2D(this, FallSFXCue);
			}

		}
}


