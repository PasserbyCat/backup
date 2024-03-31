library(leaflet)
UserIcon <- makeIcon(iconUrl = "p74_TRA01.png",#請用透明背景
                     iconWidth = 30, iconHeight = 30)#自製圖標
m = leaflet()
m = addTiles(m)
m = addMarkers(m, lng=121.51, lat=25.05, 
               popup="Taipei Station",icon=UserIcon)
m