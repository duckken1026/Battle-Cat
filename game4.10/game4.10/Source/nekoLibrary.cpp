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
			range = 20;
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
			originY = 640;
		}
		else if (name == "Tank Cat") {		//Àð¿ß¸ê®Æ
			range = 3;
			health = 100;
			attack = 5;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 9;
			deathAnimationStart = 10;
			deathAnimationEnd = 20;
			deathHeightChange = 53;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 76;
			originY = 580;
		}
		else if (name == "Axe Cat") {		//¾Ô°«¿ß¸ê®Æ
			range = 25;
			health = 200;
			attack = 30;
			attackDelay = 15;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 9;
			deathAnimationStart = 10;
			deathAnimationEnd = 21;
			deathHeightChange = 57;
			moveSpeed = 5;
			imageQuantity = 22;
			headGap = 30;
			originY = 580;
		}
		else if (name == "Cow Cat") {		//¤û¿ß¸ê®Æ
			range = 20;
			health = 200;
			attack = 30;
			attackDelay = 3;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 7;
			deathAnimationStart = 8;
			deathAnimationEnd = 17;
			deathHeightChange = 0;
			moveSpeed = 10;
			imageQuantity = 18;
			headGap = 51;
			originY = 550;
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
			char *temp[21] = { ".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h9.bmp",".\\bitmaps\\¿ß«}\\Àð¿ß\\À»°h10.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Axe Cat") {		//¾Ô°«¿ß¸ê®Æ
			char *temp[22] = { ".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h9.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h10.bmp",".\\bitmaps\\¿ß«}\\¾Ô°«¿ß\\À»°h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Cow Cat") {		//¤û¿ß¸ê®Æ
			char *temp[18] = { ".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h9.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = {".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}0.bmp"};
			return temp[imageNumber];
		}
	}

}