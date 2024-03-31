a = rep(1:3,each=50)
x= iris[,1]
y= iris[,2]
plot(x,y,col=a)#挑選錯誤資料範例

a = kmeans(iris[1:2],3)
x= iris[,1]
y= iris[,2]
plot(x,y,col=a$cluster)