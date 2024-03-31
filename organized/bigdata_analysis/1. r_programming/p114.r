# xlsx to csv
x=read.xlsx("p114_AQX.xlsx",sheetName="AQX")
write.table(x,file="p114_out_xlsx.csv",col.names = T,row.names = F,sep=",")
# xml to csv
x = xmlParse("p114_AQX.xml", encoding = "utf8")
xmlfiles = xmlRoot(x)
y = xmlToDataFrame(xmlfiles)
write.table(y,file="p114_out_xml.csv",col.names = T,row.names = F,sep=",")
# json to csv
x = fromJSON("p114_AQX.json",flatten = TRUE)
write.table(x,file="p114_out_json.csv",col.names = T,row.names = F,sep=",")
