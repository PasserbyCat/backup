titanic %>%  
group_by(Sex) %>%  #對性別做切割
summarise(Sexsum = sum(Freq, na.rm=TRUE))#對分割出來的地方給欄位名稱和行為