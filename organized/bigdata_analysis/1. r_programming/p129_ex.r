library(dplyr)
x = read.csv("p129_ex_311.csv", header = T, sep = ",")
y = data.frame(x)
data1 = y %>% group_by(Complaint.Type) %>% count(Complaint.Type)
data1
data2 = y %>% group_by(Borough) %>% filter(Complaint.Type == "Blocked Driveway") %>% count(Borough)
data2
