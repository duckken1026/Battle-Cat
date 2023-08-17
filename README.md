# Battle-Cat 貓咪大戰爭(自製版)
# 遊玩影片🎮
https://youtu.be/FscnovoOnVs
# 遊戲內容

開始畫面:
![螢幕擷取畫面 2022-06-16 104015](https://github.com/duckken1026/Battle-Cat/assets/97723340/fe9ecbf6-3590-4e47-a452-afb8eb08b9a7)
選擇關卡:
![螢幕擷取畫面 2022-06-16 112953](https://github.com/duckken1026/Battle-Cat/assets/97723340/5d441cf7-3855-481b-9c0f-4c50a7381b90)
切換關卡操作:
![螢幕擷取畫面 2022-06-16 112953 拷貝](https://github.com/duckken1026/Battle-Cat/assets/97723340/23a3c3ac-70b3-4fbc-9036-e6ab2f677a01)
遊玩畫面:
![螢幕擷取畫面 2022-06-16 113028](https://github.com/duckken1026/Battle-Cat/assets/97723340/0af2b734-fd0e-4b13-8148-98de92862344)
![螢幕擷取畫面 2022-06-16 113112](https://github.com/duckken1026/Battle-Cat/assets/97723340/72782935-06eb-4960-bc85-48e6fa878f2f)
獲勝畫面:
![螢幕擷取畫面 2022-06-16 113133](https://github.com/duckken1026/Battle-Cat/assets/97723340/befcf2b9-e5e4-42a9-9969-f84fe570b7b9)
失敗畫面:
![螢幕擷取畫面 2022-06-16 113301](https://github.com/duckken1026/Battle-Cat/assets/97723340/10c5e079-8457-4e06-8003-2f01fcd9f21f)

# 更新日誌  
更新內容:  
* ### **2022/4/1:**

	* 新增背景圖及遊戲畫面基本圖形

* ### **2022/4/3:**

	* 新增新角色及移動(貓咪和狗仔)

* ### **2022/4/5:**

	* 修改遊戲數字圖形的位置及間距

* ### **2022/4/7:**

	* 新增金錢功能(ImageNumber)，更改遊戲背景音樂

* ### **2022/4/8:**

	* 將Class(dogeAnimation)改名為(rivalAnimation)

	* 貓咪使用 nekoAnimation

	* 敵人使用 rivalAnimation

	* 將兩個類別去互相引用對方始角色可存取目前敵方的資訊

* ### **2022/4/9:**

	* 現在起可將文字放在畫面中

	(角色互動行為更新)

	* 新增是否活著，攻擊範圍，生命值，攻擊力變數至我方與敵方

	* 若死亡則不顯示在畫面中

* ### **2022/4/10:**

	(角色互動行為更新)

	* 調整角色傳入敵方物件時傳的是指標物件

	* 調整攻擊方式為我方去修改敵方的血量而不是我方取得敵方攻擊力來改變自己的血量

	* 新增攻擊頻率(可去調整多久攻擊一次)，判斷是否死亡和死亡後會執行的動作

	* 敵方死亡後我方會繼續前進

* ### **2022/4/13:**

	(角色互動行為更新)

	* 在gamelib中的CAnimation加入SetCurrentBitmap可以直接將動畫跳到指定的圖片

	* 角色現在可以播放行走和攻擊的動畫

* ### **2022/5/1:**

	(角色互動行為更新)

	* 新增擊退時的動畫，體力小於等於零時會播放擊退動畫播放完畢後角色會從畫面消失

	* 修改攻擊模式:角色會先攻擊後再進入冷卻模式

	* 新增變數至角色的Class中:deathAnimationStart,deathAnimationEnd,deathDelay,deathHeightChange,moveSpeed.

* ### **2022/5/4:**

	* 修正攻擊動畫未完全播完的bug

	* 新增敵方攻擊動畫

	* 新Class:

	* 新增nekoLibrary貓咪的圖鑑可以得到貓咪各項資訊(由nekoAnimation存取)

	* 新增rivalLibrary敵方的圖鑑可以得到敵方各項資訊(由rivalAnimation存取)

* ### **2022/5/5:**

	* Library資料建立與更新

	* 角色可讀取到Library中的資料

	* 在圖鑑裡新增角色圖片並回傳(可選擇要哪隻角色)

* ### **2022/5/10:**

	* 現在畫面中可以同時有多隻角色

* ### **2022/5/11:**

	* 修正角色間距問題並新增HeadGap變數來判斷角色起始位置在哪裡

	* 敵方角色已可播放擊退動畫

	* 更新敵方資料庫

	* 新增originY變數可調整每個角色起始Y座標，新增有參數的constructor可放入要派出角色的名字

	* 新Class:新增nekoButton提供顯示角色按鈕的能力

* ### **2022/5/12:**

	* 將貓咪按鈕放置到遊戲畫面

* ### **2022/5/18:**

	*更新貓咪資料庫

* ### **2022/5/19:**

	*貓咪按鈕更新:當按鈕被按下時圖片會變暗，此時按下不會有任何反應
，直到延遲時間到時圖片會恢復正常按下也會有反應

* ### **2022/5/20:**

	* 貓咪按鈕更新:現在按下按鈕可以派出貓咪但還不能派出噁心貓
	* 缺少判斷目前派出的貓咪是第幾個來改變Constructor的值


* ### **2022/5/21:**

	* 新增噁心貓動畫及建立圖鑑，按鈕可派出完整9隻角色了且能正確派出按鈕上面圖片的角色

	* 修正按下最後一個按鈕會出現錯誤的問題，現在按最後一個按鈕不會有任何反應

* ### **2022/5/22:**

	* 新增三個變數在mygame.cpp中:

	* int	activateNeko;			//正在執行onShow，moveForward，loadBitmap的角色數量
	* int	currentNekoQuantity;		//目前畫面上的貓咪數量
	* int   readyToFightNeko;	  	//即將出動的貓咪(此為Neko陣列中的第N個貓咪)

	* 可以去判斷目前貓咪的狀態

	* 修正按下按鈕後會出現兩隻貓咪的問題，現在按下能正常派出貓咪(但超過最大可派出貓咪數時還沒辦法顯示無法派出貓咪且第20隻貓咪會因為再按下按鈕被取代)

	* 已解決第20隻被取代問題，將會尋找已經被擊退的貓咪並取代

	* 修正貓咪被擊退時目前場上貓咪總數可能不會減一的問題

* ### **2022/5/23:**

	* 新增無法出擊文字:當畫面上的貓咪數量等於最大貓咪數量就會出現無法出擊的文字

	* 修正調整最大可派出貓咪數會當機的問題

* ### **2022/5/25:**

	* 在NekoLibrary中加入cost變數可儲存派出貓咪需花費的金額

	* 在nekoButton中加入affordable來判斷目前的金額能不能派出這隻貓
	* 也加入了以下函式:
	* void updateAffordable();			//更新目前這隻貓是否有足夠的錢派出
	* bool isAffordable();				//回傳目前的金錢是否能派出這隻貓咪
	* int  costMoney();					//扣錢錢

	* 現在要有足夠的錢才能派出貓貓且派出貓貓後會扣錢錢(目前還未有角色附上金額的圖片)

* ### **2022/5/26:**

	* 已更新為角色附上金額的圖片

	* 貓咪按鈕已更新為3種不同模式:

	* 1.目前金額不足
	* 2.目前金額足夠
	* 3.冷卻中

	* 修正目前金額已足夠卻不能派出貓咪的問題

* ### **2022/5/31:**

	* 新Class:新增maxMoney提供顯示最大整數圖形的能力

	* 新增最大金額的數字圖形且目前金額若大於等於最大金額就不會再增加了

	* 新Class:新增levelUpButton提供升級錢包按鈕的能力

	* 新增升級錢包按鈕到畫面中，點按後可正常升級且會變更圖片和扣錢和增加最大金額(還缺升級後目前金額增加的量)

	* Bug:目前金額增加時若不是1會造成目前金額大於最大金額

* ### **2022/6/1:**

	* 完成升級後目前金額增加的量

	* 新增變數至mygame.cpp: moneyDelay(金錢增加速度延遲)

	* 修正已有足夠金額升級時升級按鈕卻無法按的狀況

	* 修正目前金額可能會超過最大金額的問題

* ### **2022/6/2:**

	* 更換主畫面介面

	* 資料庫:貓咪與敵方資料庫更新

	*	 新增originX變數到資料庫中(可調整角色起始的X座標)

* ### **2022/6/3:**

	* 將砲塔的屬性從MovingBitmap改為nekoAnimation or rivalAnimation(角色可以去攻擊砲塔)

	* 新增函數getHeadPostion至nekoAnimation 及 rivalAnimation 可取得角色的頭部位置

	* 新Class:新增nekoDetector:提供偵測哪隻貓咪要設為目標的能力

	* 現在可以偵測哪一隻角色要設為目標(貓咪偵測已完成，敵人偵測還未完成)

* ### **2022/6/5:**

	* 若砲塔的生命值小於等於0，遊戲就結束

	* 設定遊戲重新開始時的初始值

* ### **2022/6/6:**

	* 新Class:新增rivalDetector:提供偵測哪隻敵人要設為目標的能力

	* 設定遊戲重新開始時的初始值

	* 現在敵人可自動產出，貓咪可攻擊敵方砲塔

* ### **2022/6/9:**

	* 新增兩個新的GAME_STATES:GAME_STATE_Neko_Win,GAME_STATE_Rival_Win(勝利和失敗兩個狀態)

	* 新增勝利和失敗的畫面和音樂

	* 新增砲塔上的生命值資訊

	* 主畫面要按到遊戲開始按鈕才能進入遊戲

	* Game_STATES全部建置完畢(從遊戲開始到選擇關卡到開始遊戲到遊戲結束)

	* 新Class:新增stageSelector:這個class提供選擇關卡的能力

	* 加入遊戲音效

* ### **2022/6/10:**

	* 新Class:新增stageImformation:這個class提供關卡資訊的能力

	* 可依照目前關卡更改敵方砲塔，背景圖，關卡名稱，音樂

	* 新增中止遊戲按鈕

	* Bug:bitmap讀取一次後就無法再重新讀取可能需要在class中寫好讀取和顯示哪一個

* ### **2022/6/13:**

	* 修正讀取關卡圖片的問題

	* 新增4個關卡(關卡內容皆有更新)

	* 更新主畫面圖示

* ### **2022/6/14:**

	* 新增3個關卡(關卡內容皆有更新)

	* 修正在畫面上角色總數的問題可能造成無法再派出角色




