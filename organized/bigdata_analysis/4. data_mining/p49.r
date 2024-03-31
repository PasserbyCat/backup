#install.packages("C50")
library(C50)
mod1 <- C5.0(Species ~ ., data = iris)
#mod1 <- C5.0(Species ~ Sepal.Length + Sepal.Width + Petal.Length + Petal.Width, data = iris)_同上
#mod1 <- C5.0(
#  as.formula( 轉成公式
#    paste0("Species ~", 補上前面要篩選的
#           paste(colnames(iris)[1:4], _取出要的
#                 collapse = "+"))), 變成字串
#  data = iris)_同上
#前面擺要分析的~後面擺參考屬性(.代表不包含前面的所有欄位)
plot(mod1)
plot(mod1,subtree=3)#只看從3畫下去的
