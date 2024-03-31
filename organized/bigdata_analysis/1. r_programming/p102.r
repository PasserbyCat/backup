fac<-function(x)
{
  if(x==1) return(1)
  return (x*fac(x-1))
}
fac(7)