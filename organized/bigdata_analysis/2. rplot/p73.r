library(leaflet)
m = leaflet()
m = addTiles(m)
m = addPopups(m, lng=121.51, lat=25.05, popup="Taipei Station")#只有說明
m#新增註解