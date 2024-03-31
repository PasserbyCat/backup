x = sample(1:6, 150, replace=T, prob=c(0.1, 0.1, 0.2, 0.2, 0.2, 0.2))
A = table(x)
B = cumsum(A)
C = A/150*100
D = B/150*100
out = cbind(A, B, C, D)
colnames(out) = c("frequency", "cumulative frequency", "relative frequency", "cumulative relative frequency")
write.table(out, file = "p49_ex_out.csv", col.names = T, row.names = F)
barplot(A, names.arg=c(1:6))
barplot(A, names.arg=c(1:6), hori = T)
pie(A)#標籤即為column name
E = c('A', 'B', 'C', 'D', 'E', 'F')
pie(A, labels = E)#標籤即為column name
