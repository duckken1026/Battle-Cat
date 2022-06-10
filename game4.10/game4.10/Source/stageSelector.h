namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供選擇關卡的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageSelector {
	public:
		stageSelector();
		void LoadBitmap();				//讀取圖片
		void ShowBitmap();				//顯示圖片
		void SetTopLeft();				//設定座標
		void clickRight();				//選擇關卡按下偏右方位置時
		void clickLeft();				//選擇關卡按下偏左方位置時
		int  getStage();				//取得選中的關卡
	private:
		static CMovingBitmap stageImage[30];//關卡圖片
		bool isBmpLoaded;				// 是否已經載入圖形
		int  targetStage;				//選中的關卡
		int  finalStage;				//最後一關
	};
}