#library(jsonlite)
library(plotly)
library(htmlwidgets)
library(leaflet)
library(dplyr)
library(httr)
set_config(config(ssl_verifypeer = 0L))
url = "https://data.epa.gov.tw/api/v1/aqx_p_432?api_key=9be7b239-557b-4c10-9775-78cadfc555e9&format=csv"
raw = read.csv(url,header=T,sep=",")

nix = which(colnames(raw)=="SiteName")#找到他的column位置
latix = which(colnames(raw)=="Latitude")
lonix = which(colnames(raw)=="Longitude")