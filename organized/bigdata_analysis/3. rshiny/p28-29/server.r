library(shiny)
# Define server logic required for iris dataset
shinyServer(function(input, output) {
  # Return the requested dataset
  datasetInput <- reactive({
    data=switch(input$dataset,
                "Sepal.Length" = iris$Sepal.Length, "Sepal.Width" = iris$Sepal.Width,
                "Petal.Length" = iris$Petal.Length, "Petal.Width" = iris$Petal.Width)
                data[1:input$n]
  })
  output$plot <- renderPlot({
    hist(datasetInput())
  })
  # Generate a summary of the dataset
  output$summary <- renderPrint({
    summary(datasetInput())
  })
  # Show the first "n" observations
  output$table <- renderTable({
    dataset=datasetInput()
    data.frame(x=datasetInput())
  })
})
