library(leaflet)
m = leaflet()
m = addTiles(m) # Add default OpenStreetMap map tiles
m = addMarkers(m, lng=121.51, lat=25.05, popup="Taipei Station")#標記點(popup為說明文字)
#(不用設定圖片位置，自動用marker作為圖片位置)
m