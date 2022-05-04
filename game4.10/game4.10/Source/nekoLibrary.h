namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供貓咪圖鑑收集貓咪的各項資料
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoLibrary {
	public:
		//角色基本資料
		nekoLibrary(string name);
		int range;				//角色可攻擊的範圍
		int health;				//角色生命值
		int attack;				//角色攻擊力
		int attackDelay;		//角色攻擊頻率
		int walkAnimationStart;	//第一個行走動畫
		int walkAnimationEnd;	//最後一個行走動畫
		int attackAnimationStart;//第一個攻擊動畫
		int attackAnimationEnd;	//最後一個攻擊動畫
		int deathAnimationStart;//第一個死亡動畫
		int deathAnimationEnd;	//最後一個死亡動畫
		int deathHeightChange;	//擊退角色Y座標調整
		int moveSpeed;			//角色移動速度
	};


}