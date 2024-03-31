library(shiny)
library(dplyr)
library(ggplot2)
source("global.R")
shinyServer(function(input, output) {
  output$caption <- renderText({
    paste("The type of air quality :", input$type)
  })

  output$mpgPlot <- renderPlot({
    pm25= x %>% 
          filter(TYPE==input$type) %>%#根據使用者所選擇的type
          group_by(Station,Date,TYPE)%>% 
          summarise(Ave = mean(Value)) 
    ggplot(pm25, 
           aes(Date, 
               Ave, 
               group=Station, 
               colour=Station))
    + geom_line()
    + labs(x="Date", 
           y=input$type, 
           title=paste("2014 ChungLi ",
                       input$type))
    + theme(legend.position = "none")
  })
})
