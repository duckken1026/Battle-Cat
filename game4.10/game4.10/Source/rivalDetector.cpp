#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"			//�ݥ��פJ�~��Ū��
#include "nekoAnimation.h"
#include "rivalDetector.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// rivalDetector:�o��class���Ѱ��������Ĥ�n�]���ؼЪ���O
// 
// 
/////////////////////////////////////////////////////////////////////////////


	rivalDetector::rivalDetector()
	{
	}

	int rivalDetector::findTarget(rivalAnimation  *rivallist, int quantityOfRival)
	{
		target = quantityOfRival;									//�w�]���N����]���ؼ�
		for (int i = 0; i < quantityOfRival; i++) {
			if (rivallist[i].GetRivalStatus() == "IsOnScreen") {		//�Y���b�e���~�|���
				if (rivallist[i].GetHeadPosition() > rivallist[target].GetHeadPosition()) {	//�Y�񯥥x��a��ĤH�N�N������]���ؼ�
					target = i;
				}
			}
		}
		return target;
	}



}