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
		char *imageList(string name,int);//回傳角色圖片
		int imageQuantity;		//圖片數量
		int headGap;			//角色圖片起始位置間距
		int originY;			//角色起始Y位置
		int walkAnimationSpeed;	//行走動畫速度
		int attackAnimationSpeed;//攻擊動畫速度
		int buttonDelay;		//可派出貓咪的延遲時間
		int cost;				//派出貓咪需花費的金額
	};


}