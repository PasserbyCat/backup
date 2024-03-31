library(jsonlite)
# From Web
url = "http://opendata.epa.gov.tw/ws/Data/AQI/?$format=json"
x = fromJSON(url,flatten = TRUE)
# From File
x = fromJSON("p110_AQX.json",flatten = TRUE)