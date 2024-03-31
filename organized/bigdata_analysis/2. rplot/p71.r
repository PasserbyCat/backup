library(leaflet)
m = leaflet()
m = setView(m,lng = 121.51, lat = 25.05, zoom = 12)#設定起始位置，zoom為倍率
m = addTiles(m) # Add default OpenStreetMap map tiles
m
