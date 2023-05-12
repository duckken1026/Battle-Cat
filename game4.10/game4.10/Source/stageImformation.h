namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供關卡資訊的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageImformation {
	public:
		stageImformation();
		string getRivalBase(int stage);				//取得該關卡敵方的塔
		string getRival(int stage);				//取得該關卡敵方
		int	   getStageDelay(int stage);			//取得派出角色延遲時間
		void   LoadBitmap();						//讀取圖片
		void   ShowBitmapBackGround(int stage);		//顯示背景圖片
		void   ShowBitmapName(int stage);			//顯示關卡名稱圖片
	private:
		static CMovingBitmap BackGround[10];			//背景
		static CMovingBitmap Name[10];				//關卡名稱
		string stageRivalBase[10] = { "Taiwan Base","Hong Kong Base","Thailand Base","China Base","Mongolia Base","Korea Base","Japan Base","Australia Base","Singapore Base","Maldives Base"};//該關卡敵方的塔
		string stageRival[10] = { "Doge","Snache","Those Guys","Hippoe","Pigge","Pigge","Pigge","Pigge","Pigge","Pigge" };
		int	   stageDelay[10] = {30,30,30,150,300,300,300,300,100,100 };//派出角色延遲時間
		bool isBmpLoaded;				// 是否已經載入圖形
	};
}