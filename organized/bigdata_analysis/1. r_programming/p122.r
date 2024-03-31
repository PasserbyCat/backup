freqsum = titanic %>% select(Freq) %>% sum()#sum(titanic$Freq)
# add column portion
titanic %>% 
select(Sex,Age,Freq) %>% 
mutate(portion= Freq/freqsum)
new_titanic = titanic %>% mutate(portion= Freq/freqsum)#新增一列portion並且其數值為Frep/freqsum