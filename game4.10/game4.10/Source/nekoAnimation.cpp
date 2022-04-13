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
		attackDelay = 20;				//framework一秒執行10次延遲12次就等於1.2秒執行一次
		delay = 1;				
		walkAnimationStart = 0;
		walkAnimationEnd = 3;
		attackAnimationStart = 4;
		attackAnimationEnd = 8;
	}

	void nekoAnimation::LoadBitmap()
	{
		char *temp[9] = {".\\bitmaps\\貓咪\\貓咪0.bmp",".\\bitmaps\\貓咪\\貓咪1.bmp",".\\bitmaps\\貓咪\\貓咪2.bmp",".\\bitmaps\\貓咪\\貓咪3.bmp",".\\bitmaps\\貓咪\\攻擊0.bmp",".\\bitmaps\\貓咪\\攻擊1.bmp",".\\bitmaps\\貓咪\\攻擊3.bmp",".\\bitmaps\\貓咪\\攻擊4.bmp",".\\bitmaps\\貓咪\\攻擊5.bmp"};
		for (int i = 0; i < 9; i++)
			image.AddBitmap(temp[i], RGB(255, 0, 0));
		image.SetDelayCount(3);									//貓咪動畫轉換延遲速度
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.Width();								//將X2設定為圖片最右邊的X座標
		image.OnMove();											//貓咪動畫開始變換
	}

	void nekoAnimation::OnShow()
	{
		//if (IsAlive == true)
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

	void nekoAnimation::MoveForward(rivalAnimation *rival)
	{

		if (!IsAlive)				//若死亡就不在執行以下程式碼
			return;

		die();						//判斷體力小於等於零，成立則執行此函數	

		if ((rival->GetX2() < x1 - range) || (rival->GetIsAlive() == false)){	//判斷有無碰撞和敵方是否活著
			x1 -= 3;
			x2 -= 3;
			OnMove();
			if (image.GetCurrentBitmapNumber() == walkAnimationEnd + 1)		//若行走動畫播完了再重頭播一次
			{
				image.Reset();
				image.SetDelayCount(3);				//設定延遲速度
			}
		}
		else {								//如果碰到開始進行攻擊
			
			if (delay >= attackDelay)		//若延遲1秒後攻擊對方
			{
				rival->SetHealth(rival->GetHealth() - attack);	//取得對方的體力每X秒扣除對方體力***
				delay = 1;										//將延遲重制
				image.SetCurrentBitmap(4);
			}
			else if (delay >= attackDelay - (attackAnimationEnd - attackAnimationStart))	//攻擊動畫開始
			{
				OnMove();
				delay += 1;
			}
			else												//停止不動
			{
				image.SetDelayCount(1);							//設定延遲速度
				image.SetCurrentBitmap(4);
				delay += 1;					
			}
			
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

	void nekoAnimation::SetHealth(int NewHealth)
	{
		health = NewHealth;
	}

	int nekoAnimation::GetAnimationNumber()
	{
		return image.GetCurrentBitmapNumber();
	}

	void nekoAnimation::SetCurrentBitmap(int x)
	{
		image.SetCurrentBitmap(x);
	}

	void nekoAnimation::die()
	{
		if (health <= 0)					 //判斷體力小於等於零，成立則執行此函數
		{
			IsAlive = false;
			x1 += 15;
			x2 += 15;
			y = 0;
		}
	}


}