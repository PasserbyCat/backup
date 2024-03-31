out = rep(0,4)
for (i in 1:4)
{ 
  out[i] = mean(iris[,i])
}
out#這邊的結果沒有名稱
names(out) = colnames(iris[,1:4])
out