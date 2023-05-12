#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѼĤ��Ų�����Ĥ誺�U�����
	// 
	/////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////
	//��J�Ĥ�����]�w�ƭ�
	//
	/////////////////////////////////////////////////////////////////////////////
	rivalLibrary::rivalLibrary(string name) {
		if (name == "Doge")				//���J���
		{
			range = 15;
			health = 100;
			attack = 1;
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
			originX = 180;
			originY = 640;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
		}
		else if (name == "Snache") {	//���D���
			range = 20;
			health = 200;
			attack = 50;
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
			originX = 180;
			originY = 640;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
		}
		else if (name == "Those Guys") { //�ε��_�l�����
			range = 20;
			health = 500;
			attack = 100;
			attackDelay = 13;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 17;
			deathAnimationStart = 18;
			deathAnimationEnd = 29;
			deathHeightChange = 0;
			deathXChange = 103;
			moveSpeed = 4;
			imageQuantity = 30;
			headGap = 13;
			originX = 100;
			originY = 640;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
		else if (name == "Hippoe") { //�e���N���
			range = 20;
			health = 800;
			attack = 300;
			attackDelay = 22;
			walkAnimationStart = 0;
			walkAnimationEnd = 5;
			attackAnimationStart = 6;
			attackAnimationEnd = 14;
			deathAnimationStart = 15;
			deathAnimationEnd = 27;
			deathHeightChange = 0;
			deathXChange = 0;
			moveSpeed = 2;
			imageQuantity = 28;
			headGap = 45;
			originX = -80;
			originY = 540;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
		else if (name == "Pigge") { //�޳������
			range = 20;
			health = 1000;
			attack = 500;
			attackDelay = 24;
			walkAnimationStart = 0;
			walkAnimationEnd = 9;
			attackAnimationStart = 10;
			attackAnimationEnd = 21;
			deathAnimationStart = 22;
			deathAnimationEnd = 34;
			deathHeightChange = 0;
			deathXChange = 0;
			moveSpeed = 2;
			imageQuantity = 35;
			headGap = 30;
			originX = -75;
			originY = 490;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
		else if (name == "Taiwan Base") { //�x�W������
			range = 0;
			health = 1000;
			attack = 0;
			attackDelay = 0;
			walkAnimationStart = 0;
			walkAnimationEnd = 0;
			attackAnimationStart = 0;
			attackAnimationEnd = 0;
			deathAnimationStart = 0;
			deathAnimationEnd = 0;
			deathHeightChange = 0;
			deathXChange = 0;
			moveSpeed = 1;
			imageQuantity = 1;
			headGap = 25;
			originX = 105;
			originY = 419;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
		else if (name == "Hong Kong Base") { //���䯥����
		range = 0;
		health = 2000;
		attack = 0;
		attackDelay = 0;
		walkAnimationStart = 0;
		walkAnimationEnd = 0;
		attackAnimationStart = 0;
		attackAnimationEnd = 0;
		deathAnimationStart = 0;
		deathAnimationEnd = 0;
		deathHeightChange = 0;
		deathXChange = 0;
		moveSpeed = 1;
		imageQuantity = 1;
		headGap = 25;
		originX = 105;
		originY = 419;
		walkAnimationSpeed = 1;
		attackAnimationSpeed = 1;
		}
		else if (name == "Thailand Base") { //���ꯥ����
		range = 0;
		health = 2500;
		attack = 0;
		attackDelay = 0;
		walkAnimationStart = 0;
		walkAnimationEnd = 0;
		attackAnimationStart = 0;
		attackAnimationEnd = 0;
		deathAnimationStart = 0;
		deathAnimationEnd = 0;
		deathHeightChange = 0;
		deathXChange = 0;
		moveSpeed = 1;
		imageQuantity = 1;
		headGap = 25;
		originX = 105;
		originY = 419;
		walkAnimationSpeed = 1;
		attackAnimationSpeed = 1;
		}
		else if (name == "China Base") { //���ꯥ����
		range = 0;
		health = 3000;
		attack = 0;
		attackDelay = 0;
		walkAnimationStart = 0;
		walkAnimationEnd = 0;
		attackAnimationStart = 0;
		attackAnimationEnd = 0;
		deathAnimationStart = 0;
		deathAnimationEnd = 0;
		deathHeightChange = 0;
		deathXChange = 0;
		moveSpeed = 1;
		imageQuantity = 1;
		headGap = 25;
		originX = 105;
		originY = 419;
		walkAnimationSpeed = 1;
		attackAnimationSpeed = 1;
		}
		else if (name == "Mongolia Base") { //�X�j������
		range = 0;
		health = 3500;
		attack = 0;
		attackDelay = 0;
		walkAnimationStart = 0;
		walkAnimationEnd = 0;
		attackAnimationStart = 0;
		attackAnimationEnd = 0;
		deathAnimationStart = 0;
		deathAnimationEnd = 0;
		deathHeightChange = 0;
		deathXChange = 0;
		moveSpeed = 1;
		imageQuantity = 1;
		headGap = 25;
		originX = 105;
		originY = 419;
		walkAnimationSpeed = 1;
		attackAnimationSpeed = 1;
		}
		else if (name == "Korea Base") { //���ꯥ����
		range = 0;
		health = 4000;
		attack = 0;
		attackDelay = 0;
		walkAnimationStart = 0;
		walkAnimationEnd = 0;
		attackAnimationStart = 0;
		attackAnimationEnd = 0;
		deathAnimationStart = 0;
		deathAnimationEnd = 0;
		deathHeightChange = 0;
		deathXChange = 0;
		moveSpeed = 0;
		imageQuantity = 1;
		headGap = 25;
		originX = 105;
		originY = 419;
		walkAnimationSpeed = 1;
		attackAnimationSpeed = 1;
		}
		else if (name == "Japan Base") { //�饻������
		range = 0;
		health = 4500;
		attack = 0;
		attackDelay = 0;
		walkAnimationStart = 0;
		walkAnimationEnd = 0;
		attackAnimationStart = 0;
		attackAnimationEnd = 0;
		deathAnimationStart = 0;
		deathAnimationEnd = 0;
		deathHeightChange = 0;
		deathXChange = 0;
		moveSpeed = 0;
		imageQuantity = 1;
		headGap = 25;
		originX = 105;
		originY = 419;
		walkAnimationSpeed = 1;
		attackAnimationSpeed = 1;
		}
		else if (name == "Australia Base") { //�D�j�Q�ȯ�����
			range = 0;
			health = 5000;
			attack = 0;
			attackDelay = 0;
			walkAnimationStart = 0;
			walkAnimationEnd = 0;
			attackAnimationStart = 0;
			attackAnimationEnd = 0;
			deathAnimationStart = 0;
			deathAnimationEnd = 0;
			deathHeightChange = 0;
			deathXChange = 0;
			moveSpeed = 0;
			imageQuantity = 1;
			headGap = 25;
			originX = 105;
			originY = 419;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
		else if (name == "Singapore Base") { //�s�[�Y������
			range = 0;
			health = 5500;
			attack = 0;
			attackDelay = 0;
			walkAnimationStart = 0;
			walkAnimationEnd = 0;
			attackAnimationStart = 0;
			attackAnimationEnd = 0;
			deathAnimationStart = 0;
			deathAnimationEnd = 0;
			deathHeightChange = 0;
			deathXChange = 0;
			moveSpeed = 0;
			imageQuantity = 1;
			headGap = 25;
			originX = 105;
			originY = 419;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
		else if (name == "Maldives Base") { //�����a�ү�����
			range = 0;
			health = 6000;
			attack = 0;
			attackDelay = 0;
			walkAnimationStart = 0;
			walkAnimationEnd = 0;
			attackAnimationStart = 0;
			attackAnimationEnd = 0;
			deathAnimationStart = 0;
			deathAnimationEnd = 0;
			deathHeightChange = 0;
			deathXChange = 0;
			moveSpeed = 0;
			imageQuantity = 1;
			headGap = 25;
			originX = 105;
			originY = 419;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
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
	//�Ĥ�Ϥ����J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * rivalLibrary::imageList(string name, int imageNumber)
	{
		if (name == "Doge") {		//���J���
			char *temp[21] = { ".\\bitmaps\\�Ĥ�\\���J\\����0.bmp",".\\bitmaps\\�Ĥ�\\���J\\����1.bmp",".\\bitmaps\\�Ĥ�\\���J\\����2.bmp",".\\bitmaps\\�Ĥ�\\���J\\����3.bmp",".\\bitmaps\\�Ĥ�\\���J\\����0.bmp",".\\bitmaps\\�Ĥ�\\���J\\����2.bmp",".\\bitmaps\\�Ĥ�\\���J\\����3.bmp",".\\bitmaps\\�Ĥ�\\���J\\����4.bmp",".\\bitmaps\\�Ĥ�\\���J\\����5.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h0.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h1.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h2.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h3.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h4.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h5.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h6.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h7.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h8.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h9.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h10.bmp",".\\bitmaps\\�Ĥ�\\���J\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Snache") {	//���D���
			char *temp[24] = { ".\\bitmaps\\�Ĥ�\\���D\\�樫0.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫1.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫2.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫3.bmp",".\\bitmaps\\�Ĥ�\\���D\\�樫4.bmp",".\\bitmaps\\�Ĥ�\\���D\\����0.bmp",".\\bitmaps\\�Ĥ�\\���D\\����1.bmp",".\\bitmaps\\�Ĥ�\\���D\\����2.bmp",".\\bitmaps\\�Ĥ�\\���D\\����3.bmp",".\\bitmaps\\�Ĥ�\\���D\\����4.bmp",".\\bitmaps\\�Ĥ�\\���D\\����5.bmp",".\\bitmaps\\�Ĥ�\\���D\\����6.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h0.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h1.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h2.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h3.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h4.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h5.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h6.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h7.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h8.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h9.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h10.bmp",".\\bitmaps\\�Ĥ�\\���D\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Those Guys") {//�ε��_�l�����
			char *temp[30] = { ".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫0.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫1.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫2.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\�樫3.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����0.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����1.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����2.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����3.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����4.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����5.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����6.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����7.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����8.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����9.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����10.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����11.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����12.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\����13.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h0.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h1.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h2.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h3.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h4.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h5.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h6.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h7.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h8.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h9.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h10.bmp",".\\bitmaps\\�Ĥ�\\�ε��_�l��\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Hippoe") {	//�e���N���
			char *temp[28] = { ".\\bitmaps\\�Ĥ�\\�e���N\\�樫0.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\�樫1.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\�樫2.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\�樫3.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\�樫4.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\�樫5.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����0.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����1.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����2.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����3.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����4.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����5.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����6.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����7.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\����8.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h0.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h1.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h2.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h3.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h4.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h5.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h6.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h7.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h8.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h9.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h10.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h11.bmp",".\\bitmaps\\�Ĥ�\\�e���N\\���h12.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Pigge") {		//�޳������
			char *temp[35] = { ".\\bitmaps\\�Ĥ�\\�޳���\\�樫0.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫1.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫2.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫3.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫4.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫5.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫6.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫7.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫8.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\�樫9.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����0.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����1.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����2.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����3.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����4.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����5.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����6.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����7.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����8.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����9.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����10.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\����11.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h0.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h1.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h2.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h3.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h4.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h5.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h6.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h7.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h8.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h9.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h10.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h11.bmp",".\\bitmaps\\�Ĥ�\\�޳���\\���h12.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Taiwan Base") { //�x�W������
			char *temp[1] =	 { ".\\bitmaps\\��\\�x�W.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Hong Kong Base") { //���䯥����
			char *temp[1] = { ".\\bitmaps\\��\\����.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Thailand Base") { //���ꯥ����
			char *temp[1] = { ".\\bitmaps\\��\\����.bmp" };
			return temp[imageNumber];
		}
		else if (name == "China Base") { //���ꯥ����
			char *temp[1] = { ".\\bitmaps\\��\\����.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Mongolia Base") { //�X�j������
			char *temp[1] = { ".\\bitmaps\\��\\�X�j.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Korea Base") { //���ꯥ����
			char *temp[1] = { ".\\bitmaps\\��\\����.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Japan Base") { //�饻������
			char *temp[1] = { ".\\bitmaps\\��\\�饻.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Australia Base") { //�D�j�Q�ȯ�����
			char *temp[1] = { ".\\bitmaps\\��\\�D�j�Q��.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Singapore Base") { //�s�[�Y������
			char *temp[1] = { ".\\bitmaps\\��\\�s�[�Y.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Maldives Base") { //�����a�ү�����
			char *temp[1] = { ".\\bitmaps\\��\\�����a��.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = { ".\\bitmaps\\�Ĥ�\\���J\\����0.bmp" };
			return temp[imageNumber];
		}
		
	}



}