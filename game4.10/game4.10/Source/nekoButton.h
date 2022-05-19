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
		void SetIsClicked(int buttonNum,bool clicked);//設定是否被按下
		void SetClicked(int pointX,int pointY);				//設定按下時的動作
		bool checkNowClicked(int nekoNumber);				//回傳現在是不是按下去的那個瞬間
	private:
		static CMovingBitmap button[20];		//按鈕圖形
		int xGap;						//按鈕與按鈕之間的X間距
		int yGap;						//按鈕與按鈕之間的Y間距
		bool isBmpLoaded;				// 是否已經載入圖形
		bool isClicked[10];				//按鈕是否被按下
		int x[10];						//按鈕x座標
		int y[10];						//按鈕y座標
		int buttonDelay[10];			//按鈕的冷卻時間
		int delay[10];					//按鈕目前延遲時間
	};
}