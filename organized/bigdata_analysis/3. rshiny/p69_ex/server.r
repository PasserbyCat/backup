library(shiny)
library(plotly)
shinyServer(function(input,output){
  output$ui<-renderUI({
    inFile=input$file1
    if(is.null(inFile))
      return(NULL)
    data=read.table(inFile$datapath,header=T,sep=",")
    dist = unique(data[,1])
    list(
    selectInput("col","Select Dist.:",dist,selected = dist, multiple = T)
    )
  })
  output$plot<-renderPlotly({
    inFile=input$file1
    if(is.null(inFile)) return(NULL)
    if(input$col=="") return(NULL)
    data=read.table(inFile$datapath,header=T,sep=",")
    tmp = data[which(data[,1]==input$col[1]),2]
    p = plot_ly(y = tmp, type = "box", name=input$col[1])
    for (i in 2:length(input$col))
    {
      tmp = data[which(data[,1]==input$col[i]),2]
      p = p %>% add_trace(y = tmp, name=input$col[i])
    }
    p
  })
})
