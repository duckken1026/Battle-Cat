#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"			//�ݥ��פJ�~��Ū��
#include "nekoAnimation.h"
#include "nekoDetector.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// nekoDetector:�o��class���Ѱ��������߫}�n�]���ؼЪ���O
// 
// 
/////////////////////////////////////////////////////////////////////////////


	nekoDetector::nekoDetector()
	{
	}

	int nekoDetector::findTarget(nekoAnimation  *nekolist, int quantityOfNeko)
	{
		target = quantityOfNeko;									//�w�]���N����]���ؼ�
		for (int i = 0; i < quantityOfNeko; i++) {
			if (nekolist[i].GetNekoStatus() == "IsOnScreen") {		//�Y���b�e���~�|���
				if (nekolist[i].GetHeadPosition() < nekolist[target].GetHeadPosition()) {	//�Y�񯥥x��a��ĤH�N�N������]���ؼ�
					target = i;
				}
			}
		}
		return target;
	}



}