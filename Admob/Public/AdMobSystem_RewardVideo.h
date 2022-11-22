#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AdMobSystem_RewardVideo.generated.h"

#if PLATFORM_ANDROID
#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif


UCLASS(Blueprintable)
class FASTBOWLING_API UAdMobSystem : public UObject
{
	GENERATED_BODY()
	
public:
		UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Play Reward Video"), Category = "AndroidAPI")
		static void PlayRewardVideo();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Load Reward Video"), Category = "AndroidAPI")
		static void LoadRewardVideo();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Is Reward Video Ready"), Category = "AndroidAPI")
		static bool IsRewardVideoAvailable(bool Status);

		UPROPERTY(EditAnywhere,BlueprintReadWrite)
		 bool Done;

};
