//If the map is unlocked, use it.


#include "WidgetSelectLevel.h"
#include "Kismet/GameplayStatics.h"
#include "FastBowlPlayerController.h"

void UWidgetSelectLevel::NativeConstruct()
{

	Super::NativeConstruct();

	//Bind buttons.
	ButtonClassic->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickClassicBall);
	ButtonSnowball->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickSnowballBall);
	ButtonTemple->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickTempleBall);
	ButtonIsland->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickIslandBall);
	ButtonDesert->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickDesertBall);
	ButtonNature->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickNatureBall);
	ButtonRooftop->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickRooftopBall);
	ButtonCity->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickCityBall);
	ButtonMoon->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickMoonBall);
	ButtonDanger->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickDangerBall);
	ButtonOrange->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickOrangeBall);
	ButtonHall->OnClicked.AddDynamic(this, &UWidgetSelectLevel::ClickHallBall);

}

void UWidgetSelectLevel::NativeTick(const FGeometry& MyGeometry, float DeltaSecond)
{
	//only cosmetics
	Super::NativeTick(MyGeometry, DeltaSecond);

	/*
	Rules simple
	
	if(UnlockedMapBoolean==true)

	{
		1-Set Image opacity
		2-Hide Lock Text on image
	}
	
	else
	{
		1-Set Image opacity
		2-Set Unlock Message
		3-Visible Lock Text on image
	}

	*/





	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelClassic)
	{
		ClassicImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextClassic->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		ClassicImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextClassic->SetText(FText::FromString(TEXT("Unlock")));
		TextClassic->SetVisibility(ESlateVisibility::Visible);
		
	}


	if (FastBowlPlayerController->LevelSnowball)
	{
		SnowballImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextSnowball->SetVisibility(ESlateVisibility::Hidden);

	}

	else
	{
		SnowballImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextSnowball->SetText(FText::FromString(TEXT("Unlock")));
		TextSnowball->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelTempleball)
	{
		TempleImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextTemplebowl->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		TempleImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextTemplebowl->SetText(FText::FromString(TEXT("Unlock")));
		TextTemplebowl->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelIsland)
	{
		IslandImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextIsland->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		IslandImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextIsland->SetText(FText::FromString(TEXT("Unlock")));
		TextIsland->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelDesert)
	{
		DesertImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextDesert->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		DesertImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextDesert->SetText(FText::FromString(TEXT("Unlock")));
		TextDesert->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelNature)
	{
		NatureImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextNature->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		NatureImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextNature->SetText(FText::FromString(TEXT("Unlock")));
		TextNature->SetVisibility(ESlateVisibility::Visible);
	}


	if (FastBowlPlayerController->LevelRooftop)
	{
		RooftopImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextRooftop->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		RooftopImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextRooftop->SetText(FText::FromString(TEXT("Unlock")));
		TextRooftop->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelCity)
	{
		CityImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextCity->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		CityImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextCity->SetText(FText::FromString(TEXT("Unlock")));
		TextCity->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelMoon)
	{
		MoonImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextMoon->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		MoonImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextMoon->SetText(FText::FromString(TEXT("Unlock")));
		TextMoon->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelDanger)
	{
		DangerImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextDangerbowl->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		DangerImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextDangerbowl->SetText(FText::FromString(TEXT("Unlock")));
		TextDangerbowl->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelOrange)
	{
		OrangeImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextOrange->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		OrangeImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextOrange->SetText(FText::FromString(TEXT("Unlock")));
		TextOrange->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->LevelHall)
	{
		HallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		TextHall->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		HallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		TextHall->SetText(FText::FromString(TEXT("Unlock")));
		TextHall->SetVisibility(ESlateVisibility::Visible);
	}

	

}

void UWidgetSelectLevel::UnlockMapController()
{


}

void UWidgetSelectLevel::ClickClassicBall()
{
	RemoveFromParent();

	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelClassic)
	{
		//This part was made in Blueprint.
		
		//LoadingScreenWidget= CreateWidget<UUserWidget>(GetWorld(), LoadingScreenClassic);
		//LoadingScreenWidget->AddToViewport();
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Bowlingx")));

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			// Set Map Number. Can Found in FastbowlGameMode.cpp 
			Creator->MapNumber = 1;
			//Is Unlock object map?
			Creator->IsUnlockMap = true;
			//Set Unlock Message
			Creator->Name = TEXT("Unlock Fastbowl Classic");
			//Set Price
			Creator->Value = 1000;
			//Draw on Screen
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickSnowballBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelSnowball)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenSnowball);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Snowball")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 2;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Snowball");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}

}

void UWidgetSelectLevel::ClickTempleBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelTempleball)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenTemple);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Templebowl")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 3;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Templebowl");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickIslandBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelIsland)
	{
		//This part was made in Blueprint.
		// 
		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenIsland);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("island")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 4;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Islandbowl");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickDesertBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelDesert)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenDesert);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Desertball")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 5;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Desertball");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickNatureBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelNature)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenNature);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Naturebowl")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 6;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Garden");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickRooftopBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelRooftop)
	{

		//This part was made in Blueprint.


		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenRooftop);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("FlyingBall")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 7;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Rooftop");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickCityBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelCity)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenCity);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Citybowl")));
	}
	

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 8;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Pool");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickMoonBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelMoon)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenMoon);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Moonbowl")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 9;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Spacebowl");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickDangerBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelDanger)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenDanger);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("LavaBowl")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 10;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Lavabowl");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickOrangeBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelOrange)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenOrange);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}
		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Orange")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 11;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Dreambowl");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}

void UWidgetSelectLevel::ClickHallBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->LevelHall)
	{
		//This part was made in Blueprint.

		//LoadingScreenWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenHall);
		//if (LoadingScreenWidget)
		//{
		//	LoadingScreenWidget->AddToViewport();
		//}

		//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Museum")));
	}


	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do same thing
			Creator->MapNumber = 12;
			Creator->IsUnlockMap = true;
			Creator->Name = TEXT("Unlock Museum");
			Creator->Value = 1000;
			Creator->AddToViewport();
		}
	}
}
