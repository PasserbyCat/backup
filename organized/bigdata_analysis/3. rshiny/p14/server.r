library(shiny)
library(datasets)
source("global.r")#這步很重要
#太過聰明的瀏覽器會記錄第一次開啟時的結果
#導致發生程式碼修改頁面卻沒有修改的情況
shinyServer(function(input, output) {
  datasetInput <- reactive({
    switch (input$dataset,
            "Hotel" = hotel,
            "Viewpoint" = viewpoint
    )
  })
  output$caption <- renderText({
    input$dataset
  })
  output$view <- renderTable({
    head(datasetInput(), n = input$obs)
  })
})