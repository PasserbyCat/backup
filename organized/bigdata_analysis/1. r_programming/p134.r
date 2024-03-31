dF = data %>% 
  group_by(sex, year, name) %>%
  summarise(count = sum(freq)) %>% 
  group_by(sex, year) %>% 
  mutate(prop = round(count * 100/sum(count), 3)) %>% 
  filter(name %in% top10_female$name) 

dM = data %>% 
  group_by(sex, year, name) %>%
  summarise(count = sum(freq)) %>% 
  group_by(sex, year) %>%
  mutate(prop = round(count * 100/sum(count), 3)) %>% 
  filter(name %in% top10_male$name)

#> install.packages("ggplot2")
library(ggplot2)
ggplot(data = dF, aes(x=year, y=count, group=name)) + geom_path(aes(colour=name)) + + geom_point(aes(colour=name))#指令有誤,等下張投影片再看
ggplot(data = dM, aes(x=year, y=count, group=name)) + geom_path(aes(colour=name)) + + geom_point(aes(colour=name))#指令有誤,等下張投影片再看
