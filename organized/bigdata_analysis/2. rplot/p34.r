#各種簡單的統計數據
data(iris)
x = iris[,1]
mean(x)  #average
median(x) #median
quantile(x,1) #Max
quantile(x,0.2) #the value in 20%
summary(x)
