#> install.packages("dplyr")
library("dplyr")
titanic = data.frame(Titanic)
titanic[titanic$Sex=="Male" & titanic$Age=="Adult", ]#未使用dplyr的寫法
# use filter
filter(titanic, Sex == "Male" & Age== "Adult") #AND
filter(titanic, Sex == "Male" | Age== "Adult") #OR
# find class in 1st and Crew
filter(titanic, Class %in% c('1st', 'Crew'))#可對多個元素進行搜尋