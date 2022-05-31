#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "maxNumber.h"

namespace game_framework {


	/////////////////////////////////////////////////////////////////////////////
	// maxNumber:這個class提供顯示最大整數圖形的能力
	// 
	// 
	/////////////////////////////////////////////////////////////////////////////

	CMovingBitmap maxNumber::digit[13];

	maxNumber::maxNumber(int digits)
		: NUMDIGITS(digits)
	{
		isBmpLoaded = false;
	}

	void maxNumber::Add(int x)
	{
		n += x;
		int quotient = n;			//根據此商數去計算此數有幾位數
		int digit = 0;				//算出的位數
		while (quotient != 0)
		{
			quotient /= 10;
			digit += 1;
		}
		NUMDIGITS = digit;
	}

	int maxNumber::GetInteger()
	{
		return n;
	}

	void maxNumber::LoadBitmap()
	{
		//
		// digit[i]為class varibale，所以必須避免重複LoadBitmap
		//
		if (!isBmpLoaded) {
			char *d[13] = { ".\\bitmaps\\number\\0.bmp",".\\bitmaps\\number\\1.bmp",".\\bitmaps\\number\\2.bmp",".\\bitmaps\\number\\3.bmp",".\\bitmaps\\number\\4.bmp",".\\bitmaps\\number\\5.bmp",".\\bitmaps\\number\\6.bmp",".\\bitmaps\\number\\7.bmp",".\\bitmaps\\number\\8.bmp",".\\bitmaps\\number\\9.bmp",".\\bitmaps\\number\\bmp10.bmp",".\\bitmaps\\number\\slash.bmp",".\\bitmaps\\number\\元.bmp" };
			for (int i = 0; i < 13; i++)
				digit[i].LoadBitmap(d[i], RGB(255, 0, 0));
			isBmpLoaded = true;
		}
	}

	void maxNumber::SetInteger(int i)
	{
		n = i;
	}

	void maxNumber::SetTopLeft(int nx, int ny)		// 將動畫的左上角座標移至 (x,y)
	{
		x = nx; y = ny;
	}

	void maxNumber::ShowBitmap()
	{
		GAME_ASSERT(isBmpLoaded, "CInteger: 請先執行LoadBitmap，然後才能ShowBitmap");
		int nx;		// 待顯示位數的 x 座標
		int MSB;	// 最左邊(含符號)的位數的數值
		if (n >= 0) {
			MSB = n;
			nx = x + digit[0].Width()*(NUMDIGITS - 1);
		}
		else {
			MSB = -n;
			nx = x + digit[0].Width()*NUMDIGITS;
		}
		for (int i = 0; i < NUMDIGITS; i++) {
			int d = MSB % 10;
			MSB /= 10;
			digit[d].SetTopLeft(nx, y);
			digit[d].ShowBitmap();
			nx -= digit[d].Width();
		}
		if (n < 0) { // 如果小於0，則顯示負號
			digit[10].SetTopLeft(nx, y);
			digit[10].ShowBitmap();
		}
		digit[11].SetTopLeft(nx, y);		//設定slash座標
		digit[11].ShowBitmap();				//顯示slash圖片
		digit[12].SetTopLeft(nx + (NUMDIGITS + 1)* digit[0].Width(), y);//設定元座標
		digit[12].ShowBitmap();				//顯示元圖片
	}

	void maxNumber::SetDigits(int num)
	{
		NUMDIGITS = num;
	}

}