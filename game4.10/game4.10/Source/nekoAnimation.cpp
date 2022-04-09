#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"			//需先匯入才能讀取
#include "nekoAnimation.h"


namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation 貓咪動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////
	
	nekoAnimation::nekoAnimation()
	{
		//產生此物件的初始值
		x1 = x2 = y = 0;
		IsAlive = true;
		range = 3;							//實際距離為27+3=30
		health = 100;
		attack = 1;
	}

	void nekoAnimation::LoadBitmap()
	{
		image.AddBitmap(IDB_neko0, RGB(255, 0, 0));				//載入貓咪動畫圖片0
		//image.AddBitmap(IDB_neko1, RGB(255, 0, 0));			//載入貓咪動畫圖片1
		image.AddBitmap(IDB_neko2, RGB(255, 0, 0));				//載入貓咪動畫圖片2
		image.AddBitmap(IDB_neko3, RGB(255, 0, 0));				//載入貓咪動畫圖片3
		image.AddBitmap(IDB_neko4, RGB(255, 0, 0));				//載入貓咪動畫圖片4
		image.SetDelayCount(3);									//貓咪動畫轉換延遲速度
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.Width();								//將X2設定為圖片最右邊的X座標
		image.OnMove();											//貓咪動畫開始變換
	}

	void nekoAnimation::OnShow()
	{
		if (IsAlive == true)
		{
			image.SetTopLeft(x1, y);								// 設定貓咪座標
			image.OnShow();											//貼上貓咪
		}
	}

	int nekoAnimation::GetX1()								//取得X(左)座標
	{
		return x1;
	}

	int nekoAnimation::GetX2()								//取得X(右)座標
	{
		return x2;
	}

	int nekoAnimation::GetY()								//取得Y座標
	{
		return y;
	}

	void nekoAnimation::SetCoordinate(int NewX, int NewY)		//設定座標
	{
		x1 = NewX;
		y = NewY;
	}

	void nekoAnimation::MoveForward(rivalAnimation rival)
	{
		
		if (rival.GetX2() < x1 - range) {			//判斷有無碰撞
			x1 -= 3;
			x2 -= 3;
			OnMove();
		}
		else {								//如果碰到就消失
			health -= rival.GetAttack();
			//IsAlive = false;
		}
	}

	bool nekoAnimation::GetIsAlive()
	{
		return IsAlive;
	}

	int nekoAnimation::GetAttack()
	{
		return attack;
	}

	int nekoAnimation::GetHealth()
	{
		return health;
	}


}