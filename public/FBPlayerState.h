

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FBPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FASTBOWLING_API AFBPlayerState : public APlayerState
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		int InGameLevel;

	//Total Point
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Point;

	//Current Levels
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level1Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level2Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level3Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level4Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level5Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level6Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level7Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level8Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level9Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level10Done;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level11Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level12Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level13Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level14Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level15Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level16Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level17Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level18Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level19Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level20Done;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level21Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level22Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level23Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level24Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level25Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level26Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level27Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level28Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level29Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level30Done;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level31Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level32Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level33Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level34Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level35Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level36Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level37Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level38Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level39Done;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Level40Done;

	//required score
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level1ReqPoint=50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level2ReqPoint=100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level3ReqPoint=200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level4ReqPoint = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level5ReqPoint = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level6ReqPoint = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level7ReqPoint = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level8ReqPoint = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level9ReqPoint = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level10ReqPoint = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level11ReqPoint = 3000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level12ReqPoint = 4000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level13ReqPoint = 5000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level14ReqPoint = 6000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level15ReqPoint = 7000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level16ReqPoint = 8000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level17ReqPoint = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level18ReqPoint = 15000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level19ReqPoint = 20000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level20ReqPoint = 25000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level21ReqPoint = 30000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level22ReqPoint = 35000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level23ReqPoint = 40000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level24ReqPoint = 45000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level25ReqPoint = 50000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level26ReqPoint = 55000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level27ReqPoint = 60000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level28ReqPoint = 65000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level29ReqPoint = 70000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level30ReqPoint = 80000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level31ReqPoint = 90000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level32ReqPoint = 100000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level33ReqPoint = 110000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level34ReqPoint = 120000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level35ReqPoint = 130000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level36ReqPoint = 140000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level37ReqPoint = 150000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level38ReqPoint = 160000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level39ReqPoint = 170000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level40ReqPoint = 180000.0f;

	//Required score for next level.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelNow;

	//Set Level
	UFUNCTION(BlueprintCallable)
		void SetLevelNumberWithPoint();
	
};
