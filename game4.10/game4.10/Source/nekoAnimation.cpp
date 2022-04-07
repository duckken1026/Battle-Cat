#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nekoAnimation.h"


namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation 貓咪動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////
	
	nekoAnimation::nekoAnimation()
	{
		x = y = 0;
	}

	void nekoAnimation::LoadBitmap()
	{
		image.AddBitmap(IDB_neko0, RGB(255, 0, 0));				//載入貓咪動畫圖片0
		//image.AddBitmap(IDB_neko1, RGB(255, 0, 0));				//載入貓咪動畫圖片1
		image.AddBitmap(IDB_neko2, RGB(255, 0, 0));				//載入貓咪動畫圖片2
		image.AddBitmap(IDB_neko3, RGB(255, 0, 0));				//載入貓咪動畫圖片3
		image.AddBitmap(IDB_neko4, RGB(255, 0, 0));				//載入貓咪動畫圖片4
		image.SetDelayCount(3);									//貓咪動畫轉換延遲速度
	}

	void nekoAnimation::OnMove()
	{
		image.OnMove();											//貓咪動畫開始變換
	}

	void nekoAnimation::OnShow()
	{
		image.SetTopLeft(x, y);								// 設定貓咪座標
		image.OnShow();											//貼上貓咪
	}

	int nekoAnimation::GetX()								//取得X座標
	{
		return x;
	}

	int nekoAnimation::GetY()								//取得Y座標
	{
		return y;
	}

	void nekoAnimation::SetCoordinate(int NewX, int NewY)		//設定座標
	{
		x = NewX;
		y = NewY;
	}

	void nekoAnimation::MoveForward()
	{
		if (x > 285) {
			x -= 3;
		}
	}



}