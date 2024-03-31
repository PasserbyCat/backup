x=read.csv("p50_ex_Taiwan.csv",sep=",")

png("p50_ex_out/barplot_resident.png",width = 10,height = 5,res = 300,units="in")
barplot(x[,2], names.arg = x[,1])
dev.off()

png("p50_ex_out/barplot_area.png",width = 10,height = 5,res = 300,units="in")
barplot(x[,3], names.arg = x[,1])
dev.off()

png("p50_ex_out/pie_resident.png",width = 10,height = 5,res = 300,units="in")
pie(x[,2], labels = x[,1])
dev.off()

png("p50_ex_out/pie_area.png",width = 10,height = 5,res = 300,units="in")
pie(x[,3], labels = x[,1])
dev.off()
