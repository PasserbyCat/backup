library(shiny)
library(XML)
library(RCurl)
shinyServer(function(input, output) {
  output$view <- renderUI({
    data = list()
    i= 1
    vol = ""
    # https://www.cartoonmad.com/5e596/1152/ -> 這是input$vol
    #001/001.jpg
    if (input$vol <10) vol = paste("00",input$vol,sep="")#對網址做補零
    else if (input$vol >=10 && input$vol <100) vol = paste("0",input$vol,sep="")
    else vol = as.character(input$vol)
    url = paste(input$url,"/",vol,"/",sep="")#此處完成到下面網址
    # https://www.cartoonmad.com/5e596/1152/001/
    for (p in 1:as.numeric(input$n)) {
      if (p<10) img = paste(url,"00",p,".jpg",sep="")#同樣對網址補零
      else if (p >= 10 && p < 100) img = paste(url,"0",p,".jpg",sep="")
      else img = paste(url,p,".jpg",sep="")#此處完成到下面網址
      # https://www.cartoonmad.com/5e596/1152/001/001.jpg
      data[[i]]=tags$img(src=img,width=500,heigth=500)
      i=i+1
      data[[i]]=br()#使用雙括號將資料丟進list
      i=i+1
    }
    data
  })
})
