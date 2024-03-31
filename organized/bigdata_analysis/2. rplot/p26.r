x=iris[,3]
y=iris[,4]
plot(x,y)
fit=lm(y~x)
abline(fit,col=3)#直接用迴歸線畫(自動抓a,b)