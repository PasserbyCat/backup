library(rowr)
library(plotly)
x=read.csv("p65_ex_Taipei_LAND_A.csv",sep=",",header=T)

dist = unique(x[,1])#取出A~L
out = NULL
for (i in 1:length(dist)) {
  tmp = x[which(x[,1] == dist[i]),2]#將同樣英文字母的數據抓出來
  out = cbind.fill(out, tmp, fill = NA)
  #由於我們無法確認交易量是否相同
  #(cbind需要長度相同)
  #故使用fill將未滿長度的部分用NA填滿
}
out = out[,-1]#刪掉1st column
colnames(out) = dist
boxplot(out)

#作法同上面function
x=read.csv("p65_ex_Taipei_LAND_A.csv",sep=",",header=T)
boxplot(Price~Location, data=x)#x是price，y是location(公式)

#plotly
x=read.csv("p65_ex_Taipei_LAND_A.csv",sep=",",header=T)
dist = unique(x[,1])#取出A~L
tmp = x[which(x[,1] == dist[1]),2]#將第一個英文字母的數據抓出來
p = plot_ly(y = tmp, type = "box", name = dist[1])
for (i in 2:length(dist)) {
  tmp = x[which(x[,1] == dist[i]),2]#將同樣英文字母的數據抓出來
  p = p %>% add_trace(y = tmp, name = dist[i])#將新取出來的加進去
}
p
