// Selecting event Screen.


#include "WidgetSelectEvent.h"
#include "Kismet/GameplayStatics.h"
#include "FastBowlPlayerController.h"

void UWidgetSelectEvent::NativeConstruct()
{
	Super::NativeConstruct();

	//Bind Buttons
	ButtonFast->OnClicked.AddDynamic(this, &UWidgetSelectEvent::ClickFastEvent);
	ButtonMagic->OnClicked.AddDynamic(this, &UWidgetSelectEvent::ClickMagicEvent);
	ButtonSilver->OnClicked.AddDynamic(this, &UWidgetSelectEvent::ClickSilverTextHider);
	ButtonDiamond->OnClicked.AddDynamic(this, &UWidgetSelectEvent::ClickDiamondEvent);
	ButtonGold->OnClicked.AddDynamic(this, &UWidgetSelectEvent::ClickGoldEvent);

}


void UWidgetSelectEvent::NativeTick(const FGeometry& MyGeometry, float DeltaSecond)
{
	Super::NativeTick(MyGeometry, DeltaSecond);

	//Control Unlocked Events in every frame
	UnlockEventController();

}

//Control Unlocked Events
void UWidgetSelectEvent::UnlockEventController()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast< AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	//if lock event
	if (FastBowlPlayerController->fastball == false)
	{

		if (FastBowlPlayerController->GetLevelSystem() >= 5)								//If the target level has been reached
		{
			FastIfLevel->SetVisibility(ESlateVisibility::Hidden);							//Level Message Visibility
			FastImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Image Opacity Color
			FastTitle->SetColorAndOpacity(FLinearColor(1.0f,0.344081f,0.814915f,1.0f));		//Title Color
			StatusFast->SetVisibility(ESlateVisibility::Hidden);							//Status message visibility
			StatusFast->SetText(FText::FromString(TEXT("")));								// Status Message
			Fast->SetBrushColor((FLinearColor::Blue * 100.0f));								//Color bar indicating whether the event is active.	
		}

		else
		{
			FastIfLevel->SetVisibility(ESlateVisibility::Visible);											//Level Message Visibility
			FastIfLevel->SetColorAndOpacity(FSlateColor(FLinearColor::White));								//Level Message Color and Opacity
			FastImage->SetColorAndOpacity(FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f));				//Image Opacity Color
			FastTitle->SetColorAndOpacity(FLinearColor::Gray*100.0f);										//Title Color
			StatusFast->SetText(FText::FromString(TEXT("Unlock")));											//Status Message
			StatusFast->SetVisibility(ESlateVisibility::Visible);											//Status message visibility
			Fast->SetBrushColor((FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f)));						//Color bar indicating whether the event is active.		
		}

		if (FastBowlPlayerController->GetCoin() >= 350.0f)
		{
			FastIf->SetVisibility(ESlateVisibility::Hidden);													//Required level Text Visibility
			FastImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));								//Set Event Image Color and Alpha
			FastTitle->SetColorAndOpacity(FLinearColor(1.0f, 0.344081f, 0.814915f, 1.0f));
		}

		else
		{
			FastIf->SetVisibility(ESlateVisibility::Visible);													//Required level Text Visibility
			FastIf->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));								//Required level Text Color
			FastImage->SetColorAndOpacity(FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f));
			FastTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);											//Set Title Color
			
		}
		
	}

	//if unlock event
	else
	{
		FastIfLevel->SetVisibility(ESlateVisibility::Hidden);							//Hide Level Warning Text 
		FastIf->SetVisibility(ESlateVisibility::Hidden);								//Required level Text Visibility
		FastImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set color and opacity
		FastTitle->SetColorAndOpacity(FLinearColor::Green*100.0f);						//Set active event text color
		StatusFast->SetVisibility(ESlateVisibility::Visible);							//Visible Event available text
		StatusFast->SetText(FText::FromString(TEXT("Active Event")));					//Set Status Text
		Fast->SetBrushColor((FLinearColor::Green * 100.0f));							//Set Image Select Color.(Green is preferred).

		//Set Coin Ammount
		FastBowlPlayerController->Point1 = 7.5f;
		FastBowlPlayerController->Point2 = 7.5f;
		FastBowlPlayerController->Point3 = 7.5f;
		FastBowlPlayerController->Point4 = 7.5f;
		FastBowlPlayerController->Point5 = 7.5f;
		FastBowlPlayerController->Point6 = 7.5f;
		FastBowlPlayerController->Point7 = 7.5f;
		FastBowlPlayerController->Point8 = 7.5f;
		FastBowlPlayerController->Point9 = 37.5f;
		FastBowlPlayerController->PointSpare = 75.0f;
		FastBowlPlayerController->Point10 = 150.0f;

		//Set Total Point
		FastBowlPlayerController->TotalPoint1 = 15.0f;
		FastBowlPlayerController->TotalPoint2 = 15.0f;
		FastBowlPlayerController->TotalPoint3 = 15.0f;
		FastBowlPlayerController->TotalPoint4 = 15.0f;
		FastBowlPlayerController->TotalPoint5 = 15.0f;
		FastBowlPlayerController->TotalPoint6 = 15.0f;
		FastBowlPlayerController->TotalPoint7 = 15.0f;
		FastBowlPlayerController->TotalPoint8 = 15.0f;
		FastBowlPlayerController->TotalPoint9 = 45.0f;
		FastBowlPlayerController->TotalPointSpare = 75.0f;
		FastBowlPlayerController->TotalPoint10 = 150.0f;
	}

	//if lock event
	if (FastBowlPlayerController->magicball == false)
	{
		if (FastBowlPlayerController->GetLevelSystem() >= 10)								//If the target level has been reached
		{
			MagicIfLevel->SetVisibility(ESlateVisibility::Hidden);							//Level Message Visibility
			MagicImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Image Opacity Color
			MagicTitle->SetColorAndOpacity(FLinearColor(0.327654f, 0.24906f, 1.0f, 1.0f));	//Title Color
			StatusMagic->SetVisibility(ESlateVisibility::Hidden);							//Status message visibility
			StatusMagic->SetText(FText::FromString(TEXT("")));								// Status Message
			Magic->SetBrushColor((FLinearColor::Blue * 100.0f));							//Color bar indicating whether the event is active.	

		}

		else
		{
			MagicIfLevel->SetVisibility(ESlateVisibility::Visible);										//Level Message Visibility		
			MagicIfLevel->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));				//Level Message Color
			MagicImage->SetColorAndOpacity(FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f));		//Event Image Opacity and Color
			MagicTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);								//Title Color
			StatusMagic->SetText(FText::FromString(TEXT("Unlock")));									//Status Message
			StatusMagic->SetVisibility(ESlateVisibility::Visible);										//Status message visibility
			Magic->SetBrushColor((FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f)));				//Color bar indicating whether the event is active.	
		}

		if (FastBowlPlayerController->GetCoin() >= 1000)
		{
			MagicIf->SetVisibility(ESlateVisibility::Hidden);											//Required level Text Visibility
			MagicTitle->SetColorAndOpacity(FLinearColor(0.327654f, 0.24906f, 1.0f, 1.0f));
		}

		else
		{
			MagicIf->SetVisibility(ESlateVisibility::Visible);											//Required level Text Visibility
			MagicIf->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));
			MagicTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);								//Set Title Color

		}
		FastBowlPlayerController->Point2 = 5.0f;
	}

	//if unlock event
	else
	{
		MagicIfLevel->SetVisibility(ESlateVisibility::Hidden);							//Hide Level Warning Text 
		MagicIf->SetVisibility(ESlateVisibility::Hidden);								//Required level Text Visibility
		MagicImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set color and opacity
		MagicTitle->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set active event text color
		StatusMagic->SetVisibility(ESlateVisibility::Visible);							//Visible Event available text
		StatusMagic->SetText(FText::FromString(TEXT("Active Event")));					//Set Status Text
		Magic->SetBrushColor((FLinearColor::Green * 100.0f));							//Set Image Select Color.(Green is preferred).

		//Set Coin Ammount
		FastBowlPlayerController->Point1 = 10.0f;
		FastBowlPlayerController->Point2 = 10.0f;
		FastBowlPlayerController->Point3 = 10.0f;
		FastBowlPlayerController->Point4 = 10.0f;
		FastBowlPlayerController->Point5 = 10.0f;
		FastBowlPlayerController->Point6 = 10.0f;
		FastBowlPlayerController->Point7 = 10.0f;
		FastBowlPlayerController->Point8 = 10.0f;
		FastBowlPlayerController->Point9 = 50.0f;
		FastBowlPlayerController->PointSpare = 100.0f;
		FastBowlPlayerController->Point10 = 200.0f;

		//Set Total Point
		FastBowlPlayerController->TotalPoint1 = 20.0f;
		FastBowlPlayerController->TotalPoint2 = 20.0f;
		FastBowlPlayerController->TotalPoint3 = 20.0f;
		FastBowlPlayerController->TotalPoint4 = 20.0f;
		FastBowlPlayerController->TotalPoint5 = 20.0f;
		FastBowlPlayerController->TotalPoint6 = 20.0f;
		FastBowlPlayerController->TotalPoint7 = 20.0f;
		FastBowlPlayerController->TotalPoint8 = 20.0f;
		FastBowlPlayerController->TotalPoint9 = 60.0f;
		FastBowlPlayerController->TotalPointSpare = 100.0f;
		FastBowlPlayerController->TotalPoint10 = 200.0f;
	}

	//if lock event
	if (FastBowlPlayerController->silverball == false)							
	{
		FastBowlPlayerController->Point3 = 5.0f;											
		if (FastBowlPlayerController->GetLevelSystem() >= 20)											//If the target level has been reached
		{
			SilverIfLevel->SetVisibility(ESlateVisibility::Hidden);										//Level Message Visibility
			SilverImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));						//Image Opacity Color
			SilverTitle->SetColorAndOpacity(FLinearColor(0.128318, 0.84375, 0.211913f, 1.0f));			//Title Color
			StatusSilver->SetVisibility(ESlateVisibility::Hidden);										//Status message visibility
			StatusSilver->SetText(FText::FromString(TEXT("")));											//Status Message
			Silver->SetBrushColor((FLinearColor::Blue * 100.0f));										//Color bar indicating whether the event is active.			

		}

		else
		{
			SilverIfLevel->SetVisibility(ESlateVisibility::Visible);									//Level Message Visibility	
			SilverIfLevel->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));				//Level Message Color
			SilverImage->SetColorAndOpacity(FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f));		//Event Image Opacity and Color
			SilverTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);								//Title Color
			StatusSilver->SetText(FText::FromString(TEXT("Unlock")));									//Status Message
			StatusSilver->SetVisibility(ESlateVisibility::Visible);										//Status message visibility
			Silver->SetBrushColor((FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f)));				//Color bar indicating whether the event is active.	
		}

		if (FastBowlPlayerController->GetCoin() >= 4000)
		{
			SilverIf->SetVisibility(ESlateVisibility::Hidden);										//Required level Text Visibility		
			SilverTitle->SetColorAndOpacity(FLinearColor(0.128318f, 0.84375f, 0.211913f, 1.0f));
		}

		else
		{
			SilverIf->SetVisibility(ESlateVisibility::Visible);										//Required level Text Visibility
			SilverIf->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));
			SilverTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);							//Set Title Color
		}

	}

	//if unlock event
	else
	{
		SilverIfLevel->SetVisibility(ESlateVisibility::Hidden);							//Hide Level Warning Text 
		SilverIf->SetVisibility(ESlateVisibility::Hidden);								//Required level Text Visibility
		SilverImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set color and opacity
		SilverTitle->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set active event text color
		StatusSilver->SetVisibility(ESlateVisibility::Visible);							//Visible Event available text
		StatusSilver->SetText(FText::FromString(TEXT("Active Event")));					//Set Status Text
		Silver->SetBrushColor((FLinearColor::Green * 100.0f));							//Set Image Select Color.(Green is preferred).

		//Set Coin Ammount
		FastBowlPlayerController->Point1 = 15.0f;
		FastBowlPlayerController->Point2 = 15.0f;
		FastBowlPlayerController->Point3 = 15.0f;
		FastBowlPlayerController->Point4 = 15.0f;
		FastBowlPlayerController->Point5 = 15.0f;
		FastBowlPlayerController->Point6 = 15.0f;
		FastBowlPlayerController->Point7 = 15.0f;
		FastBowlPlayerController->Point8 = 15.0f;
		FastBowlPlayerController->Point9 = 75.0f;
		FastBowlPlayerController->PointSpare = 150.0f;
		FastBowlPlayerController->Point10 = 300.0f;

		//Set Total Point
		FastBowlPlayerController->TotalPoint1 = 30.0f;
		FastBowlPlayerController->TotalPoint2 = 30.0f;
		FastBowlPlayerController->TotalPoint3 = 30.0f;
		FastBowlPlayerController->TotalPoint4 = 30.0f;
		FastBowlPlayerController->TotalPoint5 = 30.0f;
		FastBowlPlayerController->TotalPoint6 = 30.0f;
		FastBowlPlayerController->TotalPoint7 = 30.0f;
		FastBowlPlayerController->TotalPoint8 = 30.0f;
		FastBowlPlayerController->TotalPoint9 = 90.0f;
		FastBowlPlayerController->TotalPointSpare = 150.0f;
		FastBowlPlayerController->TotalPoint10 = 300.0f;
	}

	
	//if lock event
	if (FastBowlPlayerController->Diamondball == false)
	{
		if (FastBowlPlayerController->GetLevelSystem() >= 30)										//If the target level has been reached
		{
			DiamondIfLevel->SetVisibility(ESlateVisibility::Hidden);								//Level Message Visibility
			DiamondImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));					//Image Opacity Color
			DiamondTitle->SetColorAndOpacity(FLinearColor(0.351149f, 1.0f, 0.940224f, 1.0f));		//Title Color
			StatusDiamond->SetVisibility(ESlateVisibility::Hidden);									//Status message visibility
			StatusDiamond->SetText(FText::FromString(TEXT("")));									//Status Message
			Diamond->SetBrushColor((FLinearColor::Blue * 100.0f));									//Color bar indicating whether the event is active.				

		}

		else
		{

			DiamondIfLevel->SetVisibility(ESlateVisibility::Visible);									//Level Message Visibility
			DiamondIfLevel->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));				//Level Message Color and Opacity
			DiamondImage->SetColorAndOpacity(FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f));		//Image Opacity Color
			DiamondTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);								//Title Color
			StatusDiamond->SetText(FText::FromString(TEXT("Unlock")));									//Status Message
			StatusDiamond->SetVisibility(ESlateVisibility::Visible);									//Status message visibility
			Diamond->SetBrushColor((FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f)));				//Color bar indicating whether the event is active.	
		}	

		if (FastBowlPlayerController->GetCoin() >= 15000)
		{
			DiamondIf->SetVisibility(ESlateVisibility::Hidden);											//Required level Text Visibility
			DiamondTitle->SetColorAndOpacity(FLinearColor(0.351149f, 1.0f, 0.940224f, 1.0f));			//Set Title Color
		}

		else
		{
			DiamondIf->SetVisibility(ESlateVisibility::Visible);						//Required level Text Visibility
			DiamondIf->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));	//Required level Text Color and Alpha
			DiamondTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);				//Set Title Color

		}

	}

	//if unlock event
	else
	{
		DiamondIfLevel->SetVisibility(ESlateVisibility::Hidden);					//Hide Level Warning Text 
		DiamondIf->SetVisibility(ESlateVisibility::Hidden);							//Required level Text Visibility						
		DiamondImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set colorand opacity
		DiamondTitle->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set active event text color
		StatusDiamond->SetVisibility(ESlateVisibility::Visible);					//Visible Event available text
		StatusDiamond->SetText(FText::FromString(TEXT("Active Event")));			//Set Status Text
		Diamond->SetBrushColor((FLinearColor::Green * 100.0f));						//Set Image Select Color.(Green is preferred).

		//Set Coin Ammount
		FastBowlPlayerController->Point1 = 20.0f;
		FastBowlPlayerController->Point2 = 20.0f;
		FastBowlPlayerController->Point3 = 20.0f;
		FastBowlPlayerController->Point4 = 20.0f;
		FastBowlPlayerController->Point5 = 20.0f;
		FastBowlPlayerController->Point6 = 20.0f;
		FastBowlPlayerController->Point7 = 20.0f;
		FastBowlPlayerController->Point8 = 20.0f;
		FastBowlPlayerController->Point9 = 100.0f;
		FastBowlPlayerController->PointSpare = 200.0f;
		FastBowlPlayerController->Point10 = 400.0f;

		//Set Total Point
		FastBowlPlayerController->TotalPoint1 = 40.0f;
		FastBowlPlayerController->TotalPoint2 = 40.0f;
		FastBowlPlayerController->TotalPoint3 = 40.0f;
		FastBowlPlayerController->TotalPoint4 = 40.0f;
		FastBowlPlayerController->TotalPoint5 = 40.0f;
		FastBowlPlayerController->TotalPoint6 = 40.0f;
		FastBowlPlayerController->TotalPoint7 = 40.0f;
		FastBowlPlayerController->TotalPoint8 = 40.0f;
		FastBowlPlayerController->TotalPoint9 = 120.0f;
		FastBowlPlayerController->TotalPointSpare = 200.0f;
		FastBowlPlayerController->TotalPoint10 = 400.0f;
	}
	
	//if lock event
	if (FastBowlPlayerController->goldenball == false)
	{
		if (FastBowlPlayerController->GetLevelSystem() >= 40)									//If the target level has been reached
		{
			GoldIfLevel->SetVisibility(ESlateVisibility::Hidden);								//Level Message Visibility
			GoldImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Image Opacity Color
			GoldTitle->SetColorAndOpacity(FLinearColor(1.0f, 0.952941f, 0.105882f, 1.0f));		//Title Color
			StatusGold->SetVisibility(ESlateVisibility::Hidden);								//Status message visibility
			StatusGold->SetText(FText::FromString(TEXT("")));									//Status Message
			Gold->SetBrushColor((FLinearColor::Blue * 100.0f));			                        //Color bar indicating whether the event is active.							
		}



		else
		{
			GoldIfLevel->SetVisibility(ESlateVisibility::Visible);									//Level Message Visibility
			GoldIfLevel->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));				//Level Message Color and Opacity
			GoldImage->SetColorAndOpacity(FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f));		//Image Opacity Color
			GoldTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);								//Title Color
			StatusGold->SetText(FText::FromString(TEXT("Unlock")));									//Status Message
			StatusGold->SetVisibility(ESlateVisibility::Visible);									//Status message visibility
			Gold->SetBrushColor((FLinearColor(0.145833f, 0.145833f, 0.145833f, 1.0f)));				//Color bar indicating whether the event is active.		
		}

		if (FastBowlPlayerController->GetCoin() >= 25000)
		{
			GoldIf->SetVisibility(ESlateVisibility::Hidden);								//Required condition message visibility. 
			GoldTitle->SetColorAndOpacity(FLinearColor(1.0f, 0.952941f, 0.105882f, 1.0f));  //Set Title Color
		}

		else
		{
			GoldIf->SetVisibility(ESlateVisibility::Visible);								//Required condition message visibility.
			GoldIf->SetColorAndOpacity(FSlateColor(FLinearColor::White * 100.0f));			////Set Required condition message Color.
			GoldTitle->SetColorAndOpacity(FLinearColor::Gray * 100.0f);						//Set Title Color
		}

	}

	//if unlock event
	else
	{
		GoldIfLevel->SetVisibility(ESlateVisibility::Hidden);						//Hide Level Warning Text 
		GoldIf->SetVisibility(ESlateVisibility::Hidden);							//Required level Text Visibility
		GoldImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set color and opacity
		GoldTitle->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set active event text color
		StatusGold->SetVisibility(ESlateVisibility::Visible);						//Visible Event available text
		StatusGold->SetText(FText::FromString(TEXT("Active Event")));				//Set Status Text
		Gold->SetBrushColor((FLinearColor::Green * 100.0f));						//Set Image Select Color.(Green is preferred).

		//Set Coin Point
		FastBowlPlayerController->Point1 = 25.0f;
		FastBowlPlayerController->Point2 = 25.0f;
		FastBowlPlayerController->Point3 = 25.0f;
		FastBowlPlayerController->Point4 = 25.0f;
		FastBowlPlayerController->Point5 = 25.0f;
		FastBowlPlayerController->Point6 = 25.0f;
		FastBowlPlayerController->Point7 = 25.0f;
		FastBowlPlayerController->Point8 = 25.0f;
		FastBowlPlayerController->Point9 = 125.0f;
		FastBowlPlayerController->PointSpare = 250.0f;
		FastBowlPlayerController->Point10 = 500.0f;

		//Set Total Point
		FastBowlPlayerController->TotalPoint1 = 50.0f;
		FastBowlPlayerController->TotalPoint2 = 50.0f;
		FastBowlPlayerController->TotalPoint3 = 50.0f;
		FastBowlPlayerController->TotalPoint4 = 50.0f;
		FastBowlPlayerController->TotalPoint5 = 50.0f;
		FastBowlPlayerController->TotalPoint6 = 50.0f;
		FastBowlPlayerController->TotalPoint7 = 50.0f;
		FastBowlPlayerController->TotalPoint8 = 50.0f;
		FastBowlPlayerController->TotalPoint9 = 150.0f;
		FastBowlPlayerController->TotalPointSpare = 250.0f;
		FastBowlPlayerController->TotalPoint10 = 500.0f;
	}
}






