#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "ImageNumber.h"
#include "nekoButton.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// ImageNumber:這個class提供顯示角色按鈕的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////



	void nekoButton::LoadBitmap()
	{
		char *d[11] = { ".\\bitmaps\\neko button\\Cat.bmp",".\\bitmaps\\neko button\\Tank Cat.bmp"};
		for (int i = 0; i < 1; i++) {
			button[i].LoadBitmap(d[i]);
		}
			
	}

	void nekoButton::ShowBitmap()
	{
		for (int i = 0; i < 1; i++) {
			button[i].ShowBitmap();
		}
	}

	void nekoButton::SetTopLeft()
	{
		for (int i = 0; i < 1; i++) {
			button[i].SetTopLeft(271,840);
		}
	}

}