x=c(1,2,3,4)
y=paste("a",x,sep=":")#對向量中的每一項串上a且用:分隔
y
y=paste("a",x,sep="")#意同y=paste0("a",x)
y
x=c(x,5:7)#將兩個向量做串接
x
x=c(x,c(8,9))
x
a=c("X","Y","Z")
b=paste(a,collapse = "_")#將向量中的每個元素串接成一個元素
b
