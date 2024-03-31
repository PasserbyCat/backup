x=read.csv("p067_ex_finalscore_exercise.csv",sep=",",header=T)
apply (x[2:4],2,mean)#對該dataset(x)的哪些([2:4])column(2)取mean
apply (x[2:4],2,sd)#對該dataset(x)的哪些([2:4])column(2)取mean
apply (x[2:4],1,mean)#對該dataset(x)的哪些([2:4])row(1)取mean
apply (x[2:4],1,sd)#對該dataset(x)的哪些([2:4])row(1)取mean