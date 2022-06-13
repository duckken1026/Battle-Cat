namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供關卡資訊的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageImformation {
	public:
		stageImformation();
		char*  getStageBackground(int stage);		//取得該關卡背景圖
		string getRivalBase(int stage);				//取得該關卡敵方的塔
		char * getMusic(int stage);					//取得該關卡背景音樂
		char * getStageName(int stage);				//取得該關卡名稱
		void   LoadBitmap();						//讀取圖片
		void   ShowBitmapBackGround(int stage);		//顯示背景圖片
		void   ShowBitmapName(int stage);			//顯示關卡名稱圖片
	private:
		static CMovingBitmap BackGround[7];			//背景
		static CMovingBitmap Name[7];				//關卡名稱
		char * stageBackGround[7] = { ".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp" };//該關卡背景圖
		string stageRivalBase[7] = { "Taiwan Base","Hong Kong Base","Thailand Base","China Base","Mongolia Base","Korea Base","Japan Base"};//該關卡敵方的塔
		char * stageMusic[3] = { "sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3" };//該關卡背景音樂
		char * stageName[7] = { ".\\bitmaps\\關卡名稱\\台灣.bmp", ".\\bitmaps\\關卡名稱\\香港.bmp", ".\\bitmaps\\關卡名稱\\泰國.bmp", ".\\bitmaps\\關卡名稱\\中國.bmp", ".\\bitmaps\\關卡名稱\\蒙古.bmp", ".\\bitmaps\\關卡名稱\\韓國.bmp", ".\\bitmaps\\關卡名稱\\日本.bmp" };//關卡名稱
		bool isBmpLoaded;				// 是否已經載入圖形
	};
}