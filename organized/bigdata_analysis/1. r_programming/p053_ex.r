x=read.csv("p053_ex_finalscore_exercise.csv",sep=",",header=T)
fs = x[,2]*0.3 + x[,3]*0.3 + x[,4]*0.4
fs#列出最終成績
length(fs[fs<60])#找出有幾個人低於60分
which(fs<60)#找出低於60分的位置
x[which(fs<60),1]#x在那個位置的第一格是學號