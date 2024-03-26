# web design
_本課程內容為web網頁設計_  
## HW1網站架設  
- 主旨 : 利用wordpress架設個人blog  
- 任務 :  
    1. install server  
        1. apache & error page  
        2. php  
        3. MySQL  
    2. install wordpress  
        1. install wordpress  
        2. chang wordpress template  
        3. add gallery(plugin)  
    3. post 2 articles on th blog  
        1. self-introduction  
        2. any suggestion about this class  
- Bonus :  
    1. register hostname(DNS)  
    2. https protocol  
  
## HW2四系迎新報名網頁  
- 主旨 : 利用bootstrap設計報名網頁  
- 任務 :  
    1. HTML Form_使用者報名資訊  
        1. 必須含ratio或check box  
        2. 至少五項基本資料  
        3. 至少三項防呆機制(可利用HTML5內建或利用pattern)  
    2. CSS  
        1. inline styles  
        2. embedded style sheets  
        3. linking external style sheets  
    3. 手機和電腦呈現不同風格之頁面  
    4. 產生報名表  
        1. 參考s學號_HW2.php  
        2. 印出使用者輸入之資訊  
        3. table(需合併儲存格)  
        4. CSS  
    5. 寄發確認信  
        1. 發送成功  
        2. 需有使用者輸入資訊  
        3. 產生QRcodee  
        4. QRcode以附件寄出  
- Bonus : 
    1. W3C Validator
    2. CSS validator
    3. 報名資料存入database
    4. 掃描QRcode可直接抵達報名表頁面
## HW3階層式分群  
- 主旨 : 利用Javascript寫一程式，自動找出與某個州小於某個距離的所有州  
    1. database : 美國50州犯罪率的階層分群樹(參考hw3.js)  
    2. 距離定義 : 往上、下距離設為1  
    3. 其他條件 : height要小於50  
    4. 變數說明 :   
        1. state : 每州的名稱，共50筆資料  
        2. height : 每次合併時的距離，共49筆資料(50州只需合併49次)  
        3. merge : 每次合併之資訊，共49筆資料，用以紀錄是哪兩個值進行合併  
    5. input : (參考hw3.html)  
        1. 距離  
        2. 目標州  
    6. output :   
        1. 所有符合的州名(按照文字排序且用,分隔)  
## HW4縮網址系統
- 做法 : 
    1. 利用apache .htaccess的rewrite設定執行php
    2. 使用者輸入網址後透過php和資料庫連線
    3. 擷取資料庫內容之原始連結
    4. 透過php redirect轉到該頁面
- 任務 : 
    1. 使用者頁面 
        1. 使用者輸入網址
        2. 透過ajax給短網址
        3. php連線資料庫
        4. 短網址不重複產生(相同頁面為同樣短網址且短網址設定不可重複)
    2. 縮網址系統架構
        1. apache .htaccess設定
        2. 資料庫設計
        3. php接收使用者網址
        4. php連線資料庫
        5. 資料庫搜尋原始網址
        6. php自動轉網址
- Bonus : 
    1. 加入google adsense
- Hint(keyword) : 
    1. php redirect
    2. xampp .htaccess
    3. htaccess rewrite
