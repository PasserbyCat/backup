x = unique(iris[,5])#把三個物種取出來
y = NULL
for (i in x)#三個物種各自取mean
{
 y[i] = mean(iris[iris[,5]==i,1])
}
y

x = unique(iris[,5])
y = 0
for (i in 1:length(x))#三種物種共跑三次
{
  y[i] = mean(iris[iris[,5]==x[i],1])
}
names(y)=x#將1:3的結果命名
y