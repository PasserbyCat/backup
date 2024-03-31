filelist = list.files(path = "p115_ex_AQData")#把AQData資料夾內的檔名存起來
for (i in 1:length(filelist))
{
  fn = paste0("p115_ex_AQData/", filelist[i])#實際上的路徑
  #nchar取字串長度
  #從string取1-nchar-5作為子字串
  out = substring(filelist[i], 1, nchar(filelist[i]) - 5)
  out = paste0("p115_ex_AQData/", out, ".csv")
  # xlsx to csv
  x=read.xlsx(fn,sheetName="data")
  write.table(x,file=out,col.names = T,row.names = F,sep=",")
}
