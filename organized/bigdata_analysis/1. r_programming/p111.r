x=matrix(4:9,2,3)
x
cat(1:3, sep="\t", file="p111_out.txt")
cat("\n",file="p111_out.txt",append=T)#append=接在後面輸出
write( x, ncolumns=3, file="p111_out.txt",append=T)#ncolumn即一row可輸出幾個col
#不過矩陣輸出有問題