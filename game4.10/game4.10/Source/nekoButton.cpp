#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "ImageNumber.h"
#include "nekoButton.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// ImageNumber:這個class提供顯示角色按鈕的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////

	CMovingBitmap nekoButton::button[10];

	nekoButton::nekoButton()
	{
		isBmpLoaded = false;
		isClicked = false;
	}

	void nekoButton::LoadBitmap()
	{
		if (!isBmpLoaded) {
		char *L[10] = { ".\\bitmaps\\neko button\\Cat.bmp",".\\bitmaps\\neko button\\Tank Cat.bmp",".\\bitmaps\\neko button\\Axe Cat.bmp",".\\bitmaps\\neko button\\Gross Cat.bmp",".\\bitmaps\\neko button\\Cow Cat.bmp",".\\bitmaps\\neko button\\Bird Cat.bmp",".\\bitmaps\\neko button\\Fish Cat.bmp",".\\bitmaps\\neko button\\Lizard Cat.bmp",".\\bitmaps\\neko button\\Titan Cat.bmp",".\\bitmaps\\neko button\\None.bmp" };
		for (int i = 0; i < 10; i++) {
			button[i].LoadBitmap(L[i]);
		}
		isBmpLoaded = true;
		}
	}

	void nekoButton::ShowBitmap()
	{
		for (int i = 0; i < 10; i++) {
			button[i].ShowBitmap();
		}
	}

	void nekoButton::SetTopLeft()
	{
		int width = button[0].Width();	//圖片寬度
		int height = button[0].Height();//圖片高度
		xGap = 50;
		yGap = 10;
		static int x[10] ;//按鈕x座標
		static int y[10];//按鈕y座標
		for (int i = 0; i < 10; i++) {
			x[i] = 420 + (width + xGap) * (i % 5);
			y[i] = 790 +(height +yGap) * (i / 5);
			button[i].SetTopLeft(x[i], y[i]);
		}
	}

	void nekoButton::SetIsClicked(bool clicked)
	{
		isClicked = clicked;
	}
	
}