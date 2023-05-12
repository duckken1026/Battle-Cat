#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "rivalAnimation.h"			//需先匯入才能讀取
#include "nekoAnimation.h"
#include "rivalDetector.h"

namespace game_framework {


/////////////////////////////////////////////////////////////////////////////
// rivalDetector:這個class提供偵測哪隻敵方要設為目標的能力
// 
// 
/////////////////////////////////////////////////////////////////////////////


	rivalDetector::rivalDetector()
	{
	}

	int rivalDetector::findTarget(rivalAnimation  *rivallist, int quantityOfRival)
	{
		target = quantityOfRival;									//預設先將砲塔設為目標
		for (int i = 0; i < quantityOfRival; i++) {
			if (rivallist[i].GetRivalStatus() == "IsOnScreen") {		//若有在畫面才會比較
				if (rivallist[i].GetHeadPosition() > rivallist[target].GetHeadPosition()) {	//若比砲台更靠近敵人就將此角色設為目標
					target = i;
				}
			}
		}
		return target;
	}



}