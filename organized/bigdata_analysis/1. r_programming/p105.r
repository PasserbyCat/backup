x=read.table("load_file.csv", header=T, sep=",",colClasses=c("numeric","character","Date"))
#colClasses可直接定義該col的型態 但實在是不好用
x
x[2,]
x[,2]
colnames(x)