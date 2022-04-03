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
		int  GetX();							//取得圖片X座標
		int  GetY();							//取得圖片Y座標
		void SetCoordinate(int NewX,int NewY);	//設定圖片座標
		void MoveForward();						//向前走動
	private:
		CAnimation	image;		// 貓咪動畫物件
		int x, y;				// X,Y座標
	};
}