data = titanic %>%  
       group_by(Sex) %>%  
       summarise(Sexsum = sum(Freq, na.rm=TRUE))
barplot(data$Sexsum, names.arg=data$Sex)