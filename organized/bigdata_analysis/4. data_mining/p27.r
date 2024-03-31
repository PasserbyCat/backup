a = kmeans(iris[1:2],3)
x= iris[,1]
y= iris[,2]
a$cluster
plot(x,y,col=a$cluster)