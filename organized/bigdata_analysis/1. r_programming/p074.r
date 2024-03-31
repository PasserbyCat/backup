y=data.frame(WD=c(2,3), ID=c("tinin","bp"), Date=as.Date(c("2016-02-23","2016-02-24")))
#dataframe的每個column相同型態
y
y$ID#可用欄位名稱找資料
y$ID[2]
y[,c(2,3)]#欄位順序變動,可能抓錯資料