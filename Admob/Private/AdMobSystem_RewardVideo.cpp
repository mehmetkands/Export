//Only works android platform.

#include "AdMobSystem_RewardVideo.h"

//Play Reward Video
void UAdMobSystem::PlayRewardVideo()
{
#if PLATFORM_ANDROID


	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		const bool bIsOptional = false;
		static jmethodID PlayRewardVideoMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowRewardVideo", "()V", bIsOptional);

		// Call Java Method
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, PlayRewardVideoMethod);


	}

#endif

}

//Load Reward Video Ad
void UAdMobSystem::LoadRewardVideo()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jboolean Ready;
		const bool bIsOptional = false;
		static jmethodID AndroidThunkJava_LoadRewardVideo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_LoadRewardVideo", "()Z", bIsOptional);

		// Call Java Method
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_LoadRewardVideo);


		 //Convert scope array into java fields
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, JniMethod);
	}
#endif
}

//Is Ready?
bool UAdMobSystem::IsRewardVideoAvailable(bool Status)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID JniMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_RewardedVideoReady", "()Z", bIsOptional);

		// Convert scope array into java fields
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, JniMethod);
	}
#endif
	return false;
}