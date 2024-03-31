titanic %>% 
group_by(Age, Sex) %>% #兩種屬性互相對照，產生Age*Sex種組合
summarise(fs = sum(Freq)) %>% 
arrange(desc(fs))
