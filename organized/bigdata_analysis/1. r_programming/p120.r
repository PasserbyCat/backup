filter(select(titanic, Sex, Class, Age), Age == "Child")
# then function
titanic %>% select(Sex, Class, Age) %>% filter(Age == "Child")# %>%前項的output成為後項的input
