data = read.csv("p42_exchangerate.csv",header = T,sep=",")
p = plot_ly(data,
            x = ~date,#date是文字排序所以出錯
            y = ~rate,
            type = 'scatter',
            mode = 'lines')
p
