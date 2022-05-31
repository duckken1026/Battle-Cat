namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供升級錢包按鈕的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class levelUpButton {
	public:
		levelUpButton();
		void LoadBitmap();				//讀取圖片
		void ShowBitmap();				//顯示圖片
		void SetTopLeft();				//設定座標
		int  getCurrentLevel();			//取得目前等級
		bool checkAffordable(int currentMoney);	//是否有足夠的錢升級並回傳布林值
		bool clickAction(int pointX, int pointY);//按下時的動作並回傳有沒有升級
		int  requireMoney[7];					//升級所需費用
		int  maxMoney;							//升級後增加多少到最大金額
	private:
		static CMovingBitmap button[15];		//按鈕圖形
		bool isBmpLoaded;						//是否已經載入圖形
		int  level;								//目前等級
		void levelUp();							//升級level
		bool affordable;						//是否有足夠的錢升級
		
	};
}