library(leaflet)
AQX =read.csv("p76_ex_MRT.csv",header=T,sep=",")

UserIcon <- makeIcon(iconUrl = "p76_ex_MRT.png",
                     iconWidth = 30, iconHeight = 30)#自製圖標

m = leaflet(data = AQX ) %>% 
  addTiles() %>%
  addMarkers(~lon, ~lat, icon = 
               UserIcon,popup=~id)
m
