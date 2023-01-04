//Dedected Box. Controls the ball crossing the line, starts calculating points. It manages many functions such as respawn.
#include "DedectedBox.h"
#include "FastBowlingGameState.h"
#include "Kismet/GameplayStatics.h"


ADedectedBox::ADedectedBox()
{
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Volume"));
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ADedectedBox::Beginoverlap);
	TriggerVolume->SetupAttachment(RootComponent);
}

//Respawn Player Character
void ADedectedBox::TimerRespawner()
{
	AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (TheGameState)
	{
		if (TheGameState->GetRoundNumber() < 11)
		{
			//if game timer zero, unpossess character and destroy uncontrolled ball.
			if (TheGameState->Second <= 0)
			{
				AFastBowlingCharacter* FBCC = Cast< AFastBowlingCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
				if (FBCC)
				{
					UGameplayStatics::GetPlayerController(GetWorld(), 0)->UnPossess();

					FBCC->Destroy();
				}
				PointCalculate();
				Respawn();
			}
		}

	}
}

void ADedectedBox::BeginPlay()
{
	Super::BeginPlay();

	//Play Round Start SFX.
	if (StartSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, StartSound, GetActorLocation());
	}

	//Every Second Control TimerRespawner
	GetWorldTimerManager().SetTimer(TimeController, this, &ADedectedBox::TimerRespawner, 1.0f, true);
}


void ADedectedBox::Beginoverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (TheGameState)
	{
		if(TheGameState->RoundBreak==false)
		{ 
			if(AFastBowlingCharacter* FBC=Cast< AFastBowlingCharacter>(OtherActor))
			{
				if (FBC)
				{
					//if ball overlap the dedectedbox, unpossess character. 
					UGameplayStatics::GetPlayerController(GetWorld(), 0)->UnPossess();

					//Delay Respawn.
					GetWorldTimerManager().SetTimer(FunctionTimer, this, &ADedectedBox::Respawn, SpawnTimeDelay, false);

					//Delay Point Calculate
					GetWorldTimerManager().SetTimer(FunctionTimerSecond, this, &ADedectedBox::PointCalculate, PCTimeDelay, false);

			
					if (TheGameState)
					{
						//Enable Round break.
						TheGameState->RoundBreak = true;

						TheGameState->StartTimerforPointShower();
					}

			
				}

				//Destroy uncontrolled ball.
				FBC->Destroyer();
			}
		}
	}
}

//Respawn Function
void ADedectedBox::Respawn()
{
	AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (TheGameState)
	{
		//
		TheGameState->StartTimerDestroy();
	
		//If a strike or spare was made in the 10th round, +1 more shot is given. "BonusRound" represents that.
		if (TheGameState->BonusRound == false)
		{

			//if Strike, set round number int(+1) value.
			if (TheGameState->IsStrike)
			{
				TheGameState->SetRoundNumber(1);

			}

			//else, set round number float (0.5f) value.
			else
			{
				TheGameState->SetRoundNumber(0.5f);

			}
		}

		//if the "BonusRound" is active the new round number will be (10.6f).
		else
		{
			TheGameState->DirectSetup = true;
			TheGameState->SetRoundNumber(10.6f);
		}

			//Reset spawn timer.
			GetWorldTimerManager().ClearTimer(FunctionTimer);
			FActorSpawnParameters TheParam;

		
			TheParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			//Spawn ball character
			AFastBowlingCharacter* RespawnCharacter = GetWorld()->SpawnActor<AFastBowlingCharacter>(CharacterClass, SpawnLocation, SpawnRotation, TheParam);

			if (RespawnCharacter)
			{
				//Control ball character
				UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(RespawnCharacter);
				//Set Game Time
				TheGameState->Second = GameTime;
				//Empty Array
				FoundActors.Empty();
			}

			
			//Roundbreak returns the true as soon as the ball enters the detection box. For the new round,"RoundBreak" returns it false.
			TheGameState->RoundBreak = false;


			//For the new round, returns it false if a strike was made in the previous round.
			TheGameState->IsStrike = false;

			
			TheGameState->IsSemiStrike = false;

			
			TheGameState->IsEpicFail = false;

			//Deletes the score of pins fell in the previous round in the second round.
			TheGameState->RoundPointDeleter();

			UGameplayStatics::GetAllActorsOfClass(GetWorld(), APinActors::StaticClass(), FoundActorsSecond);

			for (AActor* PAct : FoundActorsSecond)
			{
				APinActors* PinActor = Cast<APinActors>(PAct);

				//Find points not included.
				PinActor->StartTimerforPointExemptDedecter();
			
			}

			if (StartSound != NULL)
			{
			
				UGameplayStatics::PlaySoundAtLocation(this, StartSound, GetActorLocation());
			}
	}
}

//Point Calculator Function.
void ADedectedBox::PointCalculate()
{
	//Found in world Pin Actor.
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APinActors::StaticClass(), FoundActors);

		for (AActor* Act : FoundActors)
		{
			APinActors* PinActor = Cast<APinActors>(Act);

			//Call PointCalculator function in PinActor class. This function calculate the point.
				if (PinActor)
				{
					PinActor->PointCalculator();
				}

			AFastBowlingGameState* TheGameState = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));

				if (TheGameState)
				{
					//Draw point text on the screen.
					TheGameState->AddWidgetText();
				}
		}
}
