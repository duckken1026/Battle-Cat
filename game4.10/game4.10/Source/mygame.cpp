/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////
int stage = 1;			//�襤�����d
CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
	//
	//logo.LoadBitmap(IDB_BACKGROUND);
	MainMenu.LoadBitmap(".\\bitmaps\\�C���D�e��.bmp");
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
	CAudio::Instance()->Load(AUDIO_Beginning, "sounds\\beginning.mp3");		//Load �}�Y����
	CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play �}�Y����
}

void CGameStateInit::OnBeginState()
{
	
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE) {
		GotoGameState(GAME_STATE_Stage_Select);				// ������GAME_STATE_Stage_Select
		CAudio::Instance()->Stop(AUDIO_Beginning);
	}
	else if (nChar == KEY_ESC) {								// Demo �����C������k
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
	}
}

void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ((point.x >= 575 && point.x <= 1337) && (point.y >= 592 && point.y <= 700)) {
		GotoGameState(GAME_STATE_Stage_Select);		// ������GAME_STATE_Stage_Select
		CAudio::Instance()->Stop(AUDIO_Beginning);
	}
	if ((point.x >= 575 && point.x <= 1337) && (point.y >= 730 && point.y <= 838)) {
		GotoGameState(GAME_STATE_ABOUT);		// ������GAME_STATE_ABOUT
	}
}

void CGameStateInit::OnShow()
{
	//
	// �K�Wlogo
	//

	//logo.SetTopLeft((SIZE_X - logo.Width())/2, SIZE_Y/8);
	//logo.ShowBitmap();
	MainMenu.ShowBitmap();
	//
	// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
	//
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	fp=pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	pDC->TextOut(5,895,"Press Ctrl-F to switch in between window mode and full screen mode.");
	if (ENABLE_GAME_PAUSE)
		pDC->TextOut(5,925,"Press Ctrl-Q to pause the Game.");
	pDC->TextOut(5,955,"Press Alt-F4 or ESC to Quit.");
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}			

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C������
/////////////////////////////////////////////////////////////////////////////

CGameStateAbout::CGameStateAbout(CGame * g)
: CGameState(g)
{
}

void CGameStateAbout::OnInit()
{
	about.LoadBitmap(".\\bitmaps\\�C������.bmp");
}

void CGameStateAbout::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ((point.x >= 2 && point.x <= 142) && (point.y >= 914 && point.y <= 1075)) {
		GotoGameState(GAME_STATE_INIT);		// ������GAME_STATE_INIT
	}
}

void CGameStateAbout::OnShow()
{
	about.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateStageSelect::CGameStateStageSelect(CGame *g)
	: CGameState(g)
{
}

void CGameStateStageSelect::OnInit()
{
	stageSelect.LoadBitmap();
	back.LoadBitmap(".\\bitmaps\\��^.bmp", RGB(255, 0, 0));
	back.SetTopLeft(10,920);
	start.LoadBitmap(".\\bitmaps\\�԰��}�l.bmp", RGB(255,0,0));
	start.SetTopLeft(1280,920);
	CAudio::Instance()->Load(AUDIO_Stage, "sounds\\Preparation.mp3");		//Load �}�Y����
	
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

void CGameStateStageSelect::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ((point.y >= 140 && point.y < 920) &&(point.x>960 && point.x<=1920)) {
		stageSelect.clickRight();
	}
	if ((point.y >= 140 && point.y < 920) && (point.x >= 0 && point.x <= 960)) {
		stageSelect.clickLeft();
	}
	if ((point.y >= 920 && point.y <= 1102) && (point.x >= 10 && point.x <= 243)) {
		GotoGameState(GAME_STATE_INIT);				// ������GAME_STATE_INIT
		CAudio::Instance()->Stop(AUDIO_Stage);
		CAudio::Instance()->Play(AUDIO_Beginning, true);
	}
	if ((point.y >= 920 && point.y <= 1089) && (point.x >= 1280 && point.x <= 1945)) {
		stage = stageSelect.getStage();
		GotoGameState(GAME_STATE_RUN);				// ������GAME_STATE_RUN
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
// �o��class���C�����������A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play �}�Y����
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
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	fp=pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "Game Over ! (%d)", counter / 10);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A�߫}���
/////////////////////////////////////////////////////////////////////////////
CGameStateNekoWin::CGameStateNekoWin(CGame *g)
	: CGameState(g)
{
}

void CGameStateNekoWin::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ((point.y >= 0 && point.y <= 1080) && (point.x >= 0 && point.x <= 1920)) {
		CAudio::Instance()->Stop(AUDIO_Victory);
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play �}�Y����
		GotoGameState(GAME_STATE_INIT);
	}

}

