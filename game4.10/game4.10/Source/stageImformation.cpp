#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "stageImformation.h"

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// stageImformation:�o��class�������d��T����O
	// 
	// 
	/////////////////////////////////////////////////////////////////////////////
	CMovingBitmap stageImformation::BackGround[10];
	CMovingBitmap stageImformation::Name[10];
	stageImformation::stageImformation()
	{
		isBmpLoaded = false;
	}

	string stageImformation::getRivalBase(int stage)
	{
		return stageRivalBase[stage-1];
	}

	string stageImformation::getRival(int stage)
	{
		return stageRival[stage-1];
	}

	int stageImformation::getStageDelay(int stage)
	{
		return stageDelay[stage-1];
	}

	void stageImformation::LoadBitmap()
	{
		if (!isBmpLoaded) {
			char *background[10] = { ".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\����.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\�]��.bmp",".\\bitmaps\\�I��\\��a.bmp" ,".\\bitmaps\\�I��\\��a.bmp" ,".\\bitmaps\\�I��\\���y.bmp" };
			char *name[10] = { ".\\bitmaps\\���d�W��\\�x�W.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\�X�j.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\�饻.bmp", ".\\bitmaps\\���d�W��\\�D�j�Q��.bmp", ".\\bitmaps\\���d�W��\\�s�[�Y.bmp", ".\\bitmaps\\���d�W��\\�����a��.bmp" };
			for (int i = 0; i < 10; i++) {
				BackGround[i].LoadBitmap(background[i],RGB(255,0,0));
				BackGround[i].SetTopLeft(0,0);
				Name[i].LoadBitmap(name[i],RGB(255, 0, 0));
				Name[i].SetTopLeft(110, 3);
			}
			isBmpLoaded = true;
		}
	}

	void stageImformation::ShowBitmapBackGround(int stage)
	{
		BackGround[stage - 1].ShowBitmap();
	}

	void stageImformation::ShowBitmapName(int stage)
	{
		Name[stage - 1].ShowBitmap();
	}
}