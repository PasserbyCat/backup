x=cars[,1]
y=cars[,2]
plot(x,y)
fit = lm(y~x)
abline(fit, col = "red")
cor(x,y)#相關性
cor(x^2,y)#根據運動學,理想下為1
