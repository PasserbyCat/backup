x=read.csv("p077_ex_Taiwan.csv",header=T)
sum(x$Resident)
x$Density=x$Resident/x$Area
x$Density
x[order(x$Density,decreasing=TRUE),]
x[which(x$Resident > 2000000),1]