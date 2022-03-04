#import urllib.request as req#匯入套件
import requests
#import csv 
#import selenium
#import bs4
from datetime import datetime
import json
import tkinter as tk
from PIL import Image, ImageTk
import tkinter.ttk as ttk

locationName=[]

def getTime():    
    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    #print("Current Time =", current_time) 確認時間
    tmp = current_time.split(":")
    index = 10
    hr = 0
    for i in range(2):
        hr += index * int(tmp[0][i])
        index /= 10
    #print(hr) #確認輸出
    return hr

'''
def ok(en1, en2):
    option = en1.get()
    location = en2.get()
    opcode(option , location)
'''    

def create_label_image():
    img = Image.open('C:\\Users\\JIMBO\\OneDrive\\桌面\\圖片\\月老\\pray.jpg')
    img = img.resize( (img.width // 10, img.height // 10 ) )
    imgTk =  ImageTk.PhotoImage(img)
    lbl_2 = tk.Label(window, image=imgTk)
    lbl_2.image = imgTk
    lbl_2.grid(column=0, row=0) 
    
    
def UI_Window():
    window.geometry('800x1000')  #邊框
    window.minsize(width=500,height=625) #最小邊框
    window.maxsize(width=1200,height=1500) #最大邊框
    window.iconbitmap("C:\\Users\\JIMBO\\OneDrive\\桌面\\Final_Project\\icon\\meow.ico") #標題圖示 only for .ico
    window.config(bg = "skyblue") #背景顏色
    #window.attributes("-topmost", 1) #把東西的屬性 (頁面置頂)
    #if(current_time.getTime() == hr): #抓時間去找要什麼資料
        
    lbl_intr = tk.Label(window, text="Hello User", bg='white', fg='#263238', font=('Arial', 18))
    lbl_intr.grid(column = 1, row = 0) #pack() , grid() 只能選一個用
    
    lb1 = tk.Label(window, text="請輸入您要的功能", bg='white', fg='#263238', font=('Arial', 16))
    lb1.grid(column = 0, row = 1) #pack() , grid() 只能選一個用
    

    en1 = tk.Entry() #使用者輸入
    en1.grid(column = 1, row = 1)
    
    lb2 = tk.Label(window, text="請輸入地點", bg='white', fg='#263238', font=('Arial', 16))
    lb2.grid(column = 0, row = 2) 
    print(locationName)
    combo = ttk.Combobox(window, l=['臺北市', '新北市', '桃園市', '臺中市', '臺南市', '高雄市', '基隆市', '新竹縣', '新竹市', '苗栗縣', '彰化縣', '南投縣', '雲林縣', '嘉義縣', '嘉義市', '屏東縣', '宜蘭縣', '花蓮縣', '臺東縣', '澎湖縣', '金門縣', '連江縣']) #使用者輸入
    combo.grid(column = 1, row = 2)
    combo.current(1)
    
    bt_1 = tk.Button(window, text="button", bg='red', fg='white', font=('Arial', 16),)
    bt_1['activebackground'] = 'red'
    bt_1['activeforeground'] = 'black'
    bt_1.grid(column = 1, row = 3) #botton不要包裝成函式，lable抓不到，包裝功能就好
    create_label_image()
    window.mainloop()
    

'''
    現有(提供)資訊: Wx(天氣現象) 、 MaxT(最高溫度) 、 MinT(最低溫度) 、 CI(舒適度) 、 PoP(降雨機率)
'''

'''
def opcode(option):
   
    #地點的資訊 location
    if(option == 1): #"Wx(天氣現象)"
        
    elif(option == 2): #MaxT(最高溫度)
    elif(option == 2): #MaxT(最高溫度)
    elif(option == 2): #MaxT(最高溫度)
    elif()
    else:
        
    #不管選擇是什麼最後都要給他給資訊 about 該不該出門 ...指數
    lb = tk.Label(window, text="Hello User", bg='white', fg='#263238', font=('Arial', 12))
'''

def main():
    html = requests.get("https://opendata.cwb.gov.tw/fileapi/v1/opendataapi/F-C0032-001?Authorization=CWB-2690584E-1FFF-4D4D-8270-F361A33EB494&downloadType=WEB&format=JSON")
    html.encoding = "utf-8"
    #print(html.text)
    #把雙引號弄掉
    #list1 = eval(html.text)
    text = json.loads(html.text)
    data = text['cwbopendata']['dataset']['location']#(0~21)共有22個index
    #print(text)
    keys=[]
    for i in range(22):
        locationName.append(data[i]['locationName'])#names of location
    #print(len(data[0]["weatherElement"]))
    for i in range(len(data[0]["weatherElement"])):
        for key in data[0]["weatherElement"][i].keys():
            #print(data[0]["weatherElement"][i])
            keys.append(key)
    #print(data[0]) #檢查data
    #print(keys) #檢查keys
    '''
    manyDictionary(list1,dic)
    print(dic)
    '''
    UI_Window()
    
    
    '''
    user_time = input("xx:xx(幾點幾分):").split(":")
    user_location = input("請輸入您的地點:")
    '''
window = tk.Tk()
window.title('天氣預報')
current_time = getTime()
div_size = 200
img_size = div_size * 2
main()
'''
# 公開資料檔案 氣象資料開放平台網站
url ='https://opendata.cwb.gov.tw/dataset/forecast/F-C0032-001'
# 建立一個 Request 物件，附加 Request Headers 的資訊(目的:看起來像是一個使用者進去網址)
request = req.Request(url,headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36"
    })

with req.urlopen(request) as response:
    data=response.read().decode("utf-8")
#print(data) 檢查資料是否正確

#beautifulsoup4 匯入

root = bs4.BeautifulSoup(data, "html.parser")
print(root.title.string)
'''