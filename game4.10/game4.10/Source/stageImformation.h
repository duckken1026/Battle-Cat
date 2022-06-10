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
		char * getStageName(int stage);					//取得該關卡名稱
	private:
		char * stageBackGround[3] = { ".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp",".\\bitmaps\\背景\\草地.bmp" };//該關卡背景圖
		string stageRivalBase[3] = { "Taiwan Base","Hong Kong Base","Thailand Base" };		//該關卡敵方的塔
		char * stageMusic[3] = { "sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3" };//該關卡背景音樂
		char * stageName[3] = { ".\\bitmaps\\關卡名稱\\台灣.bmp", ".\\bitmaps\\關卡名稱\\香港.bmp", ".\\bitmaps\\關卡名稱\\泰國.bmp" };
	};
}