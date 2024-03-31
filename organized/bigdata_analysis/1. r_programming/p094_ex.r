cn = colnames(iris[1:4])
rn = unique(iris[,5])
y = array(0,c(length(rn),length(cn)))
rownames(y) = rn
colnames(y) = cn
for (i in 1:length(rn))#三種物種共跑三次
{
  for (j in 1:length(cn))#四種特性
  {
    y[i,j] = mean(iris[iris[,5]==rn[i],j])
  }
}
y