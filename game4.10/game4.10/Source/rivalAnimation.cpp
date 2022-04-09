#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"
#include "nekoAnimation.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// class dogeAnimation 狗仔動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////

	rivalAnimation::rivalAnimation() {
		//產生此物件的初始值
		x1 = x2 = y = 0;
		IsAlive = true;			
		range = 4;						//實際距離為26+4=30
		health = 100;
		attack = 1;
	}

	void rivalAnimation::LoadBitmap() {
		image.AddBitmap(IDB_doge0, RGB(255, 0, 0));				//載入狗仔動畫圖片0
		image.AddBitmap(IDB_doge1, RGB(255, 0, 0));				//載入狗仔動畫圖片1
		image.AddBitmap(IDB_doge2, RGB(255, 0, 0));				//載入狗仔動畫圖片2
		image.AddBitmap(IDB_doge3, RGB(255, 0, 0));				//載入狗仔動畫圖片3
		image.SetDelayCount(5);									//狗仔動畫轉換延遲速度
	}

	void rivalAnimation::OnMove() {
		x2 = x1 + image.Width();								//將X2設定為圖片最右邊的X座標
		image.OnMove();											//狗仔動畫開始變換
	}

	void rivalAnimation::OnShow() {
		if (IsAlive == true)
		{
			image.SetTopLeft(x1, y);								// 設定狗仔座標
			image.OnShow();											//貼上狗仔
		}
	}

	int rivalAnimation::GetX1()									//取得X座標
	{
		return x1;
	}

	int rivalAnimation::GetX2()
	{
		return x2;
	}

	int rivalAnimation::GetY()									//取得Y座標
	{
		return y;
	}

	void rivalAnimation::SetCoordinate(int NewX, int NewY)		//設定座標
	{
		x1 = NewX;
		y = NewY;
	}

	void rivalAnimation::MoveForward(nekoAnimation neko)
	{
		if (neko.GetX1() > x2 + range) {			//判斷有無碰撞
			x1 += 5;
			x2 += 5;
		}
		else {								//如果碰到就消失
			//IsAlive = false;
		}

	}

	bool rivalAnimation::GetIsAlive()
	{
		return IsAlive;
	}

	int rivalAnimation::GetAttack()
	{
		return attack;
	}

	int rivalAnimation::GetHealth()
	{
		return health;
	}

}