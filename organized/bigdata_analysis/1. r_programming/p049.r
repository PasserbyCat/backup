x = as.Date("2022/01/19")
x = x+1 # add 1 day
x
y = as.Date("2023/01/20")
a = difftime(y,x,unit="days")#計算y和x之間差幾天
a
as.integer(a)
age = as.integer(difftime(Sys.Date(),"2001-01-01",unit="days") /365.25)#Sys.Date是今天的日期
age