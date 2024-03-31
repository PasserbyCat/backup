x = read.csv("p53_ex_play_tennis.csv", header = T)
HY = length(which(x$Humidity == "High" & x$PlayTennis == "Yes")) #3
HN = length(which(x$Humidity == "High" & x$PlayTennis == "No")) #4
NY = length(which(x$Humidity == "Normal" & x$PlayTennis == "Yes")) #6
NN = length(which(x$Humidity == "Normal" & x$PlayTennis == "No")) #1

Y = length(which(x$PlayTennis == "Yes")) #9
N = length(which(x$PlayTennis == "No")) #5

C = nrow(x) #14

EntropyS = -Y/C*log2(Y/C)-N/C*log2(N/C) #0.940
EntropyH = (HY+HN)/C*(-HY/(HY+HN)*log2(HY/(HY+HN))-HN/(HY+HN)*log2(HN/(HY+HN)))+
           (NY+NN)/C*(-NY/(NY+NN)*log2(NY/(NY+NN))-NN/(NY+NN)*log2(NN/(NY+NN)))
Gain = EntropyS - EntropyH
