namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供顯示角色按鈕的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoButton {
	public:
		nekoButton();
		void LoadBitmap();				//讀取圖片
		void ShowBitmap();				//顯示圖片
		void SetTopLeft();				//設定座標
		void SetIsClicked(bool clicked);//設定是否被按下
	private:
		static CMovingBitmap button[10];		//按鈕圖形
		int xGap;						//按鈕與按鈕之間的X間距
		int yGap;						//按鈕與按鈕之間的Y間距
		bool isBmpLoaded;				// 是否已經載入圖形
		bool isClicked;					//按鈕是否被按下
	};
}