boxplot(iris[,1:4])

dim(iris)
dim(cars)
boxplot(cbind(cars[,1:2],iris[,1:4]))
#將兩個dataset cbine後再畫圖