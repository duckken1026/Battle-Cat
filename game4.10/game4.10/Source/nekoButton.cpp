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

	CMovingBitmap nekoButton::button[30];
	nekoButton::nekoButton()
	{
		isBmpLoaded = false;
		for (int i = 0; i < 10; i++) {
			nekoLibrary data(nekoName[i]);
			isClicked[i] = false;
			buttonDelay[i] = data.buttonDelay;
			delay[i] = 0;
			affordable[i] = false;
		}
		clickedTimes = 0;
	}

	void nekoButton::LoadBitmap()
	{
		if (!isBmpLoaded) {
		char *L[30] = { ".\\bitmaps\\neko button\\Cat_text.bmp",".\\bitmaps\\neko button\\Tank Cat_text.bmp",".\\bitmaps\\neko button\\Axe Cat_text.bmp",".\\bitmaps\\neko button\\Gross Cat_text.bmp",".\\bitmaps\\neko button\\Cow Cat_text.bmp",".\\bitmaps\\neko button\\Bird Cat_text.bmp",".\\bitmaps\\neko button\\Fish Cat_text.bmp",".\\bitmaps\\neko button\\Lizard Cat_text.bmp",".\\bitmaps\\neko button\\Titan Cat_text.bmp",".\\bitmaps\\neko button\\None.bmp",".\\bitmaps\\neko button\\Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Tank Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Axe Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Gross Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Cow Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Bird Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Fish Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Lizard Cat_text_Dark.bmp",".\\bitmaps\\neko button\\Titan Cat_text_Dark.bmp",".\\bitmaps\\neko button\\None.bmp",".\\bitmaps\\neko button\\Cat_dark.bmp",".\\bitmaps\\neko button\\Tank_dark.bmp",".\\bitmaps\\neko button\\Axe Cat_dark.bmp",".\\bitmaps\\neko button\\Gross Cat_dark.bmp",".\\bitmaps\\neko button\\Cow Cat_dark.bmp",".\\bitmaps\\neko button\\Bird Cat_dark.bmp",".\\bitmaps\\neko button\\Fish Cat_dark.bmp",".\\bitmaps\\neko button\\Lizard Cat_dark.bmp",".\\bitmaps\\neko button\\Titan Cat_dark.bmp",".\\bitmaps\\neko button\\None.bmp" };
		for (int i = 0; i < 30; i++) {
			button[i].LoadBitmap(L[i]);
		}
		isBmpLoaded = true;
		}
	}

	void nekoButton::ShowBitmap()
	{
		for (int i = 0; i < 10; i++) {
			if (isClicked[i] == true  && delay[i] != 0) {
				button[i + 20].ShowBitmap();	//按下按鈕圖片變灰色
				delay[i] -= 1;
			}
			else {
				SetIsClicked(i, false);
				if (affordable[i]) {			//若目前金額足夠則顯示較亮且有文字的貓咪圖片
					button[i].ShowBitmap();
				}
				else {							//若不夠則顯示較暗且有文字的圖片
					button[i+10].ShowBitmap();
				}
						
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
			button[i+20].SetTopLeft(x[i], y[i]);
		}
	}

	void nekoButton::SetIsClicked(int buttonNum,bool clicked)
	{
		if (isClicked[buttonNum] == false) {			//若還沒按下則設定計時延遲
			delay[buttonNum] = buttonDelay[buttonNum]; //從buttonDelay中取得延長時間
		}
		isClicked[buttonNum] = clicked;
		if (checkNowClicked(buttonNum) == true) {
			clickedTimes += 1;
		}
	}

	void nekoButton::SetClicked(int pointX, int pointY)
	{
		for (int i = 0; i < 9; i++) {
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

	int nekoButton::getClickedTimes()
	{
		return clickedTimes;
	}

	void nekoButton::setClickedTimes(int number)
	{
		clickedTimes = number;
	}

	int nekoButton::getButtonNum(int pointX, int pointY)
	{
		for (int i = 0; i < 10; i++) {
			if ((x[i] < pointX) && (pointX < x[i] + button->Width()) && (y[i] < pointY) && (pointY < y[i] + button->Height())) {
				return i;
			}
		}
		return -1;
	}

	void nekoButton::updateAffordable(int currentMoney)
	{
		for (int i = 0; i < 10; i++) {
			nekoLibrary data(nekoName[i]);
			if (currentMoney >= data.cost) {	//若現在的錢足夠了
				affordable[i] = true;
			}
			else {
				affordable[i] = false;
			}
		}
	}

	bool nekoButton::isAffordable(int pointX, int pointY)
	{
		if (getButtonNum(pointX, pointY) != -1) {
			return affordable[getButtonNum(pointX, pointY)];
		}
		return false;				//若滑鼠按下的範圍不在按鈕上就不會執行mygame.cpp中OnLButtonUp裡面的內容
	}

	int nekoButton::costMoney(int nekoNumber)
	{
		nekoLibrary data(nekoName[nekoNumber]);
		return data.cost;
	}


	
}