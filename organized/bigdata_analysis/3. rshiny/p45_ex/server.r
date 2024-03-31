 library(shiny)
 library(dplyr)
 library(ggplot2)
 library(RMySQL)
 shinyServer(function(input, output) {

   datasetInput <- reactive({
     #"2017-01-01" -> "20170101"
     fd = paste(substring(input$from,1,4),
                substring(input$from,6,7),
                substring(input$from,9,10),
                sep="")
     td = paste(substring(input$to,1,4),
                substring(input$to,6,7),
                substring(input$to,9,10),
                sep="")
     con =dbConnect(RMySQL::MySQL(),
                    dbname="CS528A",
                    host="localhost" ,
                    username="CS528A",
                    password="CS528A")
     sql = paste("SELECT `stno` ,  `yyyymmdd` ,  `",
                 input$type,#有不同欄位
                 "`  FROM `Weather` WHERE  `yyyymmdd` >='",
                 fd,
                 "' and `yyyymmdd` <='",
                 td,
                 "' and `stno` LIKE '",
                 input$stno,
                 "'",
                 sep="")
     res = dbSendQuery(con, sql)
     raw = fetch(res, n = -1)
     raw
   })
     
   output$mpgPlot <- renderPlot({
     dataset = datasetInput()
     colnames(dataset)=c("Station","Date","Value")
     ggplot(dataset, aes(Date, Value, group=Station, colour=Station)) + geom_line() + labs(x="Date", y=input$type, title="Weather") + theme(legend.position = "none")
   }) 
})
  