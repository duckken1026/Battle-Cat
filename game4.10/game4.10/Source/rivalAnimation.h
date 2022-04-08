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
		int  GetX();							//取得圖片X座標
		int  GetY();							//取得圖片Y座標
		void SetCoordinate(int NewX, int NewY);	//設定圖片座標
		void MoveForward(nekoAnimation neko);						//向前走動
	private:
		CAnimation	image;		// 狗仔動畫物件
		int x, y;				// X,Y座標
	};
}