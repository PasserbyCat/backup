library(xlsx)
x=read.xlsx("p108_PM25.xlsx",sheetName="PM25")#excel有多個工作表必須指定sheetName
#也可使用sheetIndex指定第幾個工作表(一樣從1開始)
x#本套件使用java，所以若要獨自安裝要先裝java，並設定路徑