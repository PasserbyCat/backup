taiwan_url = "https://od.cdc.gov.tw/eic/Weekly_Confirmation_Age_County_Gender_19CoV.csv"
global_url = "https://od.cdc.gov.tw/eic/covid19/covid19_global_cases_and_deaths.csv"

taiwan_data = read.csv(taiwan_url, header = T, sep = ",")
global_data = read.csv(global_url, header = T, sep = ",")

#taiwan : 縣市
#global : 國家
#皆製作圓餅圖和長條圖
#縣市使用年齡做方格圖