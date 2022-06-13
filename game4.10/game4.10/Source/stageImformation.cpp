#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stageImformation.h"

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// stageImformation:這個class提供關卡資訊的能力
	// 
	// 
	/////////////////////////////////////////////////////////////////////////////
	CMovingBitmap stageImformation::BackGround[7];
	CMovingBitmap stageImformation::Name[7];
	stageImformation::stageImformation()
	{
		isBmpLoaded = false;
	}

	char* stageImformation::getStageBackground(int stage)
	{
		return stageBackGround[stage-1];
	}

	string stageImformation::getRivalBase(int stage)
	{
		return stageRivalBase[stage-1];
	}

	char * stageImformation::getMusic(int stage)
	{
		return stageMusic[stage-1];
	}

	char * stageImformation::getStageName(int stage)
	{
		return stageName[stage-1];
	}

	void stageImformation::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *L[14] = { ".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\關卡名稱\\台灣.bmp", ".\\bitmaps\\關卡名稱\\香港.bmp", ".\\bitmaps\\關卡名稱\\泰國.bmp", ".\\bitmaps\\關卡名稱\\中國.bmp", ".\\bitmaps\\關卡名稱\\蒙古.bmp", ".\\bitmaps\\關卡名稱\\韓國.bmp", ".\\bitmaps\\關卡名稱\\日本.bmp" };
			for (int i = 0; i < 7; i++) {
				BackGround[i].LoadBitmap(L[i],RGB(255,0,0));
				BackGround[i].SetTopLeft(0,0);
				Name[i].LoadBitmap(L[i+7],RGB(255, 0, 0));
				Name[i].SetTopLeft(110, 3);
			}
			isBmpLoaded = true;
		}
	}

	void stageImformation::ShowBitmapBackGround(int stage)
	{
		BackGround[stage - 1].ShowBitmap();
	}

	void stageImformation::ShowBitmapName(int stage)
	{
		Name[stage - 1].ShowBitmap();
	}
}