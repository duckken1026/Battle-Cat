#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nekoLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ³o­Óclass´£¨Ñ¿ß«}¹ÏÅ²¦¬¶°¿ß«}ªº¦U¶µ¸ê®Æ
	// 
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	//¿é¤J¿ß«}ºØÃþ³]©w¼Æ­È
	//
	/////////////////////////////////////////////////////////////////////////////
	nekoLibrary::nekoLibrary(string name)	
	{
		if (name == "Cat") {				//¿ß«}¸ê®Æ
			range = 4;
			health = 100;
			attack = 1;
			attackDelay = 10;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 17;
			headGap = 27;			
		}
		else if (name == "Tank Cat") {		//Àð¿ß¸ê®Æ
			range = 3;
			health = 100;
			attack = 5;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 10;
			headGap = 76;
		}
		
		
	}
	/////////////////////////////////////////////////////////////////////////////
	//¿ß«}¹Ï¤ù¸ü¤J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * nekoLibrary::imageList(string name,int imageNumber)
	{
		if (name == "Cat") {				//¿ß«}¸ê®Æ
			char *temp[17] = { ".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}0.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}1.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}2.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}3.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\¿ß«}\\À»°h7.bmp" };
			return temp[imageNumber];
		}
		else if(name == "Tank Cat") {		//Àð¿ß¸ê®Æ
			char *temp[10] = { ".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»5.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = {".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}0.bmp"};
			return temp[imageNumber];
		}
	}

}