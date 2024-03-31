library(shiny)
shinyServer(function(input, output) {
  output$contents <- renderTable({
    inFile = input$file1#file header
    if (is.null(inFile))
      return(NULL)   
    read.csv(inFile$datapath, #這才是檔名(存在暫存資料夾)
             header=input$header,
             sep=input$sep,
             quote=input$quote)
  })
})
