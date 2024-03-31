data = read.csv("p46_ex_name_english.csv",sep=",", header=F)
colnames(data) = c("sex", "year", "name", "freq")
ans = data %>% 
      filter(year == 2012) %>% 
      select(name, freq) %>% #freq是要呈現的主要數據
      group_by(name) %>% #name是x軸
      summarise(total = sum(freq)) #作為freq的對照
barplot(ans$total, names.arg = ans$name)
