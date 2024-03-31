library(shiny)
library(datasets)
shinyServer(function(input, output) {
  datasetInput <- reactive({
    switch(input$dataset,
          "iris" = iris,
          "mtcars" = mtcars,
          "USArrests" = USArrests)
  })
  output$caption <- renderText({
    input$caption
  })
  output$summary <- renderPrint({
    dataset = datasetInput()
    summary(dataset)
  })
  output$view <- DT::renderDataTable({
    head(datasetInput(), n = input$obs)
  })
})
