x=c("1","2","3","A","B","C")
mode(x)
y = as.integer(x)
y
mean(y)
mean(y,na.rm=T)#去除na