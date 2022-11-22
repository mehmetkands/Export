// Ball Customize System. Opening new skins and changing skins are done here.


#include "WidgetCustomizeBall.h"
#include "Kismet/GameplayStatics.h"
#include "FastBowlPlayerController.h"

void UWidgetCustomizeBall::NativeConstruct()
{
	Super::NativeConstruct();

	//Bind Buttons
	ButtonBlueBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickBlueBall);
	ButtonRedBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickRedBall);
	ButtonGreenBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickGreenBall);
	ButtonYellowBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickYellowBall);
	ButtonOrangeBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickOrangeBall);
	ButtonPurpleBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickPurpleBall);
	ButtonWhiteBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickWhiteBall);
	ButtonBlackBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickBlackBall);
	ButtonGoldenBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickGoldenBall);

	ButtonEarthBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickEarthBall);
	ButtonMoonBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickMoonBall);
	ButtonFlowerBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickFlowerBall);
	ButtonCloudBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickCloudBall);
	ButtonCactusBall->OnClicked.AddDynamic(this, &UWidgetCustomizeBall::ClickCactusBall);



}

void UWidgetCustomizeBall::NativeTick(const FGeometry& MyGeometry, float DeltaSecond)
{
	//Only Cosmetics 
	Super::NativeTick(MyGeometry, DeltaSecond);

	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	//if red skin is unlocked
	if(FastBowlPlayerController->UnlockRed)
	{
	
		//Set Image color and Alpha
		RedBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));					//Set Image Color and Alpha

		//if red skin selected
		if (FastBowlPlayerController->TextureRed == true)
		{
			RedBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);						//Set Select Image color and Alpha	
		}

		else
		{
			RedBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		RedBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));					//Set Image Color and Alpha
	}

	//if blue skin is unlocked
	if (FastBowlPlayerController->UnlockBlue)
	{
		BlueBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureBlue == true)
		{
			BlueBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set Select Image color and Alpha
		}

		else
		{
			BlueBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		BlueBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));				//Set Image Color and Alpha
	
	}

	//if green skin is unlocked
	if (FastBowlPlayerController->UnlockGreen)
	{
		GreenBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureGreen == true)
		{
			GreenBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set Select Image color and Alpha
		}	

		else
		{
			GreenBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		GreenBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));			//Set Image Color and Alpha

	}

	//if yellow skin is unlocked
	if (FastBowlPlayerController->UnlockYellow)
	{
		YellowBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureYellow == true)
		{
			YellowBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set Select Image color and Alpha
		}

		else
		{
			YellowBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		YellowBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));			//Set Image Color and Alpha
	}

	//if orange skin is unlocked
	if (FastBowlPlayerController->UnlockOrange)
	{
		OrangeBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureOrange == true)
		{
			OrangeBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set Select Image color and Alpha
		}

		else
		{
			OrangeBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set Image color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		OrangeBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));			//Set Image color and Alpha
	}

	//if purple skin is unlocked
	if (FastBowlPlayerController->UnlockPurple)
	{
		PurpleBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		if (FastBowlPlayerController->TexturePurple == true)
		{
			PurpleBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);			//Set Select Image color and Alpha
		}

		else
		{
			PurpleBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));	//Set Image color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		PurpleBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));			//Set Image color and Alpha
	}

	//if white skin is unlocked
	if (FastBowlPlayerController->UnlockWhite)
	{
		WhiteBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureWhite == true)
		{
			WhiteBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set Select Image Color and Alpha
		}

		else
		{
			WhiteBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		WhiteBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));			//Set Image Color and Alpha
	}

	//if black skin is unlocked
	if (FastBowlPlayerController->UnlockBlack)
	{
		BlackBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureBlack == true)
		{
			BlackBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);				//Set Select Image Color and Alpha
		}

		else
		{
			BlackBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));		//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		BlackBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));				//Set Image Color and Alpha		
	}

	//if golden skin is unlocked
	if (FastBowlPlayerController->UnlockGolden)
	{
		GoldenBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		TextGoldenBall->SetVisibility(ESlateVisibility::Hidden);								//Set lock text visibility
		if (FastBowlPlayerController->TextureGolden == true)							
		{
			GoldenBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set Select Image Color and Alpha
		}

		else
		{
			GoldenBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		TextGoldenBall->SetVisibility(ESlateVisibility::Visible);									//Set lock text visibility	
		GoldenBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));					//Set Image Color and Alpha
	}

	//if earth skin is unlocked
	if (FastBowlPlayerController->UnlockEarth)
	{
		TextEarthBall->SetVisibility(ESlateVisibility::Hidden);										//Set lock text visibility
		EarthBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));					//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureEarth == true)
		{
			EarthBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);						//Set Select Image Color and Alpha
		}

		else
		{
			EarthBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		TextEarthBall->SetVisibility(ESlateVisibility::Visible);								//Set lock text visibility
		EarthBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));				//Set Image Color and Alpha
	}

	//if moon skin is unlocked
	if (FastBowlPlayerController->UnlockMoon)
	{
		TextMoonBall->SetVisibility(ESlateVisibility::Hidden);									//Set lock text visibility
		MoonBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureMoon == true)
		{
			MoonBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set Select Image Color and Alpha
		}

		else
		{
			MoonBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		TextMoonBall->SetVisibility(ESlateVisibility::Visible);									//Set lock text visibility
		MoonBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));				//Set Image Color and Alpha	
	}

	//if flower skin is unlocked
	if (FastBowlPlayerController->UnlockFlower)
	{
		TextFlowerBall->SetVisibility(ESlateVisibility::Hidden);								//Set lock text visibility
		FlowerBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f,1.0f));
		if (FastBowlPlayerController->TextureFlower == true)
		{
			FlowerBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set Select Image Color and Alpha
		}

		else
		{
			FlowerBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}

	//Set Image color and Alpha
	else
	{
		TextFlowerBall->SetVisibility(ESlateVisibility::Visible);								//Set lock text visibility
		FlowerBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));				//Set Image Color and Alpha
	}

	//if cloud skin is unlocked
	if (FastBowlPlayerController->UnlockCloud)
	{
		TextCloudBall->SetVisibility(ESlateVisibility::Hidden);									//Set lock text visibility	
		CloudBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		if (FastBowlPlayerController->TextureCloud == true)
		{
			CloudBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);					//Set Select Image Color and Alpha
		}

		else
		{
			CloudBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));			//Set Image Color and Alpha
		}
	}

	//Set Image color and Alpha
	else
	{
		TextCloudBall->SetVisibility(ESlateVisibility::Visible);								//Set lock text visibility
		CloudBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
	}

	//if cactus skin is unlocked
	if (FastBowlPlayerController->UnlockCactus==true)
	{
		TextCactusBall->SetVisibility(ESlateVisibility::Hidden);									//Set lock text visibility
		CactusBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));					//Set Image Color and Alpha

		if (FastBowlPlayerController->TextureCactus == true)
		{
			//Set Image color and Alpha
			CactusBallImage->SetColorAndOpacity(FLinearColor::Green * 100.0f);						//Set Select Image Color and Alpha
		}

		else
		{
			//Set Image color and Alpha
			CactusBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));				//Set Image Color and Alpha
		}	

	}

	//Set Image color and Alpha
	else
	{
		TextCactusBall->SetVisibility(ESlateVisibility::Visible);									//Set lock text visibility
		CactusBallImage->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
	}


	//Set Visibility Available Text
	if (FastBowlPlayerController->GetLevelSystem()>=20|| FastBowlPlayerController->EditionController()==true)

	{
		AvailableGoldText->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		AvailableGoldText->SetVisibility(ESlateVisibility::Visible);
	}


	if (FastBowlPlayerController->GetLevelSystem() >= 20 || FastBowlPlayerController->EditionController() == true)

	{
		AvailableEarthText->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		AvailableEarthText->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->GetLevelSystem() >= 20 || FastBowlPlayerController->EditionController() == true)

	{
		AvailableMoonText->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		AvailableMoonText->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->GetLevelSystem() >= 20 || FastBowlPlayerController->EditionController() == true)

	{
		AvailableFlowerText->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		AvailableFlowerText->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->GetLevelSystem() >= 20 || FastBowlPlayerController->EditionController() == true)

	{
		AvailableCloudText->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		AvailableCloudText->SetVisibility(ESlateVisibility::Visible);
	}

	if (FastBowlPlayerController->GetLevelSystem() >= 20 || FastBowlPlayerController->EditionController() == true)

	{
		AvailableCactusText->SetVisibility(ESlateVisibility::Hidden);
	}

	else
	{
		AvailableCactusText->SetVisibility(ESlateVisibility::Visible);
	}

}

