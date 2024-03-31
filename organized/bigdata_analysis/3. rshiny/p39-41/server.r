library(shiny)
library(dplyr)
library(ggplot2)
library(RMySQL)
shinyServer(function(input, output) {
  datasetInput <- reactive({
    con =dbConnect(RMySQL::MySQL(),#哪個資料庫
                   dbname="CS528A",
                   host="localhost" ,#連到哪裡(IP位址)
                   username="CS528A",
                   password="CS528A")
    sql = paste("SELECT `Date`,
                `Station`,
                avg(`Value`) FROM `Air` WHERE `Date` >='",
                input$from,#使用者選擇的起始日期
                "' and `Date` <='",
                input$to,#使用者選擇的結束日期
                "' and `TYPE` LIKE'",
                input$type,#使用者選擇的型態
                "' group by `Date`,`Station`",
                sep="")#組合SQL指令
    res = dbSendQuery(con, sql)#正式執行指令
    raw = fetch(res, n = -1)#撈指令結果的資料(n是撈幾筆)
    raw
  })
  output$mpgPlot <- renderPlot({
    dataset = datasetInput()
    colnames(dataset)=c("Date","Station","Ave")
    ggplot(dataset, aes(Date, Ave, group=Station, colour=Station)) + geom_line()  + labs(x="Date", y=input$type, title=paste("2014 ChungLi ",input$type))  + theme(legend.position = "none")
  })
})
