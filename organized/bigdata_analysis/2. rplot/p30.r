png("p30.png",#檔名
    width = 10,#寬
    height = 5,#長
    res = 300,#dpi
    units="in")
x=cars[,1]
y=cars[,2]
plot(x,y)
dev.off()#做法類似sink,需使用此行關閉
