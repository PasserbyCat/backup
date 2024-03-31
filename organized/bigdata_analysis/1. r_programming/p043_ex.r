x=read.csv("p043_ex_score_exercise.csv",sep=",",header=T)
score = x[,2]
min(score)
max(score)
mean(score)#平均值
median(score)#中位數
var(score)#變異數
sd(score)#標準差