void UWidgetCustomizeBall::UnlockTextureController()
{

}

void UWidgetCustomizeBall::ClickBlueBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	//if unlock texture
	if (FastBowlPlayerController->UnlockBlue)
	{
		FastBowlPlayerController->TextureBlue = true; //Set texture. The other is apply list to turn off selected textures. All but the selected color will return false.
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();  //Save Texture.
	}

	else 
	{
		//Draw Unlock Screen
		Creator= CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Set Texture Number
			Creator->TextureNumber = 1;
			//Unlock Type is Map?
			Creator->IsUnlockMap = false;
			//Unlock Message
			Creator->Name = TEXT("Unlock Blue Ball Skin");
			//Price
			Creator->Value = 1000;
			//Request Level
			Creator->RequestLevel = 0;
			//Draw on screen
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickRedBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockRed)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = true;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;
		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Set Texture Number
			Creator->TextureNumber = 2;
			//Unlock Type is Map?
			Creator->IsUnlockMap = false;
			//Unlock Message
			Creator->Name = TEXT("Red Ball Skin");
			//Price
			Creator->Value = 1000;
			//Request Level
			Creator->RequestLevel = 0;
			//Draw on screen
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickGreenBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockGreen)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = true;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();
	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Set Texture Number
			Creator->TextureNumber = 3;
			//Unlock Type is Map?
			Creator->IsUnlockMap = false;
			//Unlock Message
			Creator->Name = TEXT("Unlock Green Ball Skin");
			//Price
			Creator->Value = 1000;
			//Request Level
			Creator->RequestLevel = 0;
			//Draw on screen
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickYellowBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockYellow)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = true;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 4;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Yellow Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 0;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickOrangeBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockOrange)
	{
		
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = true;
		FastBowlPlayerController->TextureOrange = true;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 5;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Orange Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 0;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickPurpleBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockPurple)
	{
	
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = true;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 6;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Purple Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 0;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickWhiteBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockWhite)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = true;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 7;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock White Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 0;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickBlackBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockBlack)
	{

		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = true;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

	
		FastBowlPlayerController->SaveBallTexture();
		

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 8;
			Creator->IsUnlockMap = false;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Black Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 0;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickGoldenBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockGolden)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = true;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 9;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Gold Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 12;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickSilverBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockSilver)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = true;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();

	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 10;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Silver Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 20;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickEarthBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockEarth)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = true;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();
	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 11;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Earth Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 20;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickMoonBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockMoon)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = true;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();
	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 12;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Moon Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 20;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickFlowerBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockFlower)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = true;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();
	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 13;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Flower Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 20;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickCloudBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockCloud)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = true;
		FastBowlPlayerController->TextureCactus = false;

		FastBowlPlayerController->SaveBallTexture();
	}

	else
	{

		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 14;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Cloud Ball Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 20;
			Creator->AddToViewport();
		}
	}
}

