//Gameplay Hud Screen. In-game screen.


#include "HudScreen.h"
#include "FastBowlingGameState.h"
#include "Kismet/GameplayStatics.h"

//Draw Point on Table
void UHudScreen::ShowPointonTable()
{
	AFastBowlingGameState* FGS = Cast<AFastBowlingGameState>(UGameplayStatics::GetGameState(GetWorld()));

	if (FGS)
	{
		if (FGS->RoundBreak)
		{
			if (FGS->GetRoundNumber() == 1)
			{
				//is strike?
				if (FGS->IsStrike == true)
				{
					StrikeRound1 = true;
					R1Point->SetText(FText::FromString(TEXT("X")));
				}

				//else?
				else
				{
					R1Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				
				Round1Score = FGS->GetRoundPoint();
			}

			if (FGS->GetRoundNumber() == 1.5f)
			{
				Round15Score = FGS->GetRoundPoint();

				if (FGS->IsSemiStrike)
				{
					PreviusRoundPoint = Totalpoinplus;
					SpareRound1 = true;
					R15Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					R15Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round15Score + Round1Score;
					R1TotalPoint1->SetText(FText::AsNumber(Totalpoinplus));
				}
					
			}

			if (FGS->GetRoundNumber() == 2)
			{
				//If Striked
				if (FGS->IsStrike == true)
				{
					StrikeRound2 = true;
					R2Point->SetText(FText::FromString(TEXT("X")));

					//If Previous Round Strike Has Been Made
					if (StrikeRound1 == true)
					{
						FirstClassTakePoint=true;
					}
				}

				else
				{
					R2Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				//Set Current Round Score 
				Round2Score = FGS->GetRoundPoint();

				//If Previous Round Spare Made
				if (SpareRound1==true)
				{
					Totalpoinplus = Round1Score + Round15Score + Round2Score+ Totalpoinplus;
					R1TotalPoint1->SetText(FText::AsNumber(Totalpoinplus));
				}

			}

			if (FGS->GetRoundNumber() == 2.5f)
			{
				//Set Current Round Score 
				Round25Score = FGS->GetRoundPoint();

				//If Strike is done, send the sum of the two lobes to R1Total
				if (StrikeRound1 == true && SpareRound1 == false)
				{
					Totalpoinplus = Round2Score + Round25Score + Round1Score;
					R1TotalPoint1->SetText(FText::AsNumber(Totalpoinplus));
				}

				//If Spare
				if (FGS->IsSemiStrike)
				{
					SpareRound2 = true;
					PreviusRoundPoint = Totalpoinplus;
					R25Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					//Draw Current Round Score on Screen
					R25Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round2Score + Round25Score + Totalpoinplus;
					R1TotalPoint2->SetText(FText::AsNumber(Totalpoinplus));
				}


			}

			if (FGS->GetRoundNumber() == 3)
			{
				
				if (FGS->IsStrike == true)
				{
					R3Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound3 = true;
					if (StrikeRound2 == true)
					{
						SecondClassTakePoint = true;
					}
				}

				else
				{
					R3Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				Round3Score = FGS->GetRoundPoint();

				if (FirstClassTakePoint == true)
				{
					Totalpoinplus = Round1Score + Round15Score + Round2Score + Round3Score+ Totalpoinplus;
					R1TotalPoint1->SetText(FText::AsNumber(Totalpoinplus));
				}


				
				if (SpareRound2 == true)
				{
					Totalpoinplus = Round2Score + Round25Score + Round3Score+ Totalpoinplus;
					R1TotalPoint2->SetText(FText::AsNumber(Totalpoinplus));
				}

			}

			if (FGS->GetRoundNumber() == 3.5f)
			{
				Round35Score = FGS->GetRoundPoint();

				if (StrikeRound2 == true && SpareRound2 == false)
				{
					Totalpoinplus = Round3Score + Round35Score + Round2Score+Totalpoinplus;
					R1TotalPoint2->SetText(FText::AsNumber(Totalpoinplus));
				}
		
				if (FGS->IsSemiStrike)
				{
					SpareRound3 = true;
					PreviusRoundPoint = Totalpoinplus;
					R35Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					R35Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round3Score + Round35Score + Totalpoinplus;
					R1TotalPoint3->SetText(FText::AsNumber(Totalpoinplus));
				}

			}

			if (FGS->GetRoundNumber() == 4)
			{
				if (FGS->IsStrike == true)
				{
					R4Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound4 = true;
					if (StrikeRound3 == true)
					{
						ThirdClassTakePoint = true;
					}
				}
				else
				{
					R4Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}
				Round4Score = FGS->GetRoundPoint();
				if (SecondClassTakePoint == true)
				{
					Totalpoinplus = Round2Score + Round25Score + Round3Score + Round4Score + Totalpoinplus;
					R1TotalPoint2->SetText(FText::AsNumber(Totalpoinplus));
				}

	
				if (SpareRound3 == true)
				{
					Totalpoinplus = Round3Score + Round35Score + Round4Score + Totalpoinplus;
					R1TotalPoint3->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 4.5f)
			{
				Round45Score = FGS->GetRoundPoint();

				if (StrikeRound3 == true && SpareRound3 == false)
				{
					Totalpoinplus = Round4Score + Round45Score + Round3Score+ Totalpoinplus;
					R1TotalPoint3->SetText(FText::AsNumber(Totalpoinplus));
				}
		
				if (FGS->IsSemiStrike)
				{
					SpareRound4 = true;
					PreviusRoundPoint = Totalpoinplus;
					R45Point->SetText(FText::FromString(TEXT("/")));
				}
				else
				{
					R45Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round4Score + Round45Score + Totalpoinplus;
					R1TotalPoint4->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 5)
			{
				if (FGS->IsStrike == true)
				{
					R5Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound5 = true;
					if (StrikeRound4 == true)
					{
						FourClassTakePoint = true;
					}
				}

				else
				{
					R5Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}
				Round5Score = FGS->GetRoundPoint();
				if (ThirdClassTakePoint == true)
				{
					Totalpoinplus = Round3Score + Round35Score + Round4Score + Round5Score + Totalpoinplus;
					R1TotalPoint3->SetText(FText::AsNumber(Totalpoinplus));
				}
		
				if (SpareRound4 == true)
				{
					Totalpoinplus = Round4Score + Round45Score + Round5Score+ Totalpoinplus;
					R1TotalPoint4->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 5.5f)
			{
				Round55Score = FGS->GetRoundPoint();

				if (StrikeRound4 == true && SpareRound4 == false)
				{
					Totalpoinplus = Round5Score + Round55Score + Round4Score+ Totalpoinplus;
					R1TotalPoint4->SetText(FText::AsNumber(Totalpoinplus));
			
				}
				
				if (FGS->IsSemiStrike)
				{
					SpareRound5 = true;
					PreviusRoundPoint = Totalpoinplus;
					R55Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					R55Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round5Score + Round55Score + Totalpoinplus;
					R1TotalPoint5->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 6)
			{
				if (FGS->IsStrike == true)
				{
					R6Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound6 = true;
					if (StrikeRound5 == true)
					{
						FiveClassTakePoint = true;
					}
				}

				else
				{
					R6Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}
				Round6Score = FGS->GetRoundPoint();
				if (FourClassTakePoint == true)
				{
					Totalpoinplus = Round4Score + Round45Score + Round5Score + Round6Score + Totalpoinplus;
					R1TotalPoint4->SetText(FText::AsNumber(Totalpoinplus));
				}
	
				
				if (SpareRound5 == true)
				{
					Totalpoinplus = Round5Score + Round55Score + Round6Score + Totalpoinplus;
					R1TotalPoint5->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 6.5f)
			{
				Round65Score = FGS->GetRoundPoint();
			


				if (StrikeRound5 == true && SpareRound5 == false)
				{
					Totalpoinplus = Round6Score + Round65Score + Round5Score+ Totalpoinplus;
					R1TotalPoint5->SetText(FText::AsNumber(Totalpoinplus));
				}

				if (FGS->IsSemiStrike)
				{
					SpareRound6 = true;
					PreviusRoundPoint = Totalpoinplus;
					R65Point->SetText(FText::FromString(TEXT("/")));
				}
				else
				{
					R65Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round6Score + Round65Score + Totalpoinplus;
					R1TotalPoint6->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 7)
			{
				if (FGS->IsStrike == true)
				{
					R7Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound7 = true;
					if (StrikeRound6 == true)
					{
						SixClassTakePoint = true;
					}
				}

				else
				{
					R7Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				Round7Score = FGS->GetRoundPoint();

				if (FiveClassTakePoint == true)
				{
					Totalpoinplus = Round5Score + Round55Score + Round6Score + Round7Score + Totalpoinplus;
					R1TotalPoint5->SetText(FText::AsNumber(Totalpoinplus));
				}
			
				if (SpareRound6 == true)
				{
					Totalpoinplus = Round6Score + Round65Score + Round7Score + Totalpoinplus;
					R1TotalPoint6->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 7.5f)
			{
			

				Round75Score= FGS->GetRoundPoint();

				if (StrikeRound6 == true && SpareRound6 == false)
				{
					Totalpoinplus = Round7Score + Round75Score + Round6Score+ Totalpoinplus;
					R1TotalPoint6->SetText(FText::AsNumber(Totalpoinplus));

				}

				if (FGS->IsSemiStrike)
				{
					SpareRound7 = true;
					PreviusRoundPoint = Totalpoinplus;
					R75Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					R75Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round7Score + Round75Score + Totalpoinplus;
					R1TotalPoint7->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 8)
			{
				if (FGS->IsStrike == true)
				{
					R8Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound8 = true;
					if (StrikeRound7 == true)
					{
						SevenClassTakePoint = true;
					}
				}

				else
				{
					R8Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				Round8Score = FGS->GetRoundPoint();

				if (SixClassTakePoint == true)
				{
					Totalpoinplus = Round6Score + Round65Score + Round7Score + Round8Score + Totalpoinplus;
					R1TotalPoint6->SetText(FText::AsNumber(Totalpoinplus));
				}
				
				if (SpareRound7 == true)
				{
					Totalpoinplus = Round7Score + Round75Score + Round8Score + Totalpoinplus;
					R1TotalPoint7->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 8.5f)
			{

				Round85Score = FGS->GetRoundPoint();

				if (StrikeRound7 == true && SpareRound7 == false)
				{
					Totalpoinplus = Round8Score + Round85Score + Round7Score+ Totalpoinplus;
					R1TotalPoint7->SetText(FText::AsNumber(Totalpoinplus));
				}

				if (FGS->IsSemiStrike)
				{
					SpareRound8 = true;
					PreviusRoundPoint = Totalpoinplus;
					R85Point->SetText(FText::FromString(TEXT("/")));
				}
				else
				{
					R85Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round8Score + Round85Score + Totalpoinplus;
					R1TotalPoint8->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 9)
			{
				if (FGS->IsStrike == true)
				{
					R9Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound9 = true;
					FGS->PreviousRoundNine = true;

					if (StrikeRound8 == true)
					{
						EightClassTakePoint = true;
					}
				}

				else
				{
					R9Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				Round9Score = FGS->GetRoundPoint();
				if (SevenClassTakePoint == true)
				{
					Totalpoinplus = Round7Score + Round75Score + Round8Score + Round9Score + Totalpoinplus;
					R1TotalPoint7->SetText(FText::AsNumber(Totalpoinplus));
				}
			
				if (SpareRound8 == true)
				{
					Totalpoinplus = Round8Score + Round85Score + Round9Score + Totalpoinplus;
					R1TotalPoint8->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 9.5f)
			{

				Round95Score = FGS->GetRoundPoint();

				if (StrikeRound8 == true && SpareRound8 == false)
				{
					Totalpoinplus = Round9Score + Round95Score + Round8Score+ Totalpoinplus;
					R1TotalPoint8->SetText(FText::AsNumber(Totalpoinplus));
				}

				if (FGS->IsSemiStrike)
				{
					SpareRound9 = true;
					PreviusRoundPoint = Totalpoinplus;
					FGS->PreviousRoundNine = true;
					R95Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					R95Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
					Totalpoinplus = Round9Score + Round95Score + Totalpoinplus;
					R1TotalPoint9->SetText(FText::AsNumber(Totalpoinplus));
					
				}
			}

			if (FGS->GetRoundNumber() == 10)
			{
				FGS->PreviousRoundNine = false;
				if (FGS->IsStrike == true)
				{
					R10Point->SetText(FText::FromString(TEXT("X")));
					StrikeRound10 = true;

					if (StrikeRound9 == true)
					{
						NineClassTakePoint = true;
					}
				}

				else
				{
					R10Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}

				Round10Score = FGS->GetRoundPoint();
				
				if (EightClassTakePoint == true)
				{
					Totalpoinplus = Round8Score + Round85Score + Round9Score + Round10Score + Totalpoinplus;
					R1TotalPoint8->SetText(FText::AsNumber(Totalpoinplus));
				}

				
				if (SpareRound9 == true)
				{
					Totalpoinplus = Round9Score + Round95Score + Round10Score + Totalpoinplus;
					R1TotalPoint9->SetText(FText::AsNumber(Totalpoinplus));
				}
			}

			if (FGS->GetRoundNumber() == 10.5f)
			{
				
				Round105Score = FGS->GetRoundPoint();
	

				if (StrikeRound9 == true && SpareRound9 == false)
				{
					Totalpoinplus = Round10Score + Round105Score + Round9Score+Totalpoinplus;
					R1TotalPoint9->SetText(FText::AsNumber(Totalpoinplus));
				}

				if (FGS->IsSemiStrike)
				{
					SpareRound10 = true;
					PreviusRoundPoint = Totalpoinplus;
					R105Point->SetText(FText::FromString(TEXT("/")));
				}

				else
				{
					Totalpoinplus = Round10Score + Round105Score + Totalpoinplus;
					R1TotalPoint10->SetText(FText::AsNumber(Totalpoinplus));
					R105Point->SetText(FText::AsNumber(FGS->GetRoundPoint()));
				}
			}

			if (FGS->BonusRound == true&& FGS->GetRoundNumber() == 10.6f)
			{
				FGS->BonusRound=false;
				FGS->DirectSetup = false;
				FGS->Gameover = true;
				// Set Round Score
				BonusRoundScore = FGS->GetRoundPoint();
				//If the 9th Round Score is to be written
				if (NineClassTakePoint == true)
				{
					//addition point
					Totalpoinplus = Round9Score + Round95Score + Round10Score + BonusRoundScore + Totalpoinplus;
					//Draw Point on Screen
					R1TotalPoint9->SetText(FText::AsNumber(Totalpoinplus));
				}

				// If Strike Is Made in the 10th Round
				if (StrikeRound10 == true)
				{
					//addition point
					Totalpoinplus = Round10Score  + BonusRoundScore + Totalpoinplus;
					//Draw Point on Screen
					R1TotalPoint10->SetText(FText::AsNumber(Totalpoinplus));
				}

				// If Spare Is Made in the 10th Round
				if (SpareRound10 == true)
				{
					//addition point
					Totalpoinplus = Round10Score + Round105Score + BonusRoundScore + Totalpoinplus;
					//Draw Point on Screen
					R1TotalPoint10->SetText(FText::AsNumber(Totalpoinplus));
				}

				Totalpoinplus = BonusRoundScore + Totalpoinplus;
				//Draw Bonus Round Score on the Screen
				R1TotalPointBonus->SetText(FText::AsNumber(Totalpoinplus));

			}
		}
	}
}
