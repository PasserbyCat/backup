x = read.csv("p58_ex_play_tennis.csv", header = T)
HY = length(which(x$Humidity == "High" & x$PlayTennis == "Yes")) #3
HN = length(which(x$Humidity == "High" & x$PlayTennis == "No")) #4
NY = length(which(x$Humidity == "Normal" & x$PlayTennis == "Yes")) #6
NN = length(which(x$Humidity == "Normal" & x$PlayTennis == "No")) #1

Y = length(which(x$PlayTennis == "Yes")) #9
N = length(which(x$PlayTennis == "No")) #5

C = nrow(x) #14

GiniS1 = 1 - (HY/(HY+HN))^2 - (HN/(HY+HN))^2 #1 - (3/7)^2 - (4/7)^2
GiniS2 = 1 - (NY/(NY+NN))^2 - (NN/(NY+NN))^2 #1 - (6/7)^2 - (1/7)^2
Gini = (HY+HN)/C*GiniS1 + (NY+NN)/C*GiniS2
