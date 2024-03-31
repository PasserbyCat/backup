x=read.csv("p095_ex_AirPollution.csv",header=T)
rn = unique(x[,2])#取測站
cn = unique(x[,3])#取空汙指標
out = array(0,c(length(rn),length(cn)))
rownames(out) = rn
colnames(out) = cn
for (i in 1:length(rn)) {#四個測站分別跑
  for (j in 1:length(cn)) {#六種空汙指標
    out[i,j] = mean(as.numeric(x[x[,2]==rn[i] & x[,3]==cn[j],4:27]))
    #當rn為T且cn為T時,取x[,4:27]的平均,要記得轉成numeric
  }
}
out