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
		if (name == "Doge")				//狗仔資料
		{
			range = 15;
			health = 1000;
			attack = 100;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 20;
			deathHeightChange = 95;
			deathXChange = 185;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 26;
			originY = 640;
		}
		else if (name == "Snache") {	//扭扭蛇資料
			range = 20;
			health = 10;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 4;
			attackAnimationStart = 5;
			attackAnimationEnd = 11;
			deathAnimationStart = 12;
			deathAnimationEnd = 23;
			deathHeightChange = 85;
			deathXChange = 161;
			moveSpeed = 3;
			imageQuantity = 24;
			headGap = 13;
			originY = 640;
		}
		else if (name == "Those Guys") { //團結筷子幫資料
			range = 20;
			health = 100;
			attack = 1;
			attackDelay = 13;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 17;
			deathAnimationStart = 18;
			deathAnimationEnd = 29;
			deathHeightChange = 0;
			deathXChange = 103;
			moveSpeed = 3;
			imageQuantity = 30;
			headGap = 13;
			originY = 640;
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
			headGap = 26;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	//敵方圖片載入
	//
	/////////////////////////////////////////////////////////////////////////////
	char * rivalLibrary::imageList(string name, int imageNumber)
	{
		if (name == "Doge") {		//狗仔資料
			char *temp[21] = { ".\\bitmaps\\敵方\\狗仔\\狗狗0.bmp",".\\bitmaps\\敵方\\狗仔\\狗狗1.bmp",".\\bitmaps\\敵方\\狗仔\\狗狗2.bmp",".\\bitmaps\\敵方\\狗仔\\狗狗3.bmp",".\\bitmaps\\敵方\\狗仔\\攻擊0.bmp",".\\bitmaps\\敵方\\狗仔\\攻擊2.bmp",".\\bitmaps\\敵方\\狗仔\\攻擊3.bmp",".\\bitmaps\\敵方\\狗仔\\攻擊4.bmp",".\\bitmaps\\敵方\\狗仔\\攻擊5.bmp",".\\bitmaps\\敵方\\狗仔\\擊退0.bmp",".\\bitmaps\\敵方\\狗仔\\擊退1.bmp",".\\bitmaps\\敵方\\狗仔\\擊退2.bmp",".\\bitmaps\\敵方\\狗仔\\擊退3.bmp",".\\bitmaps\\敵方\\狗仔\\擊退4.bmp",".\\bitmaps\\敵方\\狗仔\\擊退5.bmp",".\\bitmaps\\敵方\\狗仔\\擊退6.bmp",".\\bitmaps\\敵方\\狗仔\\擊退7.bmp",".\\bitmaps\\敵方\\狗仔\\擊退8.bmp",".\\bitmaps\\敵方\\狗仔\\擊退9.bmp",".\\bitmaps\\敵方\\狗仔\\擊退10.bmp",".\\bitmaps\\敵方\\狗仔\\擊退11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Snache") {	//扭扭蛇資料
			char *temp[24] = { ".\\bitmaps\\敵方\\扭扭蛇\\行走0.bmp",".\\bitmaps\\敵方\\扭扭蛇\\行走1.bmp",".\\bitmaps\\敵方\\扭扭蛇\\行走2.bmp",".\\bitmaps\\敵方\\扭扭蛇\\行走3.bmp",".\\bitmaps\\敵方\\扭扭蛇\\行走4.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊0.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊1.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊2.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊3.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊4.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊5.bmp",".\\bitmaps\\敵方\\扭扭蛇\\攻擊6.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退0.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退1.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退2.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退3.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退4.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退5.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退6.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退7.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退8.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退9.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退10.bmp",".\\bitmaps\\敵方\\扭扭蛇\\擊退11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Those Guys") {//團結筷子幫資料
			char *temp[30] = { ".\\bitmaps\\敵方\\團結筷子幫\\行走0.bmp",".\\bitmaps\\敵方\\團結筷子幫\\行走1.bmp",".\\bitmaps\\敵方\\團結筷子幫\\行走2.bmp",".\\bitmaps\\敵方\\團結筷子幫\\行走3.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊0.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊1.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊2.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊3.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊4.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊5.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊6.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊7.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊8.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊9.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊10.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊11.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊12.bmp",".\\bitmaps\\敵方\\團結筷子幫\\攻擊13.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退0.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退1.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退2.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退3.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退4.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退5.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退6.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退7.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退8.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退9.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退10.bmp",".\\bitmaps\\敵方\\團結筷子幫\\擊退11.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = { ".\\bitmaps\\敵方\\狗仔\\狗狗0.bmp" };
			return temp[imageNumber];
		}
		
	}



}