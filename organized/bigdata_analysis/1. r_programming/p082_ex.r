x=read.csv("p082_ex_AQX.csv",header=T,sep=",")
y=read.csv("p082_ex_AQXcite.csv",header=T,sep=",")
merge(x,y, by="SiteName",all=TRUE) #outer join(x,y的聯集)
merge(x,y, by="SiteName",all.x=TRUE) #left join(x沒有的不join)
merge(x,y, by="SiteName",all.y=TRUE) #right join(y沒有的不join)
merge(x,y, by="SiteName",all=FALSE) #inner join(x,y的交集)
#四種都一樣 因為1to1且onto