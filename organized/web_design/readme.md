本課程內容為web網頁設計<br>
<br>
1. HW1<br>
    主旨 : 利用wordpress架設個人blog<br>
    任務 : <br>
        install server<br>
            apache & error page<br>
            php<br>
            MySQL<br>
        install wordpress<br>
            install wordpress<br>
            chang wordpress template<br>
            add gallery(plugin)<br>
        post 2 articles on th blog<br>
            self-introduction<br>
            any suggestion about this class<br>
    Bonus : <br>
        register hostname(DNS)<br>
        https protocol<br>
<br>
2. 四系迎新報名網頁<br>
    主旨 : 利用bootstrap設計報名網頁<br>
    任務 : <br>
        HTML Form_使用者報名資訊<br>
            必須含ratio或check box<br>
            至少五項基本資料<br>
            至少三項防呆機制(可利用HTML5內建或利用pattern)<br>
        CSS<br>
            inline styles<br>
            embedded style sheets<br>
            linking external style sheets<br>
        手機和電腦呈現不同風格之頁面<br>
        產生報名表<br>
            參考s學號_HW2.php<br>
            印出使用者輸入之資訊<br>
            table(需合併儲存格)<br>
            CSS<br>
        寄發確認信<br>
            發送成功<br>
            需有使用者輸入資訊<br>
            產生QRcodee<br>
            QRcode以附件寄出<br>
    Bonus : 
        W3C Validator
        CSS validator
        報名資料存入database
        掃描QRcode可直接抵達報名表頁面
<br>
3. 階層式分群<br>
    主旨 : 利用Javascript寫一程式，自動找出與某個州小於某個距離的所有州<br>
        database : 美國50州犯罪率的階層分群樹(參考hw3.js)<br>
        距離定義 : 往上、下距離設為1<br>
        其他條件 : height要小於50<br>
        變數說明 : <br>
            state : 每州的名稱，共50筆資料<br>
            height : 每次合併時的距離，共49筆資料(50州只需合併49次)<br>
            merge : 每次合併之資訊，共49筆資料，用以紀錄是哪兩個值進行合併<br>
        input : (參考hw3.html)<br>
            距離<br>
            目標州<br>
        output : <br>
            所有符合的州名(按照文字排序且用,分隔)<br>
<br>
4. 縮網址系統
    做法 : 
        利用apache .htaccess的rewrite設定執行php
        使用者輸入網址後透過php和資料庫連線
        擷取資料庫內容之原始連結
        透過php redirect轉到該頁面
    任務 : 
        使用者頁面 
            使用者輸入網址
            透過ajax給短網址
            php連線資料庫
            短網址不重複產生(相同頁面為同樣短網址且短網址設定不可重複)
        縮網址系統架構
            apache .htaccess設定
            資料庫設計
            php接收使用者網址
            php連線資料庫
            資料庫搜尋原始網址
            php自動轉網址
    Bonus : 
        加入google adsense
    Hint(keyword) : 
        php redirect
        xampp .htaccess
        htaccess rewrite
