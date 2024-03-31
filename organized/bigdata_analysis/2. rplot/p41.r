library(plotly)
p = plot_ly(data = iris,#資料集
            x = ~Sepal.Length,#~後面的是前面dataset的column anme(無~則為變數名稱)
            y = ~Sepal.Width,
            type ="scatter",#散佈圖
            mode = 'markers')#點
p