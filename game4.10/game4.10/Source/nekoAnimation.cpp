#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nekoLibrary.h"
#include "rivalAnimation.h"			//需先匯入才能讀取
#include "nekoAnimation.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation 貓咪動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////
	


	nekoAnimation::nekoAnimation()
	{
	}

	nekoAnimation::nekoAnimation(string name)
	{
		nekoType = name;
		nekoLibrary data(nekoType);//產生此物件的初始值

		x1 = x2 = 1511;
		y = data.originY;
		IsAlive = true;
		range = data.range;
		health = data.health;
		attack = data.attack;
		attackDelay = data.attackDelay;		//framework一秒執行10次延遲12次就等於1.2秒執行一次
		delay = 1;
		walkAnimationStart = data.walkAnimationStart;
		walkAnimationEnd = data.walkAnimationEnd;
		attackAnimationStart = data.attackAnimationStart;
		attackAnimationEnd = data.attackAnimationEnd;
		deathAnimationStart = data.deathAnimationStart;
		deathAnimationEnd = data.deathAnimationEnd;
		deathDelay = 0;
		deathHeightChange = data.deathHeightChange;
		moveSpeed = data.moveSpeed;
		headGap = data.headGap;
		walkAnimationSpeed = data.walkAnimationSpeed;
		attackAnimationSpeed = data.attackAnimationSpeed;
	}

	void nekoAnimation::LoadBitmap()
	{
		nekoLibrary data(nekoType);//產生此物件的初始值
		for (int i = 0; i < data.imageQuantity; i++)
			image.AddBitmap(data.imageList(nekoType,i), RGB(255, 0, 0));
		image.SetDelayCount(walkAnimationSpeed);				//貓咪動畫轉換延遲速度
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.Width();								//將X2設定為圖片最右邊的X座標
		image.OnMove();											//貓咪動畫開始變換
	}

	void nekoAnimation::OnShow()
	{
		if (IsAlive == true)			//若角色還活著會顯示在畫面
		{
			image.SetTopLeft(x1, y);								// 設定貓咪座標
			image.OnShow();											//貼上貓咪
		}
		else if (IsAlive == false && deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//擊退時要將角色的Y座標做調整
			image.SetTopLeft(x1, y-deathHeightChange);
			image.OnShow();
		}
		//死亡就不顯示在畫面
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

		die();						//判斷體力小於等於零，成立則執行此函數
		if (!IsAlive)				//若死亡就不在執行以下程式碼
			return;

		if (((rival->GetX2() - rival->GetHeadGap()) < x1 + headGap - range) || (rival->GetIsAlive() == false)) {	//判斷有無碰撞和敵方是否活著
			x1 -= moveSpeed;
			x2 -= moveSpeed;
			OnMove();
			if (image.GetCurrentBitmapNumber() > walkAnimationEnd)		//若行走動畫播完了再重頭播一次
			{
				image.Reset();
				image.SetDelayCount(walkAnimationSpeed);				//設定延遲速度
			}
		}
		else {								//如果碰到開始進行攻擊
			
			if (delay == 1) {			//設定攻擊初始動畫
				image.SetDelayCount(attackAnimationSpeed);		//設定延遲速度
				image.SetCurrentBitmap(attackAnimationStart);
				delay += 1;
				OnMove();
			}
			else if (delay < (attackAnimationEnd - attackAnimationStart) + 1) {		//播放攻擊動畫
				OnMove();
				delay += 1;
			}
			else if (delay == (attackAnimationEnd - attackAnimationStart) + 1) {		//取得對方的體力每X秒扣除對方體力
				rival->SetHealth(rival->GetHealth() - attack);	
				delay += 1;
			}
			else {						//攻擊冷卻狀態
				image.SetCurrentBitmap(attackAnimationStart);
				delay += 1;
				if (delay >= attackDelay) {	//若等於冷卻時間將delay重制
					delay = 1;
				}
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

	int nekoAnimation::GetHeadGap()
	{
		return headGap;
	}

	void nekoAnimation::die()
	{
		if (health <= 0)					 //判斷體力小於等於零，成立則執行此函數
		{
			IsAlive = false;
			if (deathDelay == 0) {			//體力小於等於零後先初始化讓動畫變成第一張擊退動畫
				image.SetCurrentBitmap(deathAnimationStart);
				deathDelay++;
				image.OnMove();
			}		
			else if (deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//擊退動畫開始播放直到播完
				image.OnMove();
				deathDelay++;
			}
			
		}

	}

	string nekoAnimation::GetNekoStatus()
	{
		if (IsAlive == true) {			//還活著或還沒派出
			return "IsAlive";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) > deathDelay) {		//播放擊退時的狀態
			return "beak back";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) + 20 > deathDelay) {	//減掉貓咪總數的延遲
			deathDelay += 1;
			return "delay";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) + 20 == deathDelay) {//延遲結束貓咪總數減1
			deathDelay += 1;
			return "currentNekoQuantityMiunsOne";
		}
		else if ((deathAnimationEnd - deathAnimationStart) + 20 < deathDelay) {						//已完成任務可讓下一隻貓咪取代
			return "replaceable";
		}
		return "replaceable";
	}
}