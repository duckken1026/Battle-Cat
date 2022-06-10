#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stageSelector.h"

namespace game_framework {

/////////////////////////////////////////////////////////////////////////////
// stageSelector:這個class提供選擇關卡的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////
	CMovingBitmap stageSelector::stageImage[30];

	stageSelector::stageSelector()
	{
		isBmpLoaded = false;
		targetStage = 1;
		finalStage = 3;
	}

	void stageSelector::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *L[3] = { ".\\bitmaps\\關卡圖片\\台灣.bmp",".\\bitmaps\\關卡圖片\\香港.bmp",".\\bitmaps\\關卡圖片\\泰國.bmp" };
			for (int i = 0; i < 3; i++) {
				stageImage[i].LoadBitmap(L[i]);
			}
			isBmpLoaded = true;
		}
	}

	void stageSelector::ShowBitmap()
	{
		stageImage[targetStage - 1].ShowBitmap();
	}

	void stageSelector::SetTopLeft()
	{
	}

	void stageSelector::clickRight()
	{
		if (targetStage < finalStage) {
			targetStage += 1;
		}
	}

	void stageSelector::clickLeft()
	{
		if (targetStage > 1) {
			targetStage -= 1;
		}
	}

	int stageSelector::getStage()
	{
		return targetStage;
	}

}