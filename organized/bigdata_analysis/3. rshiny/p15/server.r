library(shiny)
library(datasets)
library(dplyr)
source("global.r")#這步很重要
#太過聰明的瀏覽器會記錄第一次開啟時的結果
#導致發生程式碼修改頁面卻沒有修改的情況
shinyServer(function(input, output) {
  datasetInput <- reactive({
    x %>% filter(Name == input$dist)#找區域名稱
  })
  output$caption <- renderText({
    datasetInput()
    summary(dataset)
  })
  output$view <- renderTable({
    dataset = datasetInput()
    y    = dataset[,2]
    bins = seq(min(y), max(y), length.out = input$bins + 1)
    hist(y, breaks = bins, col = 'darkgray', border = 'white')
  })
})