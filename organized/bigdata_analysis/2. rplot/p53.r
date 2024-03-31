library(plotly)
a = as.data.frame(table(iris[,5]))
p = plot_ly( data = a,
             x = ~Var1,
             y = ~Freq,
             name = "iris",
             type = "bar")#長條圖
p