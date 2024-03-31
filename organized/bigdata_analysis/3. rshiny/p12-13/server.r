library(shiny)
library(datasets)
# Define server logic required to summarize and view the selected
# dataset
shinyServer(function(input, output) {
  # Return the requested dataset
  datasetInput <- reactive({#根據使用者所選(下拉式選單)進行回傳
    switch(input$dataset,
           "iris" = iris,
           "mtcars" = mtcars,
           "USArrests" = USArrests)
  })
  output$caption <- renderText({
    input$caption
  })
  # Generate a summary of the dataset
  output$summary <- renderPrint({
    dataset = datasetInput()
    summary(dataset)
  })
  # Show the first "n" observations
  output$view <- renderTable({
    head(datasetInput(), n = input$obs)
  })
})