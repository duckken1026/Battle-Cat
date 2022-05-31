#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "levelUpButton.h"

namespace game_framework {

/////////////////////////////////////////////////////////////////////////////
// levelUpButton:這個class提供升級錢包按鈕的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////

	CMovingBitmap levelUpButton::button[15];

	levelUpButton::levelUpButton()
	{
		isBmpLoaded = false;
		level = 1;
		affordable = false;
		maxMoney = 300;
		for (int i = 0; i < 7; i++) {
			requireMoney[i] = 40*(i+1);
		}
	}

	void levelUpButton::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *L[15] = {".\\bitmaps\\工作貓\\level1_dark.bmp",".\\bitmaps\\工作貓\\level2_dark.bmp",".\\bitmaps\\工作貓\\level3_dark.bmp",".\\bitmaps\\工作貓\\level4_dark.bmp",".\\bitmaps\\工作貓\\level5_dark.bmp",".\\bitmaps\\工作貓\\level6_dark.bmp",".\\bitmaps\\工作貓\\level7_dark.bmp",".\\bitmaps\\工作貓\\level1_light.bmp",".\\bitmaps\\工作貓\\level2_light.bmp",".\\bitmaps\\工作貓\\level3_light.bmp",".\\bitmaps\\工作貓\\level4_light.bmp",".\\bitmaps\\工作貓\\level5_light.bmp",".\\bitmaps\\工作貓\\level6_light.bmp",".\\bitmaps\\工作貓\\level7_light.bmp",".\\bitmaps\\工作貓\\level8_light.bmp" };
			for (int i = 0; i < 15; i++) {
				button[i].LoadBitmap(L[i],RGB(255,0,0));
			}
			isBmpLoaded = true;
		}
	}

	void levelUpButton::ShowBitmap()
	{
		if (affordable == true) {
			button[level-1+7].ShowBitmap();
		}
		else {
			button[level-1].ShowBitmap();
		}

	}

	void levelUpButton::SetTopLeft()
	{
		for (int i = 0; i < 15; i++) {
			button[i].SetTopLeft(0, 885);
		}
	}

	int levelUpButton::getCurrentLevel()
	{
		return level;
	}

	void levelUpButton::levelUp()
	{
		if (level < 8) {
			level += 1;
		}
	}

	bool levelUpButton::checkAffordable(int currentMoney)
	{
		if (level < 8) {
			if (currentMoney > requireMoney[level-1]) {
				affordable = true;
				return true;
			}
			else {
				affordable = false;
				return false;
			}
		}
		else {
			return true;
		}
		
	}

	bool levelUpButton::clickAction(int pointX, int pointY)
	{
		if ((0 <= pointX) && (pointX <= 291) && (885 <= pointY) && (pointY <= 1080)) {
			if (affordable == true && level < 8) {		//若按下時金錢足夠就升級且扣掉錢
				levelUp();
				return true;
			}
		}
		return false;
	}

}