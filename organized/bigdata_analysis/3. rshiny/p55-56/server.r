shinyServer(function(input, output) {
  datasetInput <- reactive({
    switch(input$dataset,
           "iris" = iris,
           "mtcars" = mtcars,
           "USArrests" = USArrests)
  })
  output$view <- renderTable({
    datasetInput()
  })
  output$downloadData <- downloadHandler(
    filename = function() { paste(input$dataset, '.csv', sep='') },
    content = function(file) { write.csv(datasetInput(), file)}
  )
})
