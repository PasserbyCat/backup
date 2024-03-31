library(shiny)
library(dplyr)
library(datasets)
library(ggplot2)
shinyServer(function(input, output) {

  output$caption <- renderText({
    paste(input$dist,"~",input$type)
  })
  output$table <- renderTable({
    data = x %>% filter(locationName == input$dist)
    data
  })
  output$distPlot <- renderPlot({
    data = x %>% filter(locationName == input$dist)
    if (input$type =="Max Temp") {
      ggplot(data, 
             aes(startTime, Max.Temp., group=locationName, colour=locationName))
      + geom_line()
      + labs(x="startTime", y="Temp.", title="Max. Temp.")
      + theme(legend.position = "none")
    } else {
      ggplot(data, 
             aes(startTime, Min.Temp., group=locationName, colour=locationName))
      + geom_line()
      + labs(x="startTime", y="Temp.", title="Min. Temp.")
      + theme(legend.position = "none")
    }
  
  }) 
})
