/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////
int stage = 1;			//選中的關卡
CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0);	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	//logo.LoadBitmap(IDB_BACKGROUND);
	MainMenu.LoadBitmap(".\\bitmaps\\遊戲主畫面.bmp");
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
	CAudio::Instance()->Load(AUDIO_Beginning, "sounds\\beginning.mp3");		//Load 開頭音樂
	CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play 開頭音樂
}

void CGameStateInit::OnBeginState()
{
	
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE) {
		GotoGameState(GAME_STATE_Stage_Select);				// 切換至GAME_STATE_Stage_Select
		CAudio::Instance()->Stop(AUDIO_Beginning);
	}
	else if (nChar == KEY_ESC) {								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ((point.x >= 575 && point.x <= 1337) && (point.y >= 592 && point.y <= 700)) {
		GotoGameState(GAME_STATE_Stage_Select);		// 切換至GAME_STATE_Stage_Select
		CAudio::Instance()->Stop(AUDIO_Beginning);
	}
}

void CGameStateInit::OnShow()
{
	//
	// 貼上logo
	//

	//logo.SetTopLeft((SIZE_X - logo.Width())/2, SIZE_Y/8);
	//logo.ShowBitmap();
	MainMenu.ShowBitmap();
	//
	// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
	//
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	pDC->TextOut(5,895,"Press Ctrl-F to switch in between window mode and full screen mode.");
	if (ENABLE_GAME_PAUSE)
		pDC->TextOut(5,925,"Press Ctrl-Q to pause the Game.");
	pDC->TextOut(5,955,"Press Alt-F4 or ESC to Quit.");
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
}								

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateStageSelect::CGameStateStageSelect(CGame *g)
	: CGameState(g)
{
}

void CGameStateStageSelect::OnInit()
{
	stageSelect.LoadBitmap();
	back.LoadBitmap(".\\bitmaps\\返回.bmp", RGB(255, 0, 0));
	back.SetTopLeft(10,920);
	start.LoadBitmap(".\\bitmaps\\戰鬥開始.bmp", RGB(255,0,0));
	start.SetTopLeft(1280,920);
	CAudio::Instance()->Load(AUDIO_Stage, "sounds\\Preparation.mp3");		//Load 開頭音樂
	
}

void CGameStateStageSelect::OnBeginState()
{
	CAudio::Instance()->Play(AUDIO_Stage, true);
}

void CGameStateStageSelect::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 37;
	const char KEY_RIGHT = 39;
	if (nChar == KEY_LEFT) {
		stageSelect.clickLeft();
	}
	else if (nChar == KEY_RIGHT) {
		stageSelect.clickRight();
	}
}

void CGameStateStageSelect::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ((point.y >= 140 && point.y < 920) &&(point.x>960 && point.x<=1920)) {
		stageSelect.clickRight();
	}
	if ((point.y >= 140 && point.y < 920) && (point.x >= 0 && point.x <= 960)) {
		stageSelect.clickLeft();
	}
	if ((point.y >= 920 && point.y <= 1102) && (point.x >= 10 && point.x <= 243)) {
		GotoGameState(GAME_STATE_INIT);				// 切換至GAME_STATE_INIT
		CAudio::Instance()->Stop(AUDIO_Stage);
		CAudio::Instance()->Play(AUDIO_Beginning, true);
	}
	if ((point.y >= 920 && point.y <= 1089) && (point.x >= 1280 && point.x <= 1945)) {
		stage = stageSelect.getStage();
		GotoGameState(GAME_STATE_RUN);				// 切換至GAME_STATE_RUN
		CAudio::Instance()->Stop(AUDIO_Stage);
	}
}

void CGameStateStageSelect::OnShow()
{
	stageSelect.ShowBitmap();
	back.ShowBitmap();
	start.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play 開頭音樂
		GotoGameState(GAME_STATE_INIT);
	}
		
}

void CGameStateOver::OnBeginState()
{
	counter = 10 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)", counter / 10);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態貓咪獲勝
/////////////////////////////////////////////////////////////////////////////
CGameStateNekoWin::CGameStateNekoWin(CGame *g)
	: CGameState(g)
{
}

void CGameStateNekoWin::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Stop(AUDIO_Victory);
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play 開頭音樂
		GotoGameState(GAME_STATE_INIT);
	}

}

