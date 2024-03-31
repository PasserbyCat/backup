library(RCurl)#抓資料的套件
url = URLencode("https://data.epa.gov.tw/api/v1/aqx_p_304?limit=1000&api_key=9be7b239-557b-4c10-9775-78cadfc555e9&format=csv")
x = readLines(url,encoding="UTF-8")#把資料從該url藉由UTF-8讀進來
col = unlist(strsplit(x[1],split=","))#把第一行(即column name)切開來,且刪除list結構變成vector
data = array(0,c(length(x)-1,length(col)))#定義一個二維array,其中row要少掉第一行的column name
for (i in 2:length(x)) {
  k = i-1#紀錄這筆資料真實的row位置
  tmp=unlist(strsplit(x[i] ,split = ","))
  for (j in 1:length(tmp)) {
    data[k,j]=tmp[j]#依序放進data
  }
}
colnames(data)=col
rownames(data)=data[,1]