void CGameStateNekoWin::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Stop(AUDIO_Victory);
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play �}�Y����
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
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
	winPhoto.LoadBitmap(".\\bitmaps\\�j�����.bmp");
	winPhoto.SetTopLeft(370,200);
	CAudio::Instance()->Load(AUDIO_Victory, "sounds\\Victory.mp3");		//Load �ӧQ����

}

void CGameStateNekoWin::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	char str1[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "(%d)", counter / 10);
	sprintf(str1, "%s", "�I���^��D�e��");
	pDC->TextOut(925, 700, str);
	pDC->TextOut(835, 800, str1);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	winPhoto.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A�ĤH���
/////////////////////////////////////////////////////////////////////////////
CGameStateRivalWin::CGameStateRivalWin(CGame *g)
	: CGameState(g)
{
}

void CGameStateRivalWin::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ((point.y >= 0 && point.y <= 1080) && (point.x >= 0 && point.x <= 1920)) {
		CAudio::Instance()->Stop(AUDIO_Defeat);
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play �}�Y����
		GotoGameState(GAME_STATE_INIT);
	}

}

void CGameStateRivalWin::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Stop(AUDIO_Defeat);
		CAudio::Instance()->Play(AUDIO_Beginning, true);						//Play �}�Y����
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
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
	winPhoto.LoadBitmap(".\\bitmaps\\�G��.bmp");
	winPhoto.SetTopLeft(500, 200);
	CAudio::Instance()->Load(AUDIO_Defeat, "sounds\\Defeat.mp3");		//Load ���ѭ���
	
}

