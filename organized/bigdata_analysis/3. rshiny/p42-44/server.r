library(shiny)
library(dplyr)
library(ggplot2)
library(RMySQL)
shinyServer(function(input, output) {
  datasetInput <- reactive({
    con =dbConnect(RMySQL::MySQL(),dbname="CS528A",host="localhost" ,username="CS528A",password="CS528A")
    sql = paste("SELECT `Date`,`Station`,avg(`Value`) FROM `Air` WHERE  `Date` >='",input$from,"' and `Date` <='",input$to,"' and `TYPE` LIKE '",input$type,"' group by `Date`, `Station`",sep="")
    res = dbSendQuery(con, sql)
    raw = fetch(res, n = -1)
    raw
  })
  output$mpgPlot <- renderPlot({
    dataset = datasetInput()
    colnames(dataset)=c("Date","Station","Ave")
    ggplot(dataset, aes(Date, Ave, group=Station, colour=Station)) + geom_line() + labs(x="Date", y=input$type, title=paste("2014 ChungLi ",input$type)) + theme(legend.position = "none")
  })
})
