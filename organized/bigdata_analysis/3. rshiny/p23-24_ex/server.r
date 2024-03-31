library(dplyr)
library(httr)
library(leaflet)
source("global.r")#這步很重要
#太過聰明的瀏覽器會記錄第一次開啟時的結果
#導致發生程式碼修改頁面卻沒有修改的情況
shinyServer(function(input, output) {
  output$time <- renderText({
    raw[1,'PublishTime']
  })
  
  output$mpgPlot <- renderLeaflet({#記得要使用leaflet
    tix = which(colnames(raw)==as.character(input$Type))#找到他的column位置
    aq = raw[,c(nix,tix,lonix,latix)]
    colnames(aq) = c("SiteName","Value","Longitude","Latitude")
    aq$Value = as.numeric(aq$Value)
    aq$Longitude = as.numeric(aq$Longitude)
    aq$Latitude = as.numeric(aq$Latitude)
    m = leaflet(data = aq ) %>%
      setView(lng = 121.51, lat = 25.05, zoom = 8) %>%
      addTiles() %>%
      addMarkers(~Longitude, ~Latitude,popup=paste(aq$SiteName,aq$Value,sep=":"))
    m
  })
})
