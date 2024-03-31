#需用linux指令編譯c成可執行檔
#R CMD SHLIB p139_test2.c 
#此指令會生成 p139_test2.so p139_test2.o
dyn.load("p139_test2.so")#將library匯入
result<-.C("A",a="")#使用C程式碼/使用A函式/傳參數
result$a