void UWidgetSelectEvent::ClickFastEvent()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast< AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController)
	{
		if (FastBowlPlayerController->GetLevelSystem()>5&& FastBowlPlayerController->GetCoin()>= FastBallCoinValue
			&& FastBowlPlayerController->fastball ==false )
		{
			//Set Event Boolean
			FastBowlPlayerController->fastball = true;
			FastBowlPlayerController->magicball = false;
			FastBowlPlayerController->silverball = false;
			FastBowlPlayerController->Diamondball = false;
			FastBowlPlayerController->goldenball = false;
			FastBowlPlayerController->IsEventBegin = false; 
			Fast->SetBrushColor((FLinearColor::Green * 100.0f));  //Active Event Border Color

			FastBowlPlayerController->SaveEvent();//Save Event

		FastTitle->SetColorAndOpacity(FSlateColor(FLinearColor::Green * 100.0f));

		FastBowlPlayerController->Minute = 4; 	//Set Event Minute
		FastBowlPlayerController->Second = 59; 	//Set Event Second
		FastBowlPlayerController->StartTimer(); //Start Timer


		float NewValue;
		NewValue = FastBowlPlayerController->GetCoin() - FastBallCoinValue;  //Calculate new Coin. Subtract the fee.
		FastBowlPlayerController->SetDirectCoin(NewValue);					//Direct Set Coin
		FastBowlPlayerController->SaveCoin();                              //Save Coin

		}
	}
}

