namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供顯示角色按鈕的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoButton {
	public:
		void LoadBitmap();				//讀取圖片
		void ShowBitmap();				//顯示圖片
		void SetTopLeft();				//設定座標

	private:
		CMovingBitmap button[1];		//按鈕圖形
		int x[10];						//按鈕x座標
		int y[10];						//按鈕y座標
	};
}