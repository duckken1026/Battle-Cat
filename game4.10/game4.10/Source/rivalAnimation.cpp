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
		attackDelay = 20;				//framework一秒執行10次延遲10次就等於1秒執行一次
		delay = 1;
	}

	void rivalAnimation::LoadBitmap() {
		char *temp[4] = { ".\\bitmaps\\狗仔\\狗狗0.bmp",".\\bitmaps\\狗仔\\狗狗1.bmp",".\\bitmaps\\狗仔\\狗狗2.bmp",".\\bitmaps\\狗仔\\狗狗3.bmp"};
		for (int i = 0; i < 4; i++)
			image.AddBitmap(temp[i], RGB(255, 0, 0));
		//image.AddBitmap(IDB_doge0, RGB(255, 0, 0));				//載入狗仔動畫圖片0
		//image.AddBitmap(IDB_doge1, RGB(255, 0, 0));				//載入狗仔動畫圖片1
		//image.AddBitmap(IDB_doge2, RGB(255, 0, 0));				//載入狗仔動畫圖片2
		//image.AddBitmap(IDB_doge3, RGB(255, 0, 0));				//載入狗仔動畫圖片3
		image.SetDelayCount(5);									//狗仔動畫轉換延遲速度
	}

	void rivalAnimation::OnMove() {
		x2 = x1 + image.Width();								//將X2設定為圖片最右邊的X座標
		image.OnMove();											//狗仔動畫開始變換
	}

	void rivalAnimation::OnShow() {
		//if (IsAlive == true)
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

	void rivalAnimation::MoveForward(nekoAnimation *neko)
	{

		if (!IsAlive)				//若死亡就不在執行以下程式碼
			return;

		die();						//判斷體力小於等於零，成立則執行此函數

		if ((neko->GetX1() > x2 + range) || (neko->GetIsAlive() == false)){			//判斷有無碰撞和敵方是否活著

			x1 += 5;
			x2 += 5;
			OnMove();
		}
		else {								//如果碰到開始進行攻擊

			if (delay >= attackDelay)		//若延遲1秒後攻擊對方
			{
				neko->SetHealth(neko->GetHealth() - attack);	//取得對方的體力每X秒扣除對方體力***
				delay = 1;										//將延遲重制
			}
			else
			{
				delay += 1;
			}

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

	void rivalAnimation::SetHealth(int NewHealth)
	{
		health = NewHealth;
	}

	void rivalAnimation::die()
	{
		if (health <= 0)					 //判斷體力小於等於零，成立則執行此函數
		{
			IsAlive = false;
			x1 -= 15;
			x2 -= 15;
			y = 0;
		}
	}

}