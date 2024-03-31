sink(file="p113_out.txt") #open
x=read.table("p113_load_file.csv", header=T, sep=",", 
             colClasses=c("numeric","character","Date"))
x
x
sink() #close