/*
 * mygame.h: ���ɮ��x�C��������class��interface
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
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"
#include "rivalAnimation.h"
#include "nekoAnimation.h"
#include "ImageNumber.h"
#include "nekoButton.h"
#include "maxNumber.h"
#include "levelUpButton.h"
#include "nekoDetector.h"
#include "rivalDetector.h"
#include "stageSelector.h"
#include "stageImformation.h" 

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_BackgroundMusic,	// 2   �I������
		AUDIO_Beginning,		// 3   �}�Y����
		AUDIO_Victory,			// 4   �ӧQ����
		AUDIO_Defeat,			// 5   ���ѭ���
		AUDIO_Stage				// 6   ������d����
	};
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								// csie��logo
		CMovingBitmap MainMenu;							// �D�e���Ϥ�
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C������
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateAbout : public CGameState {
	public:
		CGameStateAbout(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap about;							// �����Ϥ�
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C��������d
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateStageSelect : public CGameState {
	public:
		CGameStateStageSelect(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		stageSelector stageSelect;						// ������d���\��
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap SelectStageMenu;					// ���d��ܵe���Ϥ�
		CMovingBitmap back;								// ��^�Ϥ�
		CMovingBitmap start;							// �}�l�԰��Ϥ�
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		const int		NUMBALLS;	// �y���`��
		CMovingBitmap	background;	// �Ǯչ�
		CMovingBitmap	help;		// ������
		CBall			*ball;		// �y���}�C
		CMovingBitmap	corner;		// ������
		CEraser			eraser;		// ��l
		CInteger		hits_left;	// �ѤU��������
		CBouncingBall   bball;		// ���мu�����y
		CMovingBitmap	Mybase;		// �ڤ该��
		CMovingBitmap	Rivalbase;	// �Ĥ该��
		CMovingBitmap   giant;      // ������
		nekoAnimation   neko;		// �߫}
		nekoAnimation	neko2;		// �ĤG���߫}
		rivalAnimation  doge;		// ���J
		nekoAnimation	*Neko;		// �߫}�}�C
		rivalAnimation  *Rival;		// �ĤH�}�C
		const int		maxNeko;	// �߫}���̤j�ƶq
		const int		maxRival;	// �ĤH���̤j�ƶq
		ImageNumber		currentMoney; //�{������
		nekoButton		Button;		//������s
		int	activateNeko;				//���b����onShow�AmoveForward�AloadBitmap������ƶq
		int	currentNekoQuantity;		//�ثe�e���W���߫}�ƶq
		int readyToFightNeko;			//�Y�N�X�ʪ��߫}(����Neko�}�C������N�ӿ߫})
		int	activateRival;				//���b����onShow�AmoveForward�AloadBitmap������ƶq
		int	currentRivalQuantity;		//�ثe�e���W���ĤH�ƶq
		int readyToFightRival;			//�Y�N�X�ʪ��ĤH(����Rival�}�C������N�ӼĤH)
		CMovingBitmap	MaxNekoText;	//�L�k�X����r
		maxNumber		maxMoney;	//�̤j���B
		levelUpButton	workCat;	//�u�@�߫��s
		int moneyDelay;				//�����W�[�t�ש���(�i�վ�)
		nekoDetector	NekoDetector;//���������߫}�n�]���ؼ�
		rivalDetector	RivalDetector;//���������Ĥ�n�]���ؼ�
		int rivalDelay;				//���X�ĤH������ɶ�
		stageImformation stageData;	//���d��T
		CMovingBitmap	stopButton;	//�h�X�C�����s	
		CMovingBitmap	RivalWinButton;	//RivalWin���s	
		CMovingBitmap	CatWinButton;	//CatWin���s	
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A�߫}���
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateNekoWin : public CGameState {
	public:
		CGameStateNekoWin(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void OnLButtonUp(UINT nFlags, CPoint point);  // ���s
	private:
		int counter;	// �˼Ƥ��p�ƾ�
		CMovingBitmap winPhoto;							// �ӧQ�Ϥ�
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A�ĤH���
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateRivalWin : public CGameState {
	public:
		CGameStateRivalWin(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void OnLButtonUp(UINT nFlags, CPoint point);  // ���s
	private:
		int counter;	// �˼Ƥ��p�ƾ�
		CMovingBitmap winPhoto;							// �ӧQ�Ϥ�
	};
}