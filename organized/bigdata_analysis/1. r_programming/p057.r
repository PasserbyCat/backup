x=c("4","2","8","A","B","C")
mode(x)
y = as.integer(x)
y
mode(y)
z = na.omit(y)#將na去除(並記錄na的位置)
z
y[is.na(y)] = 0#或y裡面有na則將其數值轉成0
y