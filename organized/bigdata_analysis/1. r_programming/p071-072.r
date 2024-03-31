x = list(A=c(1,2,3), B=matrix(c("a", "b", "c", "d"),nrow=2,ncol=2))#裡面有AB兩物件
#list型態不拘
x
names(x)#每個物件名稱
length(x)#有幾個物件
x$A[2]#$是取值,取A物件的第二項
unname(x)#去除物件名稱