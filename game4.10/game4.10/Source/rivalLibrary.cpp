#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ³o­Óclass´£¨Ñ¼Ä¤è¹ÏÅ²¦¬¶°¼Ä¤èªº¦U¶µ¸ê®Æ
	// 
	/////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////
	//¿é¤J¼Ä¤èºØÃþ³]©w¼Æ­È
	//
	/////////////////////////////////////////////////////////////////////////////
	rivalLibrary::rivalLibrary(string name) {
		if (name == "Doge")
		{
			range = 3;
			health = 1000;
			attack = 1;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 20;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 26;
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
	//¼Ä¤è¹Ï¤ù¸ü¤J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * rivalLibrary::imageList(string name, int imageNumber)
	{
		char *temp[21] = { ".\\bitmaps\\¼Ä¤è\\ª¯¥J\\ª¯ª¯0.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\ª¯ª¯1.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\ª¯ª¯2.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\ª¯ª¯3.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\§ðÀ»0.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\§ðÀ»2.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\§ðÀ»3.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\§ðÀ»4.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\§ðÀ»5.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h0.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h1.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h2.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h3.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h4.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h5.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h6.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h7.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h8.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h9.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h10.bmp",".\\bitmaps\\¼Ä¤è\\ª¯¥J\\À»°h11.bmp" };
		return temp[imageNumber];
	}



}