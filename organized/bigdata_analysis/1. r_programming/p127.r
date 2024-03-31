# find top 2 of each class
titanic %>%
group_by(Class) %>% 
select(Sex,Age,Freq) %>% 
top_n(2)#顯示前面幾筆資料