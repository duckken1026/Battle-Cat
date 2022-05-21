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
			walkAnimationSpeed = 2;	
			attackAnimationSpeed = 1;
			buttonDelay = 10;
		}
		else if (name == "Tank Cat") {		//Àð¿ß¸ê®Æ
			range = 3;
			health = 1000;
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
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 20;
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
			moveSpeed = 4;
			imageQuantity = 22;
			headGap = 30;
			originY = 580;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 30;
		}
		else if (name == "Gross Cat") {		//äú¤ß¿ß¸ê®Æ
			range = 50;
			health = 400;
			attack = 200;
			attackDelay = 42;
			walkAnimationStart = 0;
			walkAnimationEnd = 5;
			attackAnimationStart = 6;
			attackAnimationEnd = 12;
			deathAnimationStart = 13;
			deathAnimationEnd = 24;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 25;
			headGap = 221;
			originY = 360;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 40;
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
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 40;
		}
		else if (name == "Bird Cat") {		//³¾¿ß¸ê®Æ
			range = 30;
			health = 300;
			attack = 140;
			attackDelay = 16;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 10;
			deathAnimationStart = 11;
			deathAnimationEnd = 20;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 112;
			originY = 490;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
			buttonDelay = 50;
		}
		else if (name == "Fish Cat") {		//³½¿ß¸ê®Æ
			range = 25;
			health = 1000;
			attack = 180;
			attackDelay = 17;
			walkAnimationStart = 0;
			walkAnimationEnd = 10;
			attackAnimationStart = 11;
			attackAnimationEnd = 16;
			deathAnimationStart = 17;
			deathAnimationEnd = 28;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 29;
			headGap = 73;
			originY = 510;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
			buttonDelay = 60;
		}
		else if (name == "Lizard Cat") {		//»h»i¿ß¸ê®Æ
			range = 100;
			health = 100;
			attack = 350;
			attackDelay = 40;
			walkAnimationStart = 0;
			walkAnimationEnd = 6;
			attackAnimationStart = 7;
			attackAnimationEnd = 12;
			deathAnimationStart = 13;
			deathAnimationEnd = 30;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 31;
			headGap = 208;
			originY = 550;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
			buttonDelay = 70;
		}
		else if (name == "Titan Cat") {		//¥¨¯«¿ß¸ê®Æ
			range = 25;
			health = 100;
			attack = 280;
			attackDelay = 22;
			walkAnimationStart = 0;
			walkAnimationEnd = 5;
			attackAnimationStart = 6;
			attackAnimationEnd = 26;
			deathAnimationStart = 27;
			deathAnimationEnd = 36;
			deathHeightChange = 0;
			moveSpeed = 2;
			imageQuantity = 37;
			headGap = 85;
			originY = 400;
			walkAnimationSpeed = 3;
			attackAnimationSpeed = 1;
			buttonDelay = 80;
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
		else if (name == "Gross Cat") {		//äú¤ß¿ß¸ê®Æ
			char *temp[25] = { ".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«4.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«5.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\¦æ¨«4.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\§ðÀ»6.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\§ðÀ»7.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\§ðÀ»8.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h9.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h10.bmp",".\\bitmaps\\¿ß«}\\äú¤ß¿ß\\À»°h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Cow Cat") {		//¤û¿ß¸ê®Æ
			char *temp[18] = { ".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\¤û¿ß\\À»°h9.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Bird Cat") {		//³¾¿ß¸ê®Æ
			char *temp[21] = { ".\\bitmaps\\¿ß«}\\³¾¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\§ðÀ»6.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\³¾¿ß\\À»°h9.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Fish Cat") {		//³½¿ß¸ê®Æ
			char *temp[29] = { ".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«4.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«5.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«6.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«7.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«8.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«9.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\¦æ¨«10.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h9.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h10.bmp",".\\bitmaps\\¿ß«}\\³½¿ß\\À»°h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Lizard Cat") {	//»h»i¿ß¸ê®Æ
			char *temp[31] = { ".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«4.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«5.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\¦æ¨«6.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h9.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h10.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h11.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h12.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h13.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h14.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h15.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h16.bmp",".\\bitmaps\\¿ß«}\\»h»i¿ß\\À»°h17.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Titan Cat") {	//¥¨¯«¿ß¸ê®Æ
			char *temp[37] = { ".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\¦æ¨«0.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\¦æ¨«1.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\¦æ¨«2.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\¦æ¨«3.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\¦æ¨«4.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\¦æ¨«5.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»0.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»1.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»2.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»3.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»4.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»5.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»6.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»7.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»8.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»9.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»10.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»11.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»12.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»13.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»14.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»15.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»16.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»17.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»18.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»19.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\§ðÀ»20.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h0.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h1.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h2.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h3.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h4.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h5.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h6.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h7.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h8.bmp",".\\bitmaps\\¿ß«}\\¥¨¯«¿ß\\À»°h9.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = {".\\bitmaps\\¿ß«}\\¿ß«}\\¿ß«}0.bmp"};
			return temp[imageNumber];
		}
	}

}