void UWidgetCustomizeBall::ClickCactusBall()
{
	AFastBowlPlayerController* FastBowlPlayerController = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (FastBowlPlayerController->UnlockCactus)
	{
		FastBowlPlayerController->TextureBlue = false;
		FastBowlPlayerController->TextureRed = false;
		FastBowlPlayerController->TextureGreen = false;
		FastBowlPlayerController->TextureYellow = false;
		FastBowlPlayerController->TextureOrange = false;
		FastBowlPlayerController->TexturePurple = false;
		FastBowlPlayerController->TextureWhite = false;
		FastBowlPlayerController->TextureBlack = false;
		FastBowlPlayerController->TextureGolden = false;
		FastBowlPlayerController->TextureSilver = false;
		FastBowlPlayerController->TextureEarth = false;
		FastBowlPlayerController->TextureMoon = false;
		FastBowlPlayerController->TextureFlower = false;
		FastBowlPlayerController->TextureCloud = false;
		FastBowlPlayerController->TextureCactus = true;

		FastBowlPlayerController->SaveBallTexture();
	}

	else
	{
		Creator = CreateWidget<UWidgetApproval>(GetWorld(), SubCreator);
		if (Creator)
		{
			//Do the same as above.
			Creator->TextureNumber = 15;
			Creator->IsUnlockMap = false;
			Creator->Name = TEXT("Unlock Cactus Skin");
			Creator->Value = 1000;
			Creator->RequestLevel = 20;
			Creator->AddToViewport();
		}
	}
}
