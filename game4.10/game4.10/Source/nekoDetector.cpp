#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"			//需先匯入才能讀取
#include "nekoAnimation.h"
#include "nekoDetector.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// nekoDetector:這個class提供偵測哪隻貓咪要設為目標的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////


	nekoDetector::nekoDetector()
	{
	}

	int nekoDetector::findTarget(nekoAnimation  *nekolist, int quantityOfNeko)
	{
		target = quantityOfNeko;									//預設先將砲塔設為目標
		for (int i = 0; i < quantityOfNeko; i++) {
			if (nekolist[i].GetNekoStatus() == "IsOnScreen") {		//若有在畫面才會比較
				if (nekolist[i].GetHeadPosition() < nekolist[target].GetHeadPosition()) {	//若比砲台更靠近敵人就將此角色設為目標
					target = i;
				}
			}
		}
		return target;
	}



}