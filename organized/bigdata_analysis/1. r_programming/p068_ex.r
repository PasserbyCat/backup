x=read.csv("p068_ex_PM25.csv",sep=",",header=T)
apply (x[3:26],1,mean,na.rm=T)#對該dataset(x)的哪些([3:26])row(1)取mean,且去除NA值
#產生NaN數據->整天沒資料