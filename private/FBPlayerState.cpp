//Level System. Stores other information.(Player based)

#include "FBPlayerState.h"

//Level Controller. It assigns a level value according to the score.
void AFBPlayerState::SetLevelNumberWithPoint()
{
	if (Point >= Level1ReqPoint &&Level1Done == false)
	{
		InGameLevel = 1;								//Level Value
		Level1Done = true;								//is trueCurrent
		LevelNow = Level2ReqPoint;						//If true, this level is no longer accessible.
	}



	if (Point >= Level2ReqPoint && Level2Done == false)
	{
		InGameLevel = 2;
		Level2Done = true;
		LevelNow = Level3ReqPoint;					
	}


	if (Point >= Level3ReqPoint && Level3Done == false)
	{
		InGameLevel = 3;
		Level3Done = true;
		LevelNow = Level4ReqPoint;					
	}


	if (Point >= Level4ReqPoint && Level4Done == false)
	{
		InGameLevel = 4;
		Level4Done = true;
		LevelNow = Level5ReqPoint;
	}


	if (Point >= Level5ReqPoint && Level5Done == false)
	{
		InGameLevel = 5;
		Level5Done = true;
		LevelNow = Level6ReqPoint;
	}


	if (Point >= Level6ReqPoint && Level6Done == false)
	{
		InGameLevel = 6;
		Level6Done = true;
		LevelNow = Level7ReqPoint;
	}


	if (Point >= Level7ReqPoint && Level7Done == false)
	{
		InGameLevel = 7;
		Level7Done = true;
		LevelNow = Level8ReqPoint;
	}


	if (Point >= Level8ReqPoint && Level8Done == false)
	{
		InGameLevel = 8;
		Level8Done = true;
		LevelNow = Level9ReqPoint;
	}


	if (Point >= Level9ReqPoint && Level9Done == false)
	{
		InGameLevel = 9;
		Level9Done = true;
		LevelNow = Level10ReqPoint;
	}


	if (Point >= Level10ReqPoint && Level10Done == false)
	{
		InGameLevel = 10;
		Level10Done = true;
		LevelNow = Level11ReqPoint;
	}



	if (Point >= Level11ReqPoint && Level11Done == false)
	{
		InGameLevel = 11;
		Level11Done = true;
		LevelNow = Level12ReqPoint;
	}



	if (Point >= Level12ReqPoint && Level12Done == false)
	{
		InGameLevel = 12;
		Level12Done = true;
		LevelNow = Level13ReqPoint;
	}


	if (Point >= Level13ReqPoint && Level13Done == false)
	{
		InGameLevel = 13;
		Level13Done = true;
		LevelNow = Level14ReqPoint;
	}


	if (Point >= Level14ReqPoint && Level14Done == false)
	{
		InGameLevel = 14;
		Level14Done = true;
		LevelNow = Level15ReqPoint;
	}


	if (Point >= Level15ReqPoint && Level15Done == false)
	{
		InGameLevel = 15;
		Level15Done = true;
		LevelNow = Level16ReqPoint;
	}


	if (Point >= Level16ReqPoint && Level16Done == false)
	{
		InGameLevel = 16;
		Level16Done = true;
		LevelNow = Level17ReqPoint;
	}


	if (Point >= Level17ReqPoint && Level17Done == false)
	{
		InGameLevel = 17;
		Level17Done = true;
		LevelNow = Level18ReqPoint;
	}


	if (Point >= Level18ReqPoint && Level18Done == false)
	{
		InGameLevel = 18;
		Level18Done = true;
		LevelNow = Level19ReqPoint;
	}


	if (Point >= Level19ReqPoint && Level19Done == false)
	{
		InGameLevel = 19;
		Level19Done = true;
		LevelNow = Level20ReqPoint;
	}


	if (Point >= Level20ReqPoint && Level20Done == false)
	{
		InGameLevel = 20;
		Level20Done = true;
		LevelNow = Level21ReqPoint;
	}


	if (Point >= Level21ReqPoint && Level21Done == false)
	{
		InGameLevel = 21;
		Level21Done = true;
		LevelNow = Level22ReqPoint;
	}



	if (Point >= Level22ReqPoint && Level22Done == false)
	{
		InGameLevel = 22;
		Level22Done = true;
		LevelNow = Level23ReqPoint;
	}


	if (Point >= Level23ReqPoint && Level23Done == false)
	{
		InGameLevel = 23;
		Level23Done = true;
		LevelNow = Level24ReqPoint;
	}


	if (Point >= Level24ReqPoint && Level24Done == false)
	{
		InGameLevel = 24;
		Level24Done = true;
		LevelNow = Level25ReqPoint;
	}


	if (Point >= Level25ReqPoint && Level25Done == false)
	{
		InGameLevel = 25;
		Level25Done = true;
		LevelNow = Level26ReqPoint;
	}


	if (Point >= Level26ReqPoint && Level26Done == false)
	{
		InGameLevel = 26;
		Level26Done = true;
		LevelNow = Level27ReqPoint;
	}


	if (Point >= Level27ReqPoint && Level27Done == false)
	{
		InGameLevel = 27;
		Level27Done = true;
		LevelNow = Level28ReqPoint;
	}


	if (Point >= Level28ReqPoint && Level28Done == false)
	{
		InGameLevel = 28;
		Level28Done = true;
		LevelNow = Level29ReqPoint;
	}


	if (Point >= Level29ReqPoint && Level29Done == false)
	{
		InGameLevel = 29;
		Level29Done = true;
		LevelNow = Level30ReqPoint;
	}


	if (Point >= Level30ReqPoint && Level30Done == false)
	{
		InGameLevel = 30;
		Level30Done = true;
		LevelNow = Level31ReqPoint;
	}



	if (Point >= Level31ReqPoint && Level31Done == false)
	{
		InGameLevel = 31;
		Level31Done = true;
		LevelNow = Level32ReqPoint;
	}



	if (Point >= Level32ReqPoint && Level32Done == false)
	{
		InGameLevel = 32;
		Level32Done = true;
		LevelNow = Level33ReqPoint;
	}


	if (Point >= Level33ReqPoint && Level33Done == false)
	{
		InGameLevel = 33;
		Level33Done = true;
		LevelNow = Level34ReqPoint;
	}


	if (Point >= Level34ReqPoint && Level34Done == false)
	{
		InGameLevel = 34;
		Level34Done = true;
		LevelNow = Level35ReqPoint;
	}


	if (Point >= Level35ReqPoint && Level35Done == false)
	{
		InGameLevel = 35;
		Level35Done = true;
		LevelNow = Level36ReqPoint;
	}


	if (Point >= Level36ReqPoint && Level36Done == false)
	{
		InGameLevel = 36;
		Level36Done = true;
		LevelNow = Level37ReqPoint;
	}


	if (Point >= Level37ReqPoint && Level37Done == false)
	{
		InGameLevel = 37;
		Level37Done = true;
		LevelNow = Level38ReqPoint;
	}


	if (Point >= Level38ReqPoint && Level38Done == false)
	{
		InGameLevel = 38;
		Level38Done = true;
		LevelNow = Level39ReqPoint;
	}


	if (Point >= Level39ReqPoint && Level39Done == false)
	{
		InGameLevel = 39;
		Level39Done = true;
		LevelNow = Level40ReqPoint;
	}


	if (Point >= Level40ReqPoint && Level40Done == false)
	{
		InGameLevel = 40;
		Level40Done = true;
	}


}
