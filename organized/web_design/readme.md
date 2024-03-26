__本課程內容為web網頁設計__  
_1. HW1_  
主旨 : 利用wordpress架設個人blog  
任務 :  
:install server  
~apache & error page  
~php  
~MySQL  
[Tab][Tab]install wordpress  
[Tab][Tab][Tab]install wordpress  
[Tab][Tab][Tab]chang wordpress template  
[Tab][Tab][Tab]add gallery(plugin)  
[Tab][Tab]post 2 articles on th blog  
[Tab][Tab][Tab]self-introduction  
[Tab][Tab][Tab]any suggestion about this class  
[Tab]Bonus :   
[Tab][Tab]register hostname(DNS)  
[Tab][Tab]https protocol  
  
_2. 四系迎新報名網頁_  
[Tab][Tab][Tab]主旨 : 利用bootstrap設計報名網頁  
[Tab][Tab][Tab]任務 :   
[Tab][Tab]HTML Form_使用者報名資訊  
[Tab]必須含ratio或check box  
[Tab]至少五項基本資料  
[Tab]至少三項防呆機制(可利用HTML5內建或利用pattern)  
[Tab][Tab]CSS  
[Tab]inline styles  
[Tab]embedded style sheets  
[Tab]linking external style sheets  
[Tab][Tab]手機和電腦呈現不同風格之頁面  
[Tab][Tab]產生報名表  
[Tab]參考s學號_HW2.php  
[Tab]印出使用者輸入之資訊  
[Tab]table(需合併儲存格)  
[Tab]CSS  
[Tab][Tab]寄發確認信  
[Tab]發送成功  
[Tab]需有使用者輸入資訊  
[Tab]產生QRcodee  
[Tab]QRcode以附件寄出  
[Tab][Tab][Tab]Bonus : 
[Tab][Tab]W3C Validator
[Tab][Tab]CSS validator
[Tab][Tab]報名資料存入database
[Tab][Tab]掃描QRcode可直接抵達報名表頁面
_3. 階層式分群_  
[Tab][Tab][Tab]主旨 : 利用Javascript寫一程式，自動找出與某個州小於某個距離的所有州  
[Tab][Tab]database : 美國50州犯罪率的階層分群樹(參考hw3.js)  
[Tab][Tab]距離定義 : 往上、下距離設為1  
[Tab][Tab]其他條件 : height要小於50  
[Tab][Tab]變數說明 :   
[Tab]state : 每州的名稱，共50筆資料  
[Tab]height : 每次合併時的距離，共49筆資料(50州只需合併49次)  
[Tab]merge : 每次合併之資訊，共49筆資料，用以紀錄是哪兩個值進行合併  
[Tab][Tab]input : (參考hw3.html)  
[Tab]距離  
[Tab]目標州  
[Tab][Tab]output :   
[Tab]所有符合的州名(按照文字排序且用,分隔)  
_4. 縮網址系統_
[Tab]做法 : 
[Tab][Tab]利用apache .htaccess的rewrite設定執行php
[Tab][Tab]使用者輸入網址後透過php和資料庫連線
[Tab][Tab]擷取資料庫內容之原始連結
[Tab][Tab]透過php redirect轉到該頁面
[Tab][Tab][Tab]任務 : 
[Tab][Tab]使用者頁面 
[Tab]使用者輸入網址
[Tab]透過ajax給短網址
[Tab]php連線資料庫
[Tab]短網址不重複產生(相同頁面為同樣短網址且短網址設定不可重複)
[Tab][Tab]縮網址系統架構
[Tab]apache .htaccess設定
[Tab]資料庫設計
[Tab]php接收使用者網址
[Tab]php連線資料庫
[Tab]資料庫搜尋原始網址
[Tab]php自動轉網址
[Tab][Tab][Tab]Bonus : 
[Tab][Tab]加入google adsense
[Tab][Tab][Tab]Hint(keyword) : 
[Tab][Tab]php redirect
[Tab][Tab]xampp .htaccess
[Tab][Tab]htaccess rewrite
