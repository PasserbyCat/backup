x = read.csv("p29_ex_pm25.csv", sep = ",", header = T)
y = x[,5:28]
rownames(y) = x[,2]

a = kmeans(y,3)
a$cluster
sort(a$cluster)
