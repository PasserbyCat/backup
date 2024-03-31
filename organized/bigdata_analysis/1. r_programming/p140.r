#R CMD SHLIB p140_test3.c #generate p140_test3.so p140_test3.o
dyn.load("p140_test3.so")
result<-.C("count_len",str="Hello" ,len=as.integer(0))
result$len
result<-.C("count_len",str="World!!" ,len=as.integer(0))
result$len
result<-.C("count_len",str="World!!" )#不能不傳參數
result$len
