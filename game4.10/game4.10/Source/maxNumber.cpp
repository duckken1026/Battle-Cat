#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "maxNumber.h"

namespace game_framework {


	/////////////////////////////////////////////////////////////////////////////
	// maxNumber:�o��class������̤ܳj��ƹϧΪ���O
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
		int quotient = n;			//�ھڦ��Ӽƥh�p�⦹�Ʀ��X���
		int digit = 0;				//��X�����
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
		// digit[i]��class varibale�A�ҥH�����קK����LoadBitmap
		//
		if (!isBmpLoaded) {
			char *d[13] = { ".\\bitmaps\\number\\0.bmp",".\\bitmaps\\number\\1.bmp",".\\bitmaps\\number\\2.bmp",".\\bitmaps\\number\\3.bmp",".\\bitmaps\\number\\4.bmp",".\\bitmaps\\number\\5.bmp",".\\bitmaps\\number\\6.bmp",".\\bitmaps\\number\\7.bmp",".\\bitmaps\\number\\8.bmp",".\\bitmaps\\number\\9.bmp",".\\bitmaps\\number\\bmp10.bmp",".\\bitmaps\\number\\slash.bmp",".\\bitmaps\\number\\��.bmp" };
			for (int i = 0; i < 13; i++)
				digit[i].LoadBitmap(d[i], RGB(255, 0, 0));
			isBmpLoaded = true;
		}
	}

	void maxNumber::SetInteger(int i)
	{
		n = i;
	}

	void maxNumber::SetTopLeft(int nx, int ny)		// �N�ʵe�����W���y�в��� (x,y)
	{
		x = nx; y = ny;
	}

	void maxNumber::ShowBitmap()
	{
		GAME_ASSERT(isBmpLoaded, "CInteger: �Х�����LoadBitmap�A�M��~��ShowBitmap");
		int nx;		// ����ܦ�ƪ� x �y��
		int MSB;	// �̥���(�t�Ÿ�)����ƪ��ƭ�
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
		if (n < 0) { // �p�G�p��0�A�h��ܭt��
			digit[10].SetTopLeft(nx, y);
			digit[10].ShowBitmap();
		}
		digit[11].SetTopLeft(nx, y);		//�]�wslash�y��
		digit[11].ShowBitmap();				//���slash�Ϥ�
		digit[12].SetTopLeft(nx + (NUMDIGITS + 1)* digit[0].Width(), y);//�]�w���y��
		digit[12].ShowBitmap();				//��ܤ��Ϥ�
	}

	void maxNumber::SetDigits(int num)
	{
		NUMDIGITS = num;
	}

}