void CGameStateRivalWin::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	char str1[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "(%d)", counter / 10);
	sprintf(str1, "%s", "�I���^��D�e��");
	pDC->TextOut(925, 700, str);
	pDC->TextOut(835, 600, str1);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	winPhoto.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g), NUMBALLS(28), maxNeko(20),maxRival(10)
{
	ball = new CBall [NUMBALLS];	
	Rival = new rivalAnimation[maxRival + 1];//�[�W�@�ӼĤ�D��
	Neko = new nekoAnimation[maxNeko + 1];//�[�W�@�ӿ߫}�D��
	for (int i = 0; i < maxNeko; i++) {
		Neko[i] = nekoAnimation("Cat");
	}
	Neko[maxNeko] = nekoAnimation("Neko Base");		//�߫}�D��
	for (int i = 0; i < maxRival; i++) {
		Rival[i] = rivalAnimation("Doge");
	}
	Rival[maxRival] = rivalAnimation("Taiwan Base");//�Ĥ�D��
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
	CAudio::Instance()->Stop(AUDIO_Beginning);		//Close �}�Y����
	const int BALL_GAP = 90;
	const int BALL_XY_OFFSET = 45;
	const int BALL_PER_ROW = 7;
	const int HITS_LEFT = 10;
	const int HITS_LEFT_X = 590;
	const int HITS_LEFT_Y = 0;
	const int BACKGROUND_X = 60;
	const int ANIMATION_SPEED = 15;
	for (int i = 0; i < NUMBALLS; i++) {				// �]�w�y���_�l�y��
		int x_pos = i % BALL_PER_ROW;
		int y_pos = i / BALL_PER_ROW;
		ball[i].SetXY(x_pos * BALL_GAP + BALL_XY_OFFSET, y_pos * BALL_GAP + BALL_XY_OFFSET);
		ball[i].SetDelay(x_pos);
		ball[i].SetIsAlive(true);
	}
	//eraser.Initialize();
	background.SetTopLeft(BACKGROUND_X,0);				// �]�w�I�����_�l�y��
	help.SetTopLeft(0, SIZE_Y - help.Height());			// �]�w�����Ϫ��_�l�y��
	hits_left.SetInteger(HITS_LEFT);					// ���w�ѤU��������
	hits_left.SetTopLeft(HITS_LEFT_X,HITS_LEFT_Y);		// ���w�ѤU�����ƪ��y��
	stopButton.SetTopLeft(0,0);							//�]�w������s��ܪ��y��
	CatWinButton.SetTopLeft(1600,900);					//�]�w������s��ܪ��y��
	RivalWinButton.SetTopLeft(1600,990);				//�]�w������s��ܪ��y��
	currentMoney.SetDigits(1);
	currentMoney.SetInteger(0);							//�]�w�{�����B��l�Ȭ�0
	currentMoney.SetTopLeft(1520, 0);					//�]�w�{�����B��ܪ��y��
	maxMoney.SetDigits(3);								//�]�w�{���̤j���B���
	maxMoney.SetInteger(300);							//�]�w�{���̤j���B��l��
	maxMoney.SetTopLeft(1594, 0);						//�]�w�̤j���B��ܪ��y��
	workCat.SetTopLeft();								//�]�w�u�@�߫��s���y��
	workCat.SetInitLevel();								//�]�w��l�u�@�ߵ���
	Button.setClickedTimes(0);							//�]�w���s���U���Ƭ�0��l��
	activateNeko = 0;									//�]�wNeko�}�C���w�X�ʿ߫}���ƶq
	currentNekoQuantity = 0;							//�ثe��ܦb�e�������߫}�ƶq
	readyToFightNeko = -1;								//�]�w�U�@�ӭn���X���߫}�bNeko�}�C�����@�ӭ�
	activateRival = 0;									//�]�wRival�}�C���w�X�ʼĤ誺�ƶq
	currentRivalQuantity = 0;							//�ثe��ܦb�e�������Ĥ�ƶq
	readyToFightRival = -1;								//�]�w�U�@�ӭn���X���Ĥ�bRival�}�C�����@�ӭ�
	moneyDelay = 0;										//�����W�[�t�ש���
	rivalDelay = 0;										//���X�ĤH����ɶ�
	//CAudio::Instance()->Play(AUDIO_LAKE, true);			// ���� WAVE
	//CAudio::Instance()->Play(AUDIO_DING, false);		// ���� WAVE
	CAudio::Instance()->Play(AUDIO_BackgroundMusic, true);			// ���� �I������
	Neko[maxNeko].SetHealth(1000);						//�]�w����ͩR��
	Rival[maxRival] = rivalAnimation(stageData.getRivalBase(stage));//�Ĥ�D��
	Rival[maxRival].LoadBitmap();
	for (int i = 0; i < maxNeko; i++) {
		Neko[i] = nekoAnimation("Cat");
	}
	for (int i = 0; i < maxRival; i++) {
		Rival[i] = rivalAnimation("Doge");
	}
	
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	Neko[maxNeko].MoveForward(&doge);					//�N�߫}���𬣥X
	Rival[maxRival].MoveForward(&neko);					//�N�Ĥ该�𬣥X
	neko.OnMove();										//�߫}�ʵe�}�l�ܴ�
	if (neko.GetAnimationNumber() == 0) {
		neko.SetCurrentBitmap(9);
	}
	if (currentRivalQuantity < maxRival) {
		if (rivalDelay / stageData.getStageDelay(stage) >= 1) {						    //�C�j10���X�@���ĤH
			rivalDelay = 0;									//���]RivalDelay
			int findDisappearRival = 0;						//��XRival�}�C���@�ӼĤ�w���h���ܼ�

			if (activateRival < maxRival) {			//�p�G�w���X���ĤH�p��20���AreadyToFightRival�N�̧ǥ[�@
				activateRival += 1;
				readyToFightRival += 1;
				currentRivalQuantity += 1;			//�ثe�e���W�Ĥ��`�ƥ[�@
				Rival[readyToFightRival] = rivalAnimation(stageData.getRival(stage));//�ǤJ�Ĥ誺�W�r�M����J�Ĥ���
				Rival[readyToFightRival].LoadBitmap();		//�hŪ���ӼĤ誺�Ϥ�
			}
			else {									//�p�G�W�L20���N�n���e���Ĥ��`�Ƥp��20���A�A�h�M��Rival�}�C�����Ĥ���Ӥw�g�Q���h
				while (findDisappearRival < maxRival) {
					if (Rival[findDisappearRival].GetRivalStatus() == "replaceable" && activateRival == maxRival) {
						readyToFightRival = findDisappearRival;
						currentRivalQuantity += 1;			//�ثe�e���W�Ĥ��`�ƥ[�@
						Rival[readyToFightRival] = rivalAnimation(stageData.getRival(stage));//�ǤJ�Ĥ誺�W�r�M����J�Ĥ���
						Rival[readyToFightRival].LoadBitmap();		//�hŪ���ӼĤ誺�Ϥ�
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
		if (Rival[i].GetRivalStatus() == "IsOnScreen") {		//�p��{�b�b�e���W���Ĥ�
			currentRivalQuantity += 1;
		}
	}

	for (int i = 0; i < activateRival; i++) {			//���X�Ĥ�
		Rival[i].MoveForward(&Neko[NekoDetector.findTarget(Neko, maxNeko)]);
	}

	if (Button.getClickedTimes() <= maxNeko) {			//�Y���U�������٨S�j��maxNeko
	activateNeko = Button.getClickedTimes();			//activateNeko�[�@
	}
	
	currentNekoQuantity = 0;
	for (int i = 0; i < maxNeko; i++) {
		if (Neko[i].GetNekoStatus() == "IsOnScreen") {		//�p��{�b�b�e���W���߫}
			currentNekoQuantity += 1;
		}
	}

	for (int i = 0; i < activateNeko; i++) {			//���X�߫}
		Neko[i].MoveForward(&Rival[RivalDetector.findTarget(Rival, maxRival)]);
	}
	Button.SetTopLeft();									//�]�w���s��m
	MaxNekoText.SetTopLeft(795,350);						//�]�w�L�k�X����r��m
	
	//
	// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	// ���ʭI���Ϫ��y��
	//
	if (background.Top() > SIZE_Y)
		background.SetTopLeft(60 ,-background.Height());
	background.SetTopLeft(background.Left(),background.Top()+1);
	//
	// ���ʲy
	//
	int i;
	for (i=0; i < NUMBALLS; i++)
		ball[i].OnMove();
	//
	// �������l
	//
	//eraser.OnMove();
	//
	// �P�_���l�O�_�I��y
	//
	if (moneyDelay >= 3){//����ɶ���(100ms* x)
		if (currentMoney.GetInteger() < maxMoney.GetInteger()) {	//�Y�{�����B�p��̤j���B�{�����B�N�|����[�@
			if (currentMoney.GetInteger() + workCat.addSpeed[workCat.getCurrentLevel() - 1] > maxMoney.GetInteger()) { //�Y�[����W�L�̤j���B
				currentMoney.Add(maxMoney.GetInteger() - currentMoney.GetInteger());//�Y�|�W�L�̤j���B�u�[�W�Ȩ�̤j��
			}
			else {
				currentMoney.Add(workCat.addSpeed[workCat.getCurrentLevel() - 1]);//�C�j100�@��[1��ثe���B
			}
			moneyDelay = 0;
		}
	}
	moneyDelay += 1;
	
	Button.updateAffordable(currentMoney.GetInteger());	//��s�ثe�o���߬O�_�������������X
	workCat.checkAffordable(currentMoney.GetInteger());	//�ˬd�O�_���������B�ɯŤu�@��
	if (Neko[maxNeko].GetHealth() <= 0) {					//�Y�Ĥ����
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// ���� �I������
		GotoGameState(GAME_STATE_Rival_Win);
	}
	if (Rival[maxRival].GetHealth() <= 0) {					//�Y�߫}���
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// ���� �I������
		GotoGameState(GAME_STATE_Neko_Win);
	}
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
	//
	// �}�l���J���
	//
	int i;
	for (i = 0; i < NUMBALLS; i++)	
		ball[i].LoadBitmap();								// ���J��i�Ӳy���ϧ�
	//eraser.LoadBitmap();
	background.LoadBitmap(IDB_BACKGROUND);					// ���J�I�����ϧ�
	//
	// ��������Loading�ʧ@�A�����i��
	//
	ShowInitProgress(50);
	Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �~����J��L���
	//
	help.LoadBitmap(IDB_HELP,RGB(255,255,255));				// ���J�������ϧ�
	corner.LoadBitmap(IDB_CORNER);							// ���J�����ϧ�
	corner.ShowBitmap(background);							// �Ncorner�K��background
	bball.LoadBitmap();										// ���J�ϧ�
	hits_left.LoadBitmap();		
	stageData.LoadBitmap();									//���J�I���Ϥ��M���d�W��
	stopButton.LoadBitmap(".\\bitmaps\\����.bmp", RGB(255, 0, 0));//���J�h�X�C���ϧ�
	CatWinButton.LoadBitmap(".\\bitmaps\\SKIP-Cat.bmp", RGB(255, 0, 0));//���JCatWin�C���ϧ�
	RivalWinButton.LoadBitmap(".\\bitmaps\\SKIP - Rival.bmp", RGB(255, 0, 0));//���JRivalWin�C���ϧ�
	currentMoney.LoadBitmap();								//���J�Ʀr�ϧ�
	maxMoney.LoadBitmap();									//���J�Ʀr�ϧ�	
	workCat.LoadBitmap();									//���J�u�@�߹ϧ�
	//Mybase.LoadBitmap(IDB_Mybase,RGB(255,0,0));			//���J�ڤ该��
	Neko[maxNeko].LoadBitmap();								//���J�ڤ该��
	//Rivalbase.LoadBitmap(IDB_Rivalbase, RGB(255, 0, 0));	//���J�Ĥ该��
	Rival[maxRival].LoadBitmap();							//���J�Ĥ该��
	MaxNekoText.LoadBitmap(".\\bitmaps\\�L�k�X��.bmp", RGB(255, 0, 0));//���J�L�k�X����r
	neko.LoadBitmap();										//���J�߫}�ʵe
	//neko2.LoadBitmap();										//���J�߫}�ʵe
	//doge.LoadBitmap();									//���J�Ĥ�ʵe
	for (int i = 0; i < maxNeko; i++) {
		Neko[i].LoadBitmap();
	}
	for (int i = 0; i < maxRival; i++) {
		Rival[i].LoadBitmap();
	}
	Button.LoadBitmap();									//���J�߫}���s

	

	CAudio::Instance()->Load(AUDIO_BackgroundMusic, "sounds\\InvadingJapan!.mp3");	// ���J�s��2���n��Invading Japan!.mp3
	//
	// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
	//
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	//eraser.SetMovingLeft(true);
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	string nekoName[10] = { "Cat","Tank Cat","Axe Cat","Gross Cat","Cow Cat","Bird Cat","Fish Cat","Lizard Cat","Titan Cat","Cat"};
	//eraser.SetMovingLeft(false);
	if (currentNekoQuantity < maxNeko && Button.isAffordable(point.x, point.y)) {//�ثe�߫}�ƶq�p��maxNeko�Υثe���B�O���������U�~������
		Button.SetClicked(point.x, point.y);			//�B�z���U���s���ʧ@
		for (int i = 0; i < 10; i++) {
			int findDisappearNeko = 0;					//��XNeko�}�C���@�ӿ߫}�w���h���ܼ�	
			if (Button.checkNowClicked(i) == true) {	//���U���s�������ΧP�_��������
				currentMoney.Add(-Button.costMoney(i));
				if (activateNeko < maxNeko) {			//�p�G�w���X���߫}�p��20���AreadyToFightNeko�N�̧ǥ[�@
					readyToFightNeko += 1;
					currentNekoQuantity += 1;			//�ثe�e���W�߫}�`�ƥ[�@
					Neko[readyToFightNeko] = nekoAnimation(nekoName[Button.getButtonNum(point.x, point.y)]);//�ǤJ�߫}���W�r�M����J�߫}���
					Neko[readyToFightNeko].LoadBitmap();		//�hŪ���ӿ߫}���Ϥ�
				}
				else {									//�p�G�W�L20���N�n���e���߫}�`�Ƥp��20���A�A�h�M��Neko�}�C�����߫}���Ӥw�g�Q���h
					while(findDisappearNeko<maxNeko) {
						if (Neko[findDisappearNeko].GetNekoStatus() == "replaceable" && activateNeko == maxNeko) {
							readyToFightNeko = findDisappearNeko;
							currentNekoQuantity += 1;			//�ثe�e���W�߫}�`�ƥ[�@
							Neko[readyToFightNeko] = nekoAnimation(nekoName[Button.getButtonNum(point.x, point.y)]);//�ǤJ�߫}���W�r�M����J�߫}���
							Neko[readyToFightNeko].LoadBitmap();		//�hŪ���ӿ߫}���Ϥ�
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
	if (workCat.clickAction(point.x, point.y) == true) {		//�Y���U�ᦳ�ɯŴN������
		currentMoney.Add(-workCat.requireMoney[workCat.getCurrentLevel()-2]);
		maxMoney.Add(workCat.maxMoney);							//�W�[�̤j���B
	}
	if ((point.x >= 0 && point.x <= 100) && (point.y >= 0 && point.y <= 90)) {	//���줤��C�����s
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// ���� �I������
		GotoGameState(GAME_STATE_Stage_Select);
	}
	if ((point.x >= 1600 && point.x <= 1877) && (point.y >= 900 && point.y <= 989)) {	//���줤��C�����s
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// ���� �I������
		GotoGameState(GAME_STATE_Neko_Win);
	}
	if ((point.x >= 1600 && point.x <= 1877) && (point.y >= 990 && point.y <= 1089)) {	//���줤��C�����s
		CAudio::Instance()->Stop(AUDIO_BackgroundMusic);	// ���� �I������
		GotoGameState(GAME_STATE_Rival_Win);
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	//eraser.SetMovingRight(true);
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	//eraser.SetMovingRight(false);
	Neko[0].SetHealth(0);
	Neko[1].SetHealth(0);
	Rival[0].SetHealth(0);
}

void CGameStateRun::OnShow()
{
	//
	//  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
	//        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
	//        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
	//
	//
	//  �K�W�I���ϡB�����ơB�y�B���l�B�u�����y
	//
	stageData.ShowBitmapBackGround(stage);//�K�W�I����
	//Mybase.ShowBitmap();				//�K�W�ڤ该��
	Neko[maxNeko].OnShow();				//�K�W�ڤ该��
	Rival[maxRival].OnShow();					//�K�W�Ĥ该��
	currentMoney.ShowBitmap();			//�K�W�{�����B
	maxMoney.ShowBitmap();				//�K�W�{�����B
	workCat.ShowBitmap();				//�K�W�u�@��
	stopButton.ShowBitmap();			//�K�W���}�C�����s
	CatWinButton.ShowBitmap();			//�K�WCatWin���s
	RivalWinButton.ShowBitmap();		//�K�WRivalWin���s
	stageData.ShowBitmapName(stage);	//�K�W���d�W��	
	for (int i = 0; i < activateNeko; i++) {
		Neko[i].OnShow();
	}
	for (int i = 0; i < activateRival; i++) {
		Rival[i].OnShow();
	}
	Button.ShowBitmap();				//�K�W������s
	if (currentNekoQuantity >= maxNeko) {	//�Y�H�F�̤j�X���ƴN�|�X�{��r	
		MaxNekoText.ShowBitmap();			//�K�W�L�k�X����r
	}
	//�N�ƭ���ܦb�ù��W
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str3[100];
	char str4[100];
	sprintf(str3, "%d/%d", Rival[maxRival].GetHealth(), Rival[maxRival].GetOriginHealth());
	sprintf(str4, "%d/%d", Neko[maxNeko].GetHealth(), Neko[maxNeko].GetOriginHealth());
	pDC->TextOut(130, 360, str3);
	pDC->TextOut(1650, 360, str4);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}



}