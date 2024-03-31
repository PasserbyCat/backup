data = read.csv("exchangerate.csv",header = T,sep=",")
data[,1] = ordered(data[,1], levels = data[,1])#要求排序的方法按照原本的排序
p = plot_ly(data, x = ~date, y = ~rate, type = 'scatter', mode = 'lines')
p
