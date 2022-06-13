namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供關卡資訊的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageImformation {
	public:
		stageImformation();
		string getRivalBase(int stage);				//取得該關卡敵方的塔
		void   LoadBitmap();						//讀取圖片
		void   ShowBitmapBackGround(int stage);		//顯示背景圖片
		void   ShowBitmapName(int stage);			//顯示關卡名稱圖片
	private:
		static CMovingBitmap BackGround[7];			//背景
		static CMovingBitmap Name[7];				//關卡名稱
		string stageRivalBase[7] = { "Taiwan Base","Hong Kong Base","Thailand Base","China Base","Mongolia Base","Korea Base","Japan Base"};//該關卡敵方的塔
		bool isBmpLoaded;				// 是否已經載入圖形
	};
}