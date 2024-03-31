a=data.frame(WD=c(2,3,4), ID=c("tinin", "bp","lee"), 
             Date=as.Date(c("2016-02-23","2016-02-24","2016-02-25")),
             PHONE=c("0910","0955","0933")) 
b=data.frame(NUM=c("0910","0955","0987","0966"),
             NAME=c("CHT","FET","TM","PHS"))
merge(a,b, by.x="PHONE", by.y="NUM", all=FALSE) #inner join