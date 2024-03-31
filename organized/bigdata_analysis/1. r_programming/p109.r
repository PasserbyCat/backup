#沒有很懂每一行在做甚麼
library(XML)
# From Web
url = "http://140.138.77.210/course/AQX.xml"
x = xmlParse(url, encoding = "utf8")#被讀進來的資料,包括<>這類的title
xmlfiles = xmlRoot(x)
y = xmlToDataFrame(xmlfiles)#將xml轉成dataframe
# From File
x = xmlParse("p109_AQX.xml", encoding = "utf8")
xmlfiles = xmlRoot(x)
y = xmlToDataFrame(xmlfiles)