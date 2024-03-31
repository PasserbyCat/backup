x=iris[,3]
y=iris[,4]
out=lm(y~x) # lm :linear model:迴歸線(由x預測y)
out
out$coefficients[1]
out$coefficients[2]
#y = $coefficients[1]+$coefficients[2] * x