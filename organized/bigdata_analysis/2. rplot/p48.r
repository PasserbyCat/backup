x=round(table(iris[,5])/length(iris[,5])*100,2)#取小數後幾位
lbls=paste(names(x),x,"%")#自製數據
pie(table(iris[,5]),labels=lbls)