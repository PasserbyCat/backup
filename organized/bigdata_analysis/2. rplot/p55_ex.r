x=read.csv("p55_ex_Taiwan.csv",sep=",")

p = plot_ly( data = x,
             x = ~County,
             y = ~Resident,
             name = "resident",
             type = "bar")#長條圖
p = plot_ly( data = x,
             x = ~County,
             y = ~Area,
             name = "resident",
             type = "bar")#長條圖
p = plot_ly( data = x, 
             labels  = ~County, 
             values = ~Resident, 
             type = "pie")
p = plot_ly( data = x, 
             labels  = ~County, 
             values = ~Area, 
             type = "pie")