void UWidgetSelectEvent::ClickMagicEvent()
{

	AFastBowlPlayerController* FastBowlPlayerController = Cast< AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController)
	{
		if (FastBowlPlayerController->GetLevelSystem() > 5 && FastBowlPlayerController->GetCoin() >= MagicBallCoinValue
			&& FastBowlPlayerController->magicball==false)
		{
			//Set Event Boolean
			FastBowlPlayerController->fastball = false;
			FastBowlPlayerController->magicball = true;
			FastBowlPlayerController->silverball = false;
			FastBowlPlayerController->Diamondball = false;
			FastBowlPlayerController->goldenball = false;
			FastBowlPlayerController->IsEventBegin = false;
			FastBowlPlayerController->SaveEvent();				//Save Event
			MagicTitle->SetColorAndOpacity(FSlateColor(FLinearColor::Green * 100.0f));

			FastBowlPlayerController->Minute = 3;	//Set Event Minute
			FastBowlPlayerController->Second = 59;	//Set Event Second
			FastBowlPlayerController->StartTimer();	//Start Timer
				
			Magic->SetBrushColor((FLinearColor::Green * 100.0f));		//Active Event Border Color


			float NewValue;
			NewValue = FastBowlPlayerController->GetCoin() - MagicBallCoinValue; //Calculate new Coin.Subtract the fee.
			FastBowlPlayerController->SetDirectCoin(NewValue); //Set Coin
			FastBowlPlayerController->SaveCoin();   //Save Coin
		}
	}
}

