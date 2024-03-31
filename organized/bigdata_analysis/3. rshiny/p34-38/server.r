library(shiny)
library(dplyr)
library(ggplot2)
shinyServer(function(input, output) {
  datasetInput <- reactive({
    switch(input$type,
           "Max" = x[,1:4],
           "Min" = x[,c(1:3,5)])
  })
  output$view <- renderTable({
    dataset=datasetInput()
    dataset%>% filter(locationName==input$local)
  })
  output$mpgPlot <- renderPlot({
    dataset = datasetInput()
    data= dataset %>% filter(locationName==input$local)
    plot(data[,4],xlab="Time",ylab="Temperature",type="l",axes=FALSE)
    lbs=as.vector(unique(data[,2]))
    axis(1, at=1:length(lbs), lab=lbs)#設定x為時間
    axis(2, las=1, at=0:40)#設定y為數值
  })
})
