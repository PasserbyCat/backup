titanic %>% 
select(Sex, Class, Freq, Age) %>% 
filter(Age=="Child") %>% 
arrange(Freq)#根據freq做排序

titanic %>% #換行只能在這邊換 因為%>%需要有input
select(Sex, Class, Freq, Age) %>% 
filter(Age=="Child") %>% 
arrange(desc(Freq))#根據freq做反向排序