void UWidgetSelectEvent::ClickSilverTextHider()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast< AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController)
	{
		if (FastBowlPlayerController->GetLevelSystem() > 5 && FastBowlPlayerController->GetCoin() >= SilverBallCoinValue
			&& FastBowlPlayerController->silverball==false)
		{
			//Set Event Boolean
			FastBowlPlayerController->fastball = false;
			FastBowlPlayerController->magicball = false;
			FastBowlPlayerController->silverball = true;
			FastBowlPlayerController->Diamondball = false;
			FastBowlPlayerController->goldenball = false;
			FastBowlPlayerController->IsEventBegin = false;
			FastBowlPlayerController->SaveEvent();//Save Event
			SilverTitle->SetColorAndOpacity(FSlateColor(FLinearColor::Green * 100.0f));

			FastBowlPlayerController->Minute = 3;	//Set Event Minute
			FastBowlPlayerController->Second = 30;	//Set Event Second
			FastBowlPlayerController->StartTimer(); //Start Timer
			Silver->SetBrushColor((FLinearColor::Green * 100.0f));		//Active Event Border Color

			float NewValue;
			NewValue = FastBowlPlayerController->GetCoin() - SilverBallCoinValue; ////Calculate new Coin.Subtract the fee.
			FastBowlPlayerController->SetDirectCoin(NewValue); //Set Coin
			FastBowlPlayerController->SaveCoin();   //Save Coin
		}
	}
}