void CGameStateNekoWin::OnBeginState()
{
	counter = 10 * 10; // 10 seconds
	CAudio::Instance()->Play(AUDIO_Victory);
}

void CGameStateNekoWin::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
	winPhoto.LoadBitmap(".\\bitmaps\\大獲全勝.bmp");
	winPhoto.SetTopLeft(370,200);
	CAudio::Instance()->Load(AUDIO_Victory, "sounds\\Victory.mp3");		//Load 勝利音效

}

void CGameStateNekoWin::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "(%d)", counter / 10);
	pDC->TextOut(900, 700, str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	winPhoto.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態敵人獲勝
/////////////////////////////////////////////////////////////////////////////
CGameStateRivalWin::CGameStateRivalWin(CGame *g)
	: CGameState(g)
{
}

void CGameStateRivalWin::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Stop(AUDIO_Defeat);
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play 開頭音樂
		GotoGameState(GAME_STATE_INIT);
	}

}

void CGameStateRivalWin::OnBeginState()
{
	counter = 10 * 10; // 10 seconds
	CAudio::Instance()->Play(AUDIO_Defeat);
}

void CGameStateRivalWin::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
	winPhoto.LoadBitmap(".\\bitmaps\\慘敗.bmp");
	winPhoto.SetTopLeft(500, 200);
	CAudio::Instance()->Load(AUDIO_Defeat, "sounds\\Defeat.mp3");		//Load 失敗音效
	
}

void CGameStateRivalWin::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "(%d)", counter / 10);
	pDC->TextOut(900, 700, str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	winPhoto.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g), NUMBALLS(28), maxNeko(20),maxRival(3)
{
	ball = new CBall [NUMBALLS];	
	Rival = new rivalAnimation[maxRival + 1];//加上一個敵方主塔
	Neko = new nekoAnimation[maxNeko + 1];//加上一個貓咪主塔
	for (int i = 0; i < maxNeko; i++) {
		Neko[i] = nekoAnimation("Cat");
	}
	Neko[maxNeko] = nekoAnimation("Neko Base");		//貓咪主塔
	for (int i = 0; i < maxRival; i++) {
		Rival[i] = rivalAnimation("Doge");
	}
	Rival[maxRival] = rivalAnimation("Taiwan Base");//敵方主塔
	neko = nekoAnimation("Cat");
	neko2 = nekoAnimation("Cat");
	doge = rivalAnimation("Pigge");
	neko.SetCoordinate(0,-101);
}

CGameStateRun::~CGameStateRun()
{
	delete [] ball;
	delete [] Neko;
	delete [] Rival;
}

