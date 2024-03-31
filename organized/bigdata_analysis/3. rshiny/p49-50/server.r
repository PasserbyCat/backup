library(shiny)
library(datasets)
shinyServer(function(input, output) {
  datasetInput <- reactive({
    switch(input$dataset,
           "R" = "http://www.r-project.org/Rlogo.png",
           "Java" = "http://d3gnp09177mxuh.cloudfront.net/tech-page-images/java.png")
  })
  output$view <- renderUI({
    img=tags$img(src=datasetInput(),#tag是內建的(R裡面支援html的指令)
                 width=500,heigth=500)
    h6("Image:",br(),img)
  })
})