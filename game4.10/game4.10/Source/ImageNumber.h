namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供顯示整數圖形的能力
	// 
	/////////////////////////////////////////////////////////////////////////////

	class ImageNumber {
	public:
		ImageNumber(int = 3);		// default 5 digits
		void Add(int n);			// 增加整數值
		int  GetInteger();			// 回傳整數值
		void LoadBitmap();			// 載入0..9及負號之圖形
		void SetInteger(int);		// 設定整數值
		void SetTopLeft(int, int);	// 將動畫的左上角座標移至 (x,y)
		void ShowBitmap();			// 將動畫貼到螢幕
		void SetDigits(int );			// 設定位數
	private:
		int NUMDIGITS;			// 共顯示NUMDIGITS個位數
		static CMovingBitmap digit[11]; // 儲存0..9及負號之圖形(bitmap)
		int x, y;						// 顯示的座標
		int n;							// 整數值
		bool isBmpLoaded = false;				// 是否已經載入圖形
	};
}