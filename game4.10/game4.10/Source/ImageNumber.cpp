#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "ImageNumber.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// ImageNumber:�o��class������ܾ�ƹϧΪ���O
// 
// 
/////////////////////////////////////////////////////////////////////////////

	CMovingBitmap ImageNumber::digit[11];

	ImageNumber::ImageNumber(int digits)
		: NUMDIGITS(digits)
	{
		isBmpLoaded = false;
	}

	void ImageNumber::Add(int x)
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

	int ImageNumber::GetInteger()
	{
		return n;
	}

	void ImageNumber::LoadBitmap()
	{
		//
		// digit[i]��class varibale�A�ҥH�����קK����LoadBitmap
		//
		if (!isBmpLoaded) {
			char *d[11] = { ".\\bitmaps\\number\\0.bmp",".\\bitmaps\\number\\1.bmp",".\\bitmaps\\number\\2.bmp",".\\bitmaps\\number\\3.bmp",".\\bitmaps\\number\\4.bmp",".\\bitmaps\\number\\5.bmp",".\\bitmaps\\number\\6.bmp",".\\bitmaps\\number\\7.bmp",".\\bitmaps\\number\\8.bmp",".\\bitmaps\\number\\9.bmp",".\\bitmaps\\number\\bmp10.bmp"};
			for (int i = 0; i < 11; i++)
				digit[i].LoadBitmap(d[i], RGB(255, 0, 0));
			isBmpLoaded = true;
		}
	}

	void ImageNumber::SetInteger(int i)
	{
		n = i;
	}

	void ImageNumber::SetTopLeft(int nx, int ny)		// �N�ʵe�����W���y�в��� (x,y)
	{
		x = nx; y = ny;
	}

	void ImageNumber::ShowBitmap()
	{
		GAME_ASSERT(isBmpLoaded, "CInteger: �Х�����LoadBitmap�A�M��~��ShowBitmap");
		int nx;		// ����ܦ�ƪ� x �y��
		int MSB;	// �̥���(�t�Ÿ�)����ƪ��ƭ�
		if (n >= 0) {
			MSB = n;
			nx = x ;	//nx = x + digit[0].Width()*(NUMDIGITS - 1)
		}
		else {
			MSB = -n;
			nx = x ;	//nx = x + digit[0].Width()*NUMDIGITS
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
	}

	void ImageNumber::SetDigits(int num)
	{
		NUMDIGITS = num;
	}

}