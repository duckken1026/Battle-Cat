#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "ImageNumber.h"
#include "nekoButton.h"
#include "nekoLibrary.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// ImageNumber:這個class提供顯示角色按鈕的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////

	CMovingBitmap nekoButton::button[20];
	nekoButton::nekoButton()
	{
		string nekoName[10] = {"Cat","Tank Cat","Axe Cat","Cow Cat","Bird Cat","Fish Cat","Lizard Cat","Titan Cat"};
		isBmpLoaded = false;
		for (int i = 0; i < 10; i++) {
			nekoLibrary data(nekoName[i]);
			isClicked[i] = false;
			buttonDelay[i] = data.buttonDelay;
			delay[i] = 0;
		}
	}

	void nekoButton::LoadBitmap()
	{
		if (!isBmpLoaded) {
		char *L[20] = { ".\\bitmaps\\neko button\\Cat.bmp",".\\bitmaps\\neko button\\Tank Cat.bmp",".\\bitmaps\\neko button\\Axe Cat.bmp",".\\bitmaps\\neko button\\Gross Cat.bmp",".\\bitmaps\\neko button\\Cow Cat.bmp",".\\bitmaps\\neko button\\Bird Cat.bmp",".\\bitmaps\\neko button\\Fish Cat.bmp",".\\bitmaps\\neko button\\Lizard Cat.bmp",".\\bitmaps\\neko button\\Titan Cat.bmp",".\\bitmaps\\neko button\\None.bmp",".\\bitmaps\\neko button\\Cat_dark.bmp",".\\bitmaps\\neko button\\Tank_dark.bmp",".\\bitmaps\\neko button\\Axe Cat_dark.bmp",".\\bitmaps\\neko button\\Gross Cat_dark.bmp",".\\bitmaps\\neko button\\Cow Cat_dark.bmp",".\\bitmaps\\neko button\\Bird Cat_dark.bmp",".\\bitmaps\\neko button\\Fish Cat_dark.bmp",".\\bitmaps\\neko button\\Lizard Cat_dark.bmp",".\\bitmaps\\neko button\\Titan Cat_dark.bmp",".\\bitmaps\\neko button\\None.bmp" };
		for (int i = 0; i < 20; i++) {
			button[i].LoadBitmap(L[i]);
		}
		isBmpLoaded = true;
		}
	}

	void nekoButton::ShowBitmap()
	{
		for (int i = 0; i < 10; i++) {
			if (isClicked[i] == true  && delay[i] != 0) {
				button[i + 10].ShowBitmap();	//按下按鈕圖片變灰色
				delay[i] -= 1;
			}
			else {
				SetIsClicked(i, false);
				button[i].ShowBitmap();
			}
		}
	}

	void nekoButton::SetTopLeft()
	{
		int width = button[0].Width();	//圖片寬度
		int height = button[0].Height();//圖片高度
		xGap = 50;
		yGap = 10;
		for (int i = 0; i < 10; i++) {
			x[i] = 420 + (width + xGap) * (i % 5);
			y[i] = 790 +(height +yGap) * (i / 5);
			button[i].SetTopLeft(x[i], y[i]);
			button[i+10].SetTopLeft(x[i], y[i]);
		}
	}

	void nekoButton::SetIsClicked(int buttonNum,bool clicked)
	{
		if (isClicked[buttonNum] == false) {			//若還沒按下則開始計時延遲
			delay[buttonNum] = buttonDelay[buttonNum]; //從buttonDelay中取得延長時間
		}
		isClicked[buttonNum] = clicked;
	}

	void nekoButton::SetClicked(int pointX, int pointY)
	{
		for (int i = 0; i < 10; i++) {
			if ((x[i] < pointX) && (pointX < x[i] + button->Width()) && (y[i] < pointY) && (pointY < y[i] + button->Height())) {
				SetIsClicked(i, true);
			}
		}	
	}

	bool nekoButton::checkNowClicked(int nekoNumber)
	{
		if (isClicked[nekoNumber] == true && (buttonDelay[nekoNumber] - delay[nekoNumber]) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
}