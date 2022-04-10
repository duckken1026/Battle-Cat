namespace game_framework{
	
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供敵人動畫
	/////////////////////////////////////////////////////////////////////////////

	class nekoAnimation;						//先讓編譯器知道之後會有nekoAnimation的存在之後再來include
	
	class rivalAnimation 
	{
	public:
		rivalAnimation();
		void LoadBitmap();						//讀取圖片
		void OnMove();							//動畫開始移動
		void OnShow();							//將動畫顯示在畫面
		int  GetX1();							//取得圖片X座標
		int  GetX2();							//取得圖片X(右)座標
		int  GetY();							//取得圖片Y座標
		void SetCoordinate(int NewX, int NewY);	//設定圖片座標
		void MoveForward(nekoAnimation *neko);	//向前走動
		bool GetIsAlive();							//取得是否還活著
		int	 GetAttack();						//取得攻擊力
		int	 GetHealth();						//取得體力
		void SetHealth(int NewHealth);					//更改體力值
		
	private:
		CAnimation	image;		// 狗仔動畫物件
		int x1, y;				// X,Y座標
		int x2;					// X(右)
		bool IsAlive;			// 是否活著
		int range;				// 角色可攻擊的範圍
		int health;				//角色生命值
		int attack;				//角色攻擊力
		int attackDelay;		//角色攻擊頻率
		int delay;				//去計算目前已經Delay了幾次
		void die();				//判斷體力小於等於零，成立則執行此函數
	};
}