void CGameStateRun::OnBeginState()
{
	CAudio::Instance()->Stop(AUDIO_Beginning);		//Close 開頭音樂
	const int BALL_GAP = 90;
	const int BALL_XY_OFFSET = 45;
	const int BALL_PER_ROW = 7;
	const int HITS_LEFT = 10;
	const int HITS_LEFT_X = 590;
	const int HITS_LEFT_Y = 0;
	const int BACKGROUND_X = 60;
	const int ANIMATION_SPEED = 15;
	for (int i = 0; i < NUMBALLS; i++) {				// 設定球的起始座標
		int x_pos = i % BALL_PER_ROW;
		int y_pos = i / BALL_PER_ROW;
		ball[i].SetXY(x_pos * BALL_GAP + BALL_XY_OFFSET, y_pos * BALL_GAP + BALL_XY_OFFSET);
		ball[i].SetDelay(x_pos);
		ball[i].SetIsAlive(true);
	}
	//eraser.Initialize();
	background.SetTopLeft(BACKGROUND_X,0);				// 設定背景的起始座標
	help.SetTopLeft(0, SIZE_Y - help.Height());			// 設定說明圖的起始座標
	hits_left.SetInteger(HITS_LEFT);					// 指定剩下的撞擊數
	hits_left.SetTopLeft(HITS_LEFT_X,HITS_LEFT_Y);		// 指定剩下撞擊數的座標
	stopButton.SetTopLeft(0,0);							//設定中止按鈕顯示的座標
	currentMoney.SetDigits(1);
	currentMoney.SetInteger(0);							//設定現有金額初始值為0
	currentMoney.SetTopLeft(1520, 0);					//設定現有金額顯示的座標
	maxMoney.SetDigits(3);								//設定現有最大金額位數
	maxMoney.SetInteger(300);							//設定現有最大金額初始值
	maxMoney.SetTopLeft(1594, 0);						//設定最大金額顯示的座標
	workCat.SetTopLeft();								//設定工作貓按鈕的座標
	workCat.SetInitLevel();								//設定初始工作貓等級
	Button.setClickedTimes(0);							//設定按鈕按下次數為0初始值
	activateNeko = 0;									//設定Neko陣列中已出動貓咪的數量
	currentNekoQuantity = 0;							//目前顯示在畫面中的貓咪數量
	readyToFightNeko = -1;								//設定下一個要派出的貓咪在Neko陣列的哪一個值
	activateRival = 0;									//設定Rival陣列中已出動敵方的數量
	currentRivalQuantity = 0;							//目前顯示在畫面中的敵方數量
	readyToFightRival = -1;								//設定下一個要派出的敵方在Rival陣列的哪一個值
	moneyDelay = 0;										//金錢增加速度延遲
	rivalDelay = 0;										//派出敵人延遲時間
	//CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
	//CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
	CAudio::Instance()->Play(AUDIO_BackgroundMusic, true);			// 撥放 背景音樂
	Neko[maxNeko].SetHealth(1000);						//設定砲塔生命值
	Rival[maxRival] = rivalAnimation(stageData.getRivalBase(stage));//敵方主塔
	Rival[maxRival].LoadBitmap();
	for (int i = 0; i < maxNeko; i++) {
		Neko[i] = nekoAnimation("Cat");
	}
	for (int i = 0; i < maxRival; i++) {
		Rival[i] = rivalAnimation("Doge");
	}
	
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//Mybase.SetTopLeft(1650,419);						// 設定我方砲塔座標
	//Rivalbase.SetTopLeft(105, 419);						// 設定敵方砲塔座標
	//giant.SetTopLeft(1500, 500);
	Neko[maxNeko].MoveForward(&doge);					//將貓咪砲塔派出
	Rival[maxRival].MoveForward(&neko);					//將敵方砲塔派出
	neko.OnMove();										//貓咪動畫開始變換
	if (neko.GetAnimationNumber() == 0) {
		neko.SetCurrentBitmap(9);
	}



	if (currentRivalQuantity < maxRival) {
		if (rivalDelay / 50 >= 1) {						    //每隔10秒派出一隻敵人
			rivalDelay = 0;									//重設RivalDelay
			int findDisappearRival = 0;						//找出Rival陣列哪一個敵方已擊退的變數

			if (activateRival < maxRival) {			//如果已派出的敵人小於20隻，readyToFightRival就依序加一
				activateRival += 1;
				readyToFightRival += 1;
				currentRivalQuantity += 1;			//目前畫面上敵方總數加一
				Rival[readyToFightRival] = rivalAnimation("Doge");//傳入敵方的名字然後載入敵方資料
				Rival[readyToFightRival].LoadBitmap();		//去讀取該敵方的圖片
			}
			else {									//如果超過20隻就要等畫面敵方總數小於20隻，再去尋找Rival陣列中的敵方哪個已經被擊退
				while (findDisappearRival < maxRival) {
					if (Rival[findDisappearRival].GetRivalStatus() == "replaceable" && activateRival == maxRival) {
						readyToFightRival = findDisappearRival;
						currentRivalQuantity += 1;			//目前畫面上敵方總數加一
						Rival[readyToFightRival] = rivalAnimation("Doge");//傳入敵方的名字然後載入敵方資料
						Rival[readyToFightRival].LoadBitmap();		//去讀取該敵方的圖片
						break;
					}
					if (findDisappearRival < maxRival) {
						findDisappearRival += 1;
					}
				}
			}
			
		}
	}
	
	rivalDelay += 1;
	
	currentRivalQuantity = 0;
	for (int i = 0; i < maxRival; i++) {
		if (Rival[i].GetRivalStatus() == "IsOnScreen") {		//計算現在在畫面上的敵方
			currentRivalQuantity += 1;
		}
	}

	for (int i = 0; i < activateRival; i++) {			//派出敵方
		Rival[i].MoveForward(&Neko[NekoDetector.findTarget(Neko, maxNeko)]);
	}

	if (Button.getClickedTimes() <= maxNeko) {			//若按下的次數還沒大於maxNeko
	activateNeko = Button.getClickedTimes();			//activateNeko加一
	}
	
	currentNekoQuantity = 0;
	for (int i = 0; i < maxNeko; i++) {
		if (Neko[i].GetNekoStatus() == "IsOnScreen") {		//計算現在在畫面上的貓咪
			currentNekoQuantity += 1;
		}
	}

	for (int i = 0; i < activateNeko; i++) {			//派出貓咪
		Neko[i].MoveForward(&Rival[RivalDetector.findTarget(Rival, maxRival)]);
	}
	
	//neko2.OnMove();									//貓咪動畫開始變換
	//neko2.MoveForward(&Rival[0]);
	
	//doge.OnMove();										//貓咪動畫開始變換
	
	//doge.MoveForward(&Neko[NekoDetector.findTarget(Neko,maxNeko)]);
	Button.SetTopLeft();									//設定按鈕位置
	MaxNekoText.SetTopLeft(795,350);						//設定無法出擊文字位置
	
	//
	// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	// 移動背景圖的座標
	//
	if (background.Top() > SIZE_Y)
		background.SetTopLeft(60 ,-background.Height());
	background.SetTopLeft(background.Left(),background.Top()+1);
	//
	// 移動球
	//
	int i;
	for (i=0; i < NUMBALLS; i++)
		ball[i].OnMove();
	//
	// 移動擦子
	//
	//eraser.OnMove();
	//
	// 判斷擦子是否碰到球
	//
	if (moneyDelay >= 3){//延遲時間為(100ms* x)
		if (currentMoney.GetInteger() < maxMoney.GetInteger()) {	//若現有金額小於最大金額現有金額將會持續加一
			if (currentMoney.GetInteger() + workCat.addSpeed[workCat.getCurrentLevel() - 1] > maxMoney.GetInteger()) { //若加完後超過最大金額
				currentMoney.Add(maxMoney.GetInteger() - currentMoney.GetInteger());//若會超過最大金額只加上值到最大值
			}
			else {
				currentMoney.Add(workCat.addSpeed[workCat.getCurrentLevel() - 1]);//每隔100毫秒加1到目前金額
			}
			moneyDelay = 0;
		}
	}
	moneyDelay += 1;
	
	Button.updateAffordable(currentMoney.GetInteger());	//更新目前這隻貓是否有足夠的錢派出
	workCat.checkAffordable(currentMoney.GetInteger());	//檢查是否有足夠金額升級工作貓


	//for (i=0; i < NUMBALLS; i++)
		//if (ball[i].IsAlive() && ball[i].HitEraser(&eraser)) {
			//ball[i].SetIsAlive(false);
			//CAudio::Instance()->Play(AUDIO_DING);
			//hits_left.Add(-1);
			//
			// 若剩餘碰撞次數為0，則跳到Game Over狀態
			//
			//if (hits_left.GetInteger() <= 0) {
			//	CAudio::Instance()->Stop(AUDIO_LAKE);	// 停止 WAVE
			//	CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// 停止 背景音樂
			//	GotoGameState(GAME_STATE_OVER);
			//}
		//}
	//
	// 移動彈跳的球
	//
	bball.OnMove();
	if (Neko[maxNeko].GetHealth() <= 0) {					//若敵方獲勝
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// 停止 背景音樂
		GotoGameState(GAME_STATE_Rival_Win);
	}
	if (Rival[maxRival].GetHealth() <= 0) {					//若貓咪獲勝
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// 停止 背景音樂
		GotoGameState(GAME_STATE_Neko_Win);
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
	//
	// 開始載入資料
	//
	int i;
	for (i = 0; i < NUMBALLS; i++)	
		ball[i].LoadBitmap();								// 載入第i個球的圖形
	//eraser.LoadBitmap();
	background.LoadBitmap(IDB_BACKGROUND);					// 載入背景的圖形
	//
	// 完成部分Loading動作，提高進度
	//
	ShowInitProgress(50);
	Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 繼續載入其他資料
	//
	help.LoadBitmap(IDB_HELP,RGB(255,255,255));				// 載入說明的圖形
	corner.LoadBitmap(IDB_CORNER);							// 載入角落圖形
	corner.ShowBitmap(background);							// 將corner貼到background
	bball.LoadBitmap();										// 載入圖形
	hits_left.LoadBitmap();		
	stageData.LoadBitmap();									//載入背景圖片和關卡名稱
	stopButton.LoadBitmap(".\\bitmaps\\中止.bmp", RGB(255, 0, 0));//載入退出遊戲圖形
	currentMoney.LoadBitmap();								//載入數字圖形
	maxMoney.LoadBitmap();									//載入數字圖形	
	workCat.LoadBitmap();									//載入工作貓圖形
	//Mybase.LoadBitmap(IDB_Mybase,RGB(255,0,0));			//載入我方砲塔
	Neko[maxNeko].LoadBitmap();								//載入我方砲塔
	//Rivalbase.LoadBitmap(IDB_Rivalbase, RGB(255, 0, 0));	//載入敵方砲塔
	Rival[maxRival].LoadBitmap();							//載入敵方砲塔
	MaxNekoText.LoadBitmap(".\\bitmaps\\無法出擊.bmp", RGB(255, 0, 0));//載入無法出擊文字
	neko.LoadBitmap();										//載入貓咪動畫
	//neko2.LoadBitmap();										//載入貓咪動畫
	//doge.LoadBitmap();									//載入敵方動畫
	for (int i = 0; i < maxNeko; i++) {
		Neko[i].LoadBitmap();
	}
	for (int i = 0; i < maxRival; i++) {
		Rival[i].LoadBitmap();
	}
	Button.LoadBitmap();									//載入貓咪按鈕
	
	//giant.LoadBitmap(IDB_giant, RGB(255, 0, 0));			// 載入巨神貓
	

	CAudio::Instance()->Load(AUDIO_BackgroundMusic, "sounds\\InvadingJapan!.mp3");	// 載入編號2的聲音Invading Japan!.mp3
	//
	// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
	//
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	//if (nChar == KEY_LEFT)
		//eraser.SetMovingLeft(true);
	//if (nChar == KEY_RIGHT)
		//eraser.SetMovingRight(true);
	//if (nChar == KEY_UP)
		//eraser.SetMovingUp(true);
	//if (nChar == KEY_DOWN)
		//eraser.SetMovingDown(true);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	//if (nChar == KEY_LEFT)
		//eraser.SetMovingLeft(false);
	//if (nChar == KEY_RIGHT)
		//eraser.SetMovingRight(false);
	//if (nChar == KEY_UP)
		//eraser.SetMovingUp(false);
	//if (nChar == KEY_DOWN)
		//eraser.SetMovingDown(false);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//eraser.SetMovingLeft(true);
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	string nekoName[10] = { "Cat","Tank Cat","Axe Cat","Gross Cat","Cow Cat","Bird Cat","Fish Cat","Lizard Cat","Titan Cat","Cat"};
	//eraser.SetMovingLeft(false);
	if (currentNekoQuantity < maxNeko && Button.isAffordable(point.x, point.y)) {//目前貓咪數量小於maxNeko及目前金額是足夠的按下才有反應
		Button.SetClicked(point.x, point.y);			//處理按下按鈕的動作
		for (int i = 0; i < 10; i++) {
			int findDisappearNeko = 0;					//找出Neko陣列哪一個貓咪已擊退的變數	
			if (Button.checkNowClicked(i) == true) {	//按下按鈕的瞬間及判斷錢夠不夠
				currentMoney.Add(-Button.costMoney(i));
				if (activateNeko < maxNeko) {			//如果已派出的貓咪小於20隻，readyToFightNeko就依序加一
					readyToFightNeko += 1;
					currentNekoQuantity += 1;			//目前畫面上貓咪總數加一
					Neko[readyToFightNeko] = nekoAnimation(nekoName[Button.getButtonNum(point.x, point.y)]);//傳入貓咪的名字然後載入貓咪資料
					Neko[readyToFightNeko].LoadBitmap();		//去讀取該貓咪的圖片
				}
				else {									//如果超過20隻就要等畫面貓咪總數小於20隻，再去尋找Neko陣列中的貓咪哪個已經被擊退
					while(findDisappearNeko<maxNeko) {
						if (Neko[findDisappearNeko].GetNekoStatus() == "replaceable" && activateNeko == maxNeko) {
							readyToFightNeko = findDisappearNeko;
							currentNekoQuantity += 1;			//目前畫面上貓咪總數加一
							Neko[readyToFightNeko] = nekoAnimation(nekoName[Button.getButtonNum(point.x, point.y)]);//傳入貓咪的名字然後載入貓咪資料
							Neko[readyToFightNeko].LoadBitmap();		//去讀取該貓咪的圖片
							break;
						}
						if (findDisappearNeko < maxNeko) {
							findDisappearNeko += 1;
						}
					}
				}
			}

		}
	}
	if (workCat.clickAction(point.x, point.y) == true) {		//若按下後有升級就扣錢錢
		currentMoney.Add(-workCat.requireMoney[workCat.getCurrentLevel()-2]);
		maxMoney.Add(workCat.maxMoney);							//增加最大金額
	}
	if ((point.x >= 0 && point.x <= 100) && (point.y >= 0 && point.y <= 90)) {	//按到中止遊戲按鈕
		GotoGameState(GAME_STATE_Stage_Select);
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// 停止 背景音樂
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//eraser.SetMovingRight(true);
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	//eraser.SetMovingRight(false);
	Neko[0].SetHealth(0);
	Neko[1].SetHealth(0);
	Rival[0].SetHealth(0);
}

void CGameStateRun::OnShow()
{
	//
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
	//
	//
	//  貼上背景圖、撞擊數、球、擦子、彈跳的球
	//
	stageData.ShowBitmapBackGround(stage);//貼上背景圖
	//Mybase.ShowBitmap();				//貼上我方砲塔
	Neko[maxNeko].OnShow();				//貼上我方砲塔
	Rival[maxRival].OnShow();					//貼上敵方砲塔
	//Rivalbase.ShowBitmap();				//貼上敵方砲塔
	//neko.OnShow();						//貼上貓咪
	//neko2.OnShow();						//貼上貓咪	
	//doge.OnShow();						//貼上狗仔
	currentMoney.ShowBitmap();			//貼上現有金額
	maxMoney.ShowBitmap();				//貼上現有金額
	workCat.ShowBitmap();				//貼上工作貓
	stopButton.ShowBitmap();			//貼上離開遊戲按鈕
	stageData.ShowBitmapName(stage);	//貼上關卡名稱	
	for (int i = 0; i < activateNeko; i++) {
		Neko[i].OnShow();
	}
	for (int i = 0; i < activateRival; i++) {
		Rival[i].OnShow();
	}
	Button.ShowBitmap();				//貼上角色按鈕
	if (currentNekoQuantity >= maxNeko) {	//若以達最大出擊數就會出現文字	
		MaxNekoText.ShowBitmap();			//貼上無法出擊文字
	}

	//giant.ShowBitmap(0.8);
	/*
	background.ShowBitmap();			// 貼上學校圖
	help.ShowBitmap();					// 貼上說明圖
	hits_left.ShowBitmap();
	for (int i=0; i < NUMBALLS; i++)
		ball[i].OnShow();				// 貼上第i號球
	bball.OnShow();						// 貼上彈跳的球
	
	//
	//  貼上左上及右下角落的圖
	//
	corner.SetTopLeft(0,0);
	corner.ShowBitmap();
	corner.SetTopLeft(SIZE_X-corner.Width(), SIZE_Y-corner.Height());
	corner.ShowBitmap();*/


	//將數值顯示在螢幕上
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo 數字對字串的轉換
	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	sprintf(str, "neko(x1):%d neko(x2):%d doge(x1):%d doge(x2):%d neko(health):%d", neko2.GetX1(), neko2.GetX2(), doge.GetX1(), doge.GetX2(), neko2.GetHealth());
	sprintf(str1, "doge(health):%d animationNumber:%d %d %d", doge.GetHealth(), doge.GetAnimationNumber(),NekoDetector.findTarget(Neko, maxNeko), RivalDetector.findTarget(Rival, maxRival));
	sprintf(str2, "activateNeko:%d currentNekoQuantity:%d readyToFightNeko:%d",activateRival,currentRivalQuantity,readyToFightRival);
	sprintf(str3, "%d/%d", Rival[maxRival].GetHealth(), Rival[maxRival].GetOriginHealth());
	sprintf(str4, "%d/%d", Neko[maxNeko].GetHealth(), Neko[maxNeko].GetOriginHealth());
	pDC->TextOut(400, 0, str);
	pDC->TextOut(400, 50, str1);
	pDC->TextOut(400, 100, str2); 
	pDC->TextOut(130, 360, str3);
	pDC->TextOut(1650,360, str4);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
}
}