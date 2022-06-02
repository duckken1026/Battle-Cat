#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalLibrary.h"
#include "rivalAnimation.h"
#include "nekoAnimation.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// class dogeAnimation 狗仔動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////

	rivalAnimation::rivalAnimation() {
		
		
	}

	rivalAnimation::rivalAnimation(string name)
	{
		rivalType = name;
		rivalLibrary data(rivalType);		//產生此物件的初始值

		x1 = x2 = data.originX;
		y = data.originY;
		IsAlive = true;
		range = data.range;
		health = data.health;
		attack = data.attack;
		attackDelay = data.attackDelay;	//framework一秒執行10次延遲10次就等於1秒執行一次
		delay = 1;
		walkAnimationStart = data.walkAnimationStart;
		walkAnimationEnd = data.walkAnimationEnd;
		attackAnimationStart = data.attackAnimationStart;
		attackAnimationEnd = data.attackAnimationEnd;
		deathAnimationStart = data.deathAnimationStart;
		deathAnimationEnd = data.deathAnimationEnd;
		deathDelay = 0;
		deathHeightChange = data.deathHeightChange;
		deathXChange = data.deathXChange;
		moveSpeed = data.moveSpeed;
		headGap = data.headGap;
		walkAnimationSpeed = data.walkAnimationSpeed;	
		attackAnimationSpeed = data.attackAnimationSpeed;
	}

	void rivalAnimation::LoadBitmap() 
	{
		rivalLibrary data(rivalType);
		
		//char *temp[9] = { ".\\bitmaps\\狗仔\\狗狗0.bmp",".\\bitmaps\\狗仔\\狗狗1.bmp",".\\bitmaps\\狗仔\\狗狗2.bmp",".\\bitmaps\\狗仔\\狗狗3.bmp",".\\bitmaps\\狗仔\\攻擊0.bmp",".\\bitmaps\\狗仔\\攻擊2.bmp",".\\bitmaps\\狗仔\\攻擊3.bmp",".\\bitmaps\\狗仔\\攻擊4.bmp",".\\bitmaps\\狗仔\\攻擊5.bmp"};
		for (int i = 0; i < data.imageQuantity; i++)
			image.AddBitmap(data.imageList(rivalType,i), RGB(255, 0, 0));
		image.SetDelayCount(walkAnimationSpeed);									//狗仔動畫轉換延遲速度
	}

	void rivalAnimation::OnMove() {
		x2 = x1 + image.Width();								//將X2設定為圖片最右邊的X座標
		image.OnMove();											//狗仔動畫開始變換
	}

	void rivalAnimation::OnShow() {
		
		if (IsAlive == true)			//若角色還活著會顯示在畫面
		{
			image.SetTopLeft(x1, y);								// 設定敵方座標
			image.OnShow();											// 貼上敵方
		}
		else if (IsAlive == false && deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//擊退時要將角色的Y座標做調整
			image.SetTopLeft(x1 - deathXChange, y - deathHeightChange);
			image.OnShow();
		}
		//死亡就不顯示在畫面
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
		die();						//判斷體力小於等於零，成立則執行此函數
		if (!IsAlive)				//若死亡就不在執行以下程式碼
			return;

		if (((neko->GetX1() + neko->GetHeadGap()) > x2 - headGap + range) || (neko->GetIsAlive() == false)){			//判斷有無碰撞和敵方是否活著
			x1 += moveSpeed;
			x2 += moveSpeed;
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
				neko->SetHealth(neko->GetHealth() - attack);
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

	int rivalAnimation::GetAnimationNumber()
	{
		return image.GetCurrentBitmapNumber();
	}

	void rivalAnimation::SetCurrentBitmap(int x)
	{
		image.SetCurrentBitmap(x);
	}

	int rivalAnimation::GetHeadGap()
	{
		return headGap;
	}


	void rivalAnimation::die()
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

}