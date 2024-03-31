x=c(3,1,2,1,1,4)
names(x)=c("A","B","C","D","E","F")
x[x==1]#輸出在x裡值為1的
which(x==1)#回傳位置
unique(x)#回傳唯一的元素
length(x)
sort(x)#對數值做排序
order(x)#對位置上的數值做排序
order(x, decreasing=T)