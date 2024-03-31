titanic %>%  
select(Sex) %>%  
summarise_each(funs(n()))#同nrows(titanic)

titanic %>%  
select(Sex) %>%  
summarise_each(funs(n_distinct(Sex)))#同length(unique(titanic$Sex))