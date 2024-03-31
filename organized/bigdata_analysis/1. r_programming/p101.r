multi<-function(x)
{
  result=1
  for (i in 1:length(x)) {
    result = result * x[i]
  }
  return(result)
}
apply(iris[,1:4],1,multi)