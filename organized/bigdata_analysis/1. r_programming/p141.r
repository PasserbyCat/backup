dyn.load("p140_test3.so")
test<-function(s){#使用function反覆呼叫
  result<-.C("count_len",str=s ,len=as.integer(0))
  return (result$len)
}
test("Hello")
test("World!!")
