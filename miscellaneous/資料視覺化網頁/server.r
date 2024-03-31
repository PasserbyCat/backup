library(shiny)
library(datasets)
library(plotly)
library(dplyr)
source("global.r")

shinyServer(function(input,output){
  datasetInput <- reactive({

  })
  output$plot<-renderPlotly({
    #input$place/input$chart
    if(input$place == "Taiwan") {
      data = taiwan_data %>% 
             select(縣市, 確定病例數) %>%
             group_by(縣市) %>%
             summarise(total = sum(確定病例數))
      data[which(data$縣市 == "空值"), 1] = "境外移入"
      if (input$chart == "pie chart") {
        p = plot_ly(data, 
                    labels = ~縣市,
                    values = ~total,
                    type = "pie")
      } else {
        p = plot_ly(data, 
                    x = ~縣市,
                    y = ~total,
                    type = "bar")
        p
      }
      p
    } else {
      if (input$chart == "pie chart") {
        p = plot_ly(global_data, 
                    labels = ~country_ch,
                    values = ~cases,
                    type = "pie")
      } else {
        p = plot_ly(global_data, 
                    x = ~country_ch,
                    y = ~cases,
                    type = "bar")
        p
      }
      p
    }
  })
})