void UWidgetSelectEvent::ClickDiamondEvent()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast< AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController)
	{
		if (FastBowlPlayerController->GetLevelSystem() > 5 && FastBowlPlayerController->GetCoin() >= DiamondBallCoinValue
			&& FastBowlPlayerController->Diamondball == false)
		{
			//Set Event Boolean
			FastBowlPlayerController->fastball = false;
			FastBowlPlayerController->magicball = false;
			FastBowlPlayerController->silverball = false;
			FastBowlPlayerController->Diamondball = true;
			FastBowlPlayerController->goldenball = false;
			FastBowlPlayerController->IsEventBegin = false;
			FastBowlPlayerController->SaveEvent();	//Save Event

			DiamondTitle->SetColorAndOpacity(FSlateColor(FLinearColor::Green * 100.0f));	//Active Event Border Color


			FastBowlPlayerController->Minute = 2;	//Set Event Minute
			FastBowlPlayerController->Second = 30;	//Set Event Second
			FastBowlPlayerController->StartTimer(); //Start Timer
			Diamond->SetBrushColor((FLinearColor::Green * 100.0f));


			float NewValue;
			NewValue = FastBowlPlayerController->GetCoin() - DiamondBallCoinValue;  ////Calculate new Coin.Subtract the fee.
			FastBowlPlayerController->SetDirectCoin(NewValue); //Set Coin
			FastBowlPlayerController->SaveCoin(); //Save Coin

		}
	}
}

