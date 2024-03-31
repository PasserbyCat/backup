titanic = data.frame(Titanic)
titanic[, c("Sex","Age")]
# select column "Sex" and "Age"
select(titanic, Sex, Age)
# select column from "Sex" to "Survived"
select(titanic, Sex:Survived)
# column name contains "S"
select(titanic, contains("S"))
