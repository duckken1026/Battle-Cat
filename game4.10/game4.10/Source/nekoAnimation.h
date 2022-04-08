namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供貓咪動畫
	/////////////////////////////////////////////////////////////////////////////

	class nekoAnimation 
	{
	public:
		nekoAnimation();
		void LoadBitmap();						//讀取圖片
		void OnMove();							//動畫開始移動
		void OnShow();							//將動畫顯示在畫面
		int  GetX1();							//取得圖片X(左)座標
		int  GetX2();							//取得圖片X(右)座標
		int  GetY();							//取得圖片Y座標
		void SetCoordinate(int NewX,int NewY);	//設定圖片座標
		void MoveForward(rivalAnimation rival);	//向前走動
	private:
		CAnimation	image;		// 貓咪動畫物件
		int x1, y;				// X(左),Y座標
		int x2;					// X(右)	
	};
}