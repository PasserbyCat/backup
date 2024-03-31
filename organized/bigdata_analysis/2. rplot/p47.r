pie(table(iris[,5]))#標籤即為column name

x=c("Flower A","Flower B","Flower C")
pie(table(iris[,5]),labels=x)
