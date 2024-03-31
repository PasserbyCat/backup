new_titanic %>%  
group_by(Sex) %>%  
summarise_each(funs(sum), Freq, portion)#對Freq和portion做mean且已group_by Sex