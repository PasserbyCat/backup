a=data.frame(WD=c(2,3,4), ID=c("tinin","bp","lee"), 
             Date=as.Date(c("2016-02-23","2016-02-24","2016-02-25")),
             PHONE=c("0910","0955","0933")) 
write.table(a, file="p112_out.csv", row.names=F, 
            col.names=T, sep=",")#只有table可以指定是否要保留name
