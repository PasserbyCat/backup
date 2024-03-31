library(leaflet)
library(dplyr)
library(httr)
set_config(config(ssl_verifypeer = 0L))
# AQ Data
url = "https://data.epa.gov.tw/api/v1/aqx_p_432?api_key=9be7b239-557b-4c10-9775-78cadfc555e9&format=csv"
AQX =read.csv(url,header=T,sep=",")
aq = AQX %>% select(SiteName,PM2.5,Longitude,Latitude)
aq$PM2.5 = as.numeric(aq$PM2.5)
aq$Longitude = as.numeric(aq$Longitude)
aq$Latitude = as.numeric(aq$Latitude)
# Set Icon
UserIcon <- icons(
  iconUrl = ifelse(aq$PM2.5 < 30,
                   "good.png",
                   "bad.png"
  ),#製作圖標(依條件分類)
  iconWidth = 30, iconHeight = 30
)
m = leaflet(data = aq ) %>% 
    addTiles() %>%
    addMarkers(~Longitude, ~Latitude, icon = 
               UserIcon,popup=paste(aq$SiteName,aq$PM2.5,sep=":"))
m
