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
	CMovingBitmap stageImformation::BackGround[10];
	CMovingBitmap stageImformation::Name[10];
	stageImformation::stageImformation()
	{
		isBmpLoaded = false;
	}

	string stageImformation::getRivalBase(int stage)
	{
		return stageRivalBase[stage-1];
	}

	void stageImformation::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *background[10] = { ".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\黃昏.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\夜晚.bmp",".\\bitmaps\\背景\\草地.bmp" ,".\\bitmaps\\背景\\草地.bmp" ,".\\bitmaps\\背景\\海灘.bmp" };
			char *name[10] = { ".\\bitmaps\\關卡名稱\\台灣.bmp", ".\\bitmaps\\關卡名稱\\香港.bmp", ".\\bitmaps\\關卡名稱\\泰國.bmp", ".\\bitmaps\\關卡名稱\\中國.bmp", ".\\bitmaps\\關卡名稱\\蒙古.bmp", ".\\bitmaps\\關卡名稱\\韓國.bmp", ".\\bitmaps\\關卡名稱\\日本.bmp", ".\\bitmaps\\關卡名稱\\澳大利亞.bmp", ".\\bitmaps\\關卡名稱\\新加坡.bmp", ".\\bitmaps\\關卡名稱\\馬爾地夫.bmp" };
			for (int i = 0; i < 10; i++) {
				BackGround[i].LoadBitmap(background[i],RGB(255,0,0));
				BackGround[i].SetTopLeft(0,0);
				Name[i].LoadBitmap(name[i],RGB(255, 0, 0));
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