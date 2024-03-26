__本課程內容為web網頁設計__  
  
_1. HW1_  
- 主旨 : 利用wordpress架設個人blog  
- 任務 :   
> install server  
> > apache & error page  
> > php  
> > MySQL  
> install wordpress  
> > install wordpress  
> > chang wordpress template  
> > add gallery(plugin)  
> post 2 articles on th blog  
> > self-introduction  
> > any suggestion about this class  
- Bonus :   
> register hostname(DNS)  
> https protocol  
  
_2. 四系迎新報名網頁_  
- 主旨 : 利用bootstrap設計報名網頁  
- 任務 :   
> HTML Form_使用者報名資訊  
> > 必須含ratio或check box  
> > 至少五項基本資料  
> > 至少三項防呆機制(可利用HTML5內建或利用pattern)  
> CSS  
> > inline styles  
> > embedded style sheets  
> > linking external style sheets  
> 手機和電腦呈現不同風格之頁面  
> 產生報名表  
> > 參考s學號_HW2.php  
> > 印出使用者輸入之資訊  
> > table(需合併儲存格)  
> > CSS  
> 寄發確認信  
> > 發送成功  
> > 需有使用者輸入資訊  
> > 產生QRcodee  
> > QRcode以附件寄出  
- Bonus : 
> W3C Validator
> CSS validator
> 報名資料存入database
> 掃描QRcode可直接抵達報名表頁面
  
_3. 階層式分群_  
- 主旨 : 利用Javascript寫一程式，自動找出與某個州小於某個距離的所有州  
> database : 美國50州犯罪率的階層分群樹(參考hw3.js)  
> 距離定義 : 往上、下距離設為1  
> 其他條件 : height要小於50  
> 變數說明 :   
> > state : 每州的名稱，共50筆資料  
> > height : 每次合併時的距離，共49筆資料(50州只需合併49次)  
> > merge : 每次合併之資訊，共49筆資料，用以紀錄是哪兩個值進行合併  
> input : (參考hw3.html)  
> > 距離  
> > 目標州  
> output :   
> > 所有符合的州名(按照文字排序且用,分隔)  
  
_4. 縮網址系統_
- 做法 : 
> 利用apache .htaccess的rewrite設定執行php
> 使用者輸入網址後透過php和資料庫連線
> 擷取資料庫內容之原始連結
> 透過php redirect轉到該頁面
- 任務 : 
> 使用者頁面 
> > 使用者輸入網址
> > 透過ajax給短網址
> > php連線資料庫
> > 短網址不重複產生(相同頁面為同樣短網址且短網址設定不可重複)
> 縮網址系統架構
> > apache .htaccess設定
> > 資料庫設計
> > php接收使用者網址
> > php連線資料庫
> > 資料庫搜尋原始網址
> > php自動轉網址
- Bonus : 
> 加入google adsense
- Hint(keyword) : 
> php redirect
> xampp .htaccess
> htaccess rewrite
