#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "dogeAnimation.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// class dogeAnimation 狗仔動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////

	dogeAnimation::dogeAnimation() {
		x = y = 0;
	}

	void dogeAnimation::LoadBitmap() {
		image.AddBitmap(IDB_doge0, RGB(255, 0, 0));				//載入狗仔動畫圖片0
		image.AddBitmap(IDB_doge1, RGB(255, 0, 0));				//載入狗仔動畫圖片1
		image.AddBitmap(IDB_doge2, RGB(255, 0, 0));				//載入狗仔動畫圖片2
		image.AddBitmap(IDB_doge3, RGB(255, 0, 0));				//載入狗仔動畫圖片3
		image.SetDelayCount(5);									//狗仔動畫轉換延遲速度
	}

	void dogeAnimation::OnMove() {
		image.OnMove();											//狗仔動畫開始變換
	}

	void dogeAnimation::OnShow() {
		image.SetTopLeft(x, y);									// 設定狗仔座標
		image.OnShow();											//貼上狗仔
	}

	int dogeAnimation::GetX()									//取得X座標
	{
		return x;
	}

	int dogeAnimation::GetY()									//取得Y座標
	{
		return y;
	}

	void dogeAnimation::SetCoordinate(int NewX, int NewY)		//設定座標
	{
		x = NewX;
		y = NewY;
	}

	void dogeAnimation::MoveForward()
	{
		if (x < 1522) {
			x += 5;
		}
	}
}