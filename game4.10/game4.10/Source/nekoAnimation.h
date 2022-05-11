namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供貓咪動畫
	/////////////////////////////////////////////////////////////////////////////

	class nekoAnimation 
	{
	public:
		nekoAnimation();
		nekoAnimation(string name);
		void LoadBitmap();						//讀取圖片
		void OnMove();							//動畫開始移動
		void OnShow();							//將動畫顯示在畫面
		int  GetX1();							//取得圖片X(左)座標
		int  GetX2();							//取得圖片X(右)座標
		int  GetY();							//取得圖片Y座標
		void SetCoordinate(int NewX,int NewY);	//設定圖片座標
		void MoveForward(rivalAnimation *rival);//向前走動
		bool GetIsAlive();						//取得是否還活著
		int	 GetAttack();						//取得攻擊力
		int	 GetHealth();						//取得體力
		void SetHealth(int NewHealth);			//更改體力值
		int  GetAnimationNumber();				//取得現在動畫播到哪一張
		void SetCurrentBitmap(int);				//設定目前動畫
		int  GetHeadGap();						//回傳角色實際間距
	private:
		CAnimation	image;		// 貓咪動畫物件
		int x1, y;				// X(左),Y座標
		int x2;					// X(右)
		bool IsAlive;			// 是否活著
		int range;				// 角色可攻擊的範圍
		int headGap;			// 角色圖片起始位置間距
		int health;				//角色生命值
		int attack;				//角色攻擊力
		int attackDelay;		//角色攻擊頻率
		int delay;				//去計算目前已經Delay了幾次
		void die();				//判斷體力小於等於零，成立則執行此函數
		int walkAnimationStart;	//第一個行走動畫
		int walkAnimationEnd;	//最後一個行走動畫
		int attackAnimationStart;//第一個攻擊動畫
		int attackAnimationEnd;	//最後一個攻擊動畫
		int deathAnimationStart;//第一個死亡動畫
		int deathAnimationEnd;	//最後一個死亡動畫
		int deathDelay;			//擊退動畫延遲時間
		int deathHeightChange;	//擊退角色Y座標調整
		int moveSpeed;			//角色移動速度
		string nekoType;		//貓咪種類
	};
}