void UWidgetSelectEvent::ClickGoldEvent()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast< AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController)
	{
		if (FastBowlPlayerController->GetLevelSystem() > 5 && FastBowlPlayerController->GetCoin() >= GoldenBallCoinValue
			&& FastBowlPlayerController->goldenball==false)
		{
			//Set Event Boolean
			FastBowlPlayerController->fastball = false;
			FastBowlPlayerController->magicball = false;
			FastBowlPlayerController->silverball = false;
			FastBowlPlayerController->Diamondball = false;
			FastBowlPlayerController->goldenball = true;
			FastBowlPlayerController->IsEventBegin = false;
			FastBowlPlayerController->SaveEvent();		//Save Event
			GoldTitle->SetColorAndOpacity(FSlateColor(FLinearColor::Green * 100.0f));	//Active Event Border Color

			FastBowlPlayerController->Minute = 1; //Set Event Minute
			FastBowlPlayerController->Second = 59; //Set Event Second
			FastBowlPlayerController->StartTimer(); //Start Timer
			Gold->SetBrushColor((FLinearColor::Green * 100.0f));

			
			float NewValue;
			NewValue = FastBowlPlayerController->GetCoin() - GoldenBallCoinValue; ////Calculate new Coin.Subtract the fee.
			FastBowlPlayerController->SetDirectCoin(NewValue); //Set Coin

			FastBowlPlayerController->SaveCoin(); //Save Coin
		}
	}
}
