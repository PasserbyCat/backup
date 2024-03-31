a=rep(c(0),times=81)
dim(a)=c(9,9)#99乘法表的例子
for (i in 1:9) { 
  for(j in 1:9){
   a[i,j]=i*j
  }
}