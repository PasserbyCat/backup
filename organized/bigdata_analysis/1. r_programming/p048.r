x = as.Date("2021/02/25")
a = as.character(x)
a

as.numeric(substring(a,1,4))#year
as.numeric(substring(a,6,7))#month
as.numeric(substring(a,9,10))#day
