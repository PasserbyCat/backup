library(XML)
x = xmlParse("hotel.xml", encoding = "utf8")
xmlfiles = xmlRoot(x)
hotel = xmlToDataFrame(xmlfiles)

x = xmlParse("viewpoint.xml", encoding = "utf8")
xmlfiles = xmlRoot(x)
viewpoint = xmlToDataFrame(xmlfiles)