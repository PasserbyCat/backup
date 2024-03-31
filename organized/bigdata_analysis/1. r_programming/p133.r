data = read.csv("p133_name_chinese_Big5.csv",sep=",", header=F)
#編碼問題
#解法1:用notepad++打開並轉檔
#解法2:使用linux指令

data = read.csv("p133_name_chinese_utf8.csv",sep=",", header=F)
colnames(data) = c("sex", "year", "name", "freq")
top10_female = data %>% 
  filter(year == "2012" & sex == "F") %>% 
  group_by(name) %>% 
  summarise(count = sum(freq)) %>% 
  arrange(desc(count)) %>% 
  head(10)
top10_male =  data %>% 
  filter(year == "2012" & sex == "M") %>% 
  group_by(name) %>% summarise(count = sum(freq)) %>% 
  arrange(desc(count)) %>% 
  head(10)
pie(top10_male$count, label = top10_male$name)
