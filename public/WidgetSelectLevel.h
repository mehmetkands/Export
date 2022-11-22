

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "WidgetApproval.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "WidgetSelectLevel.generated.h"

/**
 * 
 */
UCLASS()
class FASTBOWLING_API UWidgetSelectLevel : public UUserWidget
{
	GENERATED_BODY()


public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaSecond) override;

	//BUTTON
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonClassic;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonSnowball;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonTemple;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonIsland;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonDesert;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonNature;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonRooftop;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonCity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonMoon;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonDanger;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonOrange;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonHall;



	//Images

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* ClassicImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* SnowballImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* TempleImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* IslandImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* DesertImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* NatureImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* RooftopImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* CityImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* MoonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* DangerImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* OrangeImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* HallImage;


	//Texts

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextClassic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextSnowball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextTemplebowl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextIsland;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextDesert;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextNature;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextRooftop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextCity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextMoon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextDangerbowl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextOrange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextHall;


	
	void UnlockMapController();

	//Click Button Function
	UFUNCTION()
	void ClickClassicBall();

	UFUNCTION()
	void ClickSnowballBall();

	UFUNCTION()
	void ClickTempleBall();

	UFUNCTION()
	void ClickIslandBall();

	UFUNCTION()
	void ClickDesertBall();

	UFUNCTION()
	void ClickNatureBall();

	UFUNCTION()
	void ClickRooftopBall();

	UFUNCTION()
	void ClickCityBall();

	UFUNCTION()
	void ClickMoonBall();

	UFUNCTION()
	void ClickDangerBall();

	UFUNCTION()
	void ClickOrangeBall();

	UFUNCTION()
	void ClickHallBall();


	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UWidgetApproval> SubCreator;

	//Loading Screen Sub Class Widgets
	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenClassic;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenSnowball;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenTemple;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenIsland;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenDesert;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenNature;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenRooftop;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenCity;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenMoon;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenDanger;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenOrange;

	UPROPERTY(EditDefaultsOnly, Category = "The Widget")
		TSubclassOf<UUserWidget> LoadingScreenHall;
		//Approval Widget Creator
		UWidgetApproval* Creator;
		UUserWidget* LoadingScreenWidget;
};
