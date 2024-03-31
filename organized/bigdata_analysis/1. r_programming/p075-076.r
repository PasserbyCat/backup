y=data.frame(WD=c(2,3), ID=c("tinin","bp"),Date=as.Date(c("2016-02-23","2016-02-24")))
z=data.frame(PHONE=c("0910","0911"))
cbind(y,z)#多欄位名稱和該欄位的資料
x=data.frame(WD=4,ID="lee",Date=as.Date("2016-02-25"))
rbind(y,x)#多一個資料來源
w = rbind(y,x)
w
w = w[order(w$WD,decreasing = TRUE),]#order回傳index,decreasing使其從大到小
w