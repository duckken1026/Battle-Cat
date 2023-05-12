#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "levelUpButton.h"

namespace game_framework {

/////////////////////////////////////////////////////////////////////////////
// levelUpButton:�o��class���Ѥɯſ��]���s����O
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
		int RequireMoney[8] = { 80,200,400,700,1000,1200,1500,1800 };//�ɯũһݪ��B
		for (int i = 0; i < 7; i++) {
			requireMoney[i] = RequireMoney[i];
		}
		int speedData[8] = {5,10,15,20,25,30,40,50 };//�����W�[�t�׸��
		for (int i = 0; i < 8; i++) {
			addSpeed[i] = speedData[i];
		}
	}

	void levelUpButton::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *L[15] = {".\\bitmaps\\�u�@��\\level1_dark.bmp",".\\bitmaps\\�u�@��\\level2_dark.bmp",".\\bitmaps\\�u�@��\\level3_dark.bmp",".\\bitmaps\\�u�@��\\level4_dark.bmp",".\\bitmaps\\�u�@��\\level5_dark.bmp",".\\bitmaps\\�u�@��\\level6_dark.bmp",".\\bitmaps\\�u�@��\\level7_dark.bmp",".\\bitmaps\\�u�@��\\level1_light.bmp",".\\bitmaps\\�u�@��\\level2_light.bmp",".\\bitmaps\\�u�@��\\level3_light.bmp",".\\bitmaps\\�u�@��\\level4_light.bmp",".\\bitmaps\\�u�@��\\level5_light.bmp",".\\bitmaps\\�u�@��\\level6_light.bmp",".\\bitmaps\\�u�@��\\level7_light.bmp",".\\bitmaps\\�u�@��\\level8_light.bmp" };
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
			if (currentMoney >= requireMoney[level-1]) {
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
			if (affordable == true && level < 8) {		//�Y���U�ɪ��������N�ɯťB������
				levelUp();
				return true;
			}
		}
		return false;
	}

	void levelUpButton::SetInitLevel()
	{
		level = 1;
	}

}