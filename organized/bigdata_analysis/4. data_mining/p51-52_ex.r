library(ISLR)
library(C50)
high = ifelse(Carseats$Sales>=8,"YES","NO")#用Sales欄位製成二元分析
x = cbind(Carseats,high)
y = x[,-1]#這個一定要刪掉，不燃用這個肯定精準預測
y$Education = as.factor(y$Education)#他只是類別型資料，並非數值
y$high = as.factor(y$high)
mod1 = C5.0( high ~ ., data = y)
png("p51-52_ex_out.png", width = 20, height = 10, units = "in", res = 300)
plot(mod1)
dev.off()
