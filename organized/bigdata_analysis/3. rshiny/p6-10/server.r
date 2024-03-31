library(shiny)

# Define server logic required to draw a histogram
shinyServer(function(input, output) {
  
  # Expression that generates a histogram. The expression is
  # wrapped in a call to renderPlot to indicate that:
  #
  #  1) It is "reactive" and therefore should be automatically
  #     re-executed when inputs change
  #  2) Its output type is a plot
  
  output$distPlot <- renderPlot({ 
    x    = iris[, 2]  # Iris dataset (Sepal.Width)
    bins = seq(min(x), max(x), length.out = input$bins + 1)#讓使用者設定要幾個bar(+1 -> min和max)
    
    # draw the histogram with the specified number of bins
    hist(x, breaks = bins, col = 'darkgray', border = 'white')#break強制設定中斷點
  })  
})