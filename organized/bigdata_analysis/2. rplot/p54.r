library(plotly)
a = as.data.frame(table(iris[,5]))
p = plot_ly( data = a, 
             labels  = ~Var1, 
             values = ~Freq, 
             type = "pie") %>%#圓餅圖
    layout(title = 'iris',#為要刪掉軸(舊版本有x,y軸)
           xaxis = list(showgrid = FALSE, 
                        zeroline = FALSE, 
                        showticklabels = FALSE),
           yaxis = list(showgrid = FALSE, 
                        zeroline = FALSE, 
                        showticklabels = FALSE))
p