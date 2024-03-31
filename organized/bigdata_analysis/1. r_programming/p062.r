x = matrix(1:6,nrow=2,ncol=3,byrow=T)
x
rownames(x) = paste("r",1:nrow(x), sep="")#值得學的命名法
colnames(x) = paste("c",1:ncol(x), sep="")
x
x = unname(x)
x