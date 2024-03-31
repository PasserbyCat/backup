library(shiny)
library(plotly)
shinyServer(function(input,output){
  output$ui<-renderUI({
    inFile=input$file1
    if(is.null(inFile))
      return(NULL)
    data=read.table(inFile$datapath,header=T,sep=",")
    cname=colnames(data)#取colname(data的)
    list(
      selectInput("col","Select Column:",cname[-1])
    )
  })
  output$plot<-renderPlotly({
    inFile=input$file1
    if(is.null(inFile)) return(NULL)
    if(input$col=="") return(NULL)#使用者沒選擇時
    data=read.table(inFile$datapath,header=T,sep=",")
    ix = which(colnames(data)==input$col)#找到第幾個column
    p = plot_ly( x = data[,1], 
                 y = data[,ix], 
                 name = input$col,
                 type = "bar")
    p
  })
})
