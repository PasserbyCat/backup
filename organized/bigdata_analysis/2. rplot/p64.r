library(plotly)
p = plot_ly(data = iris, y = ~Sepal.Length, type = "box", 
            name="Sepal.Length") %>%
            add_trace(y = ~Sepal.Width, name="Sepal.Width") %>%
            add_trace(y = ~Petal.Length, name="Petal.Length") %>%
            add_trace(y = ~Petal.Width, name="Petal.Width") #add_trace加資料
p