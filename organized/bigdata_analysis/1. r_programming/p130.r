data = read.csv("p130_name_english.csv",sep=",", header=F)
colnames(data) = c("sex", "year", "name", "freq")
top10_female = data %>% 
  filter(year == "2012" & sex == "F") %>% #篩選
  group_by(name) %>% #用什麼做分類
  summarise(count = sum(freq)) %>% 
  arrange(desc(count)) %>% #依照count做desc(大到小)排序
  head(10)#顯示前10筆
top10_male =  data %>% 
  filter(year == "2012" & sex == "M") %>% 
  group_by(name) %>% summarise(count = sum(freq)) %>% 
  arrange(desc(count)) %>% 
  head(10)
pie(top10_male$count, label = top10_male$name)#放:數字,標題
