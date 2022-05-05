#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供敵方圖鑑收集敵方的各項資料
	// 
	/////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////
	//輸入敵方種類設定數值
	//
	/////////////////////////////////////////////////////////////////////////////
	rivalLibrary::rivalLibrary(string name) {
		if (name == "Doge")
		{
			range = 4;
			health = 90;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 9;
		}
		else {
			range = 4;
			health = 100;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 17;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	//敵方圖片載入
	//
	/////////////////////////////////////////////////////////////////////////////
	char * rivalLibrary::imageList(string name, int imageNumber)
	{
		char *temp[9] = { ".\\bitmaps\\狗仔\\狗狗0.bmp",".\\bitmaps\\狗仔\\狗狗1.bmp",".\\bitmaps\\狗仔\\狗狗2.bmp",".\\bitmaps\\狗仔\\狗狗3.bmp",".\\bitmaps\\狗仔\\攻擊0.bmp",".\\bitmaps\\狗仔\\攻擊2.bmp",".\\bitmaps\\狗仔\\攻擊3.bmp",".\\bitmaps\\狗仔\\攻擊4.bmp",".\\bitmaps\\狗仔\\攻擊5.bmp" };
		return temp[imageNumber];
	}



}