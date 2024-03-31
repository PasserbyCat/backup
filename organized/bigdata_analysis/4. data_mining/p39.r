#純計算
a = -(log2(9/14)*9/14+log2(5/14)*5/14)#all entropy
b = -(log2(3/7)/7*3+log2(4/7)*4/7)#humidity_high entropy
c = -(log2(1/7)/7+log2(6/7)/7*6)#humidity_normal entropy
a - b * 7 / 14 - c * 7 / 14#humidity entropy
d = -(log2(3/6)/6*3+log2(3/6)*3/6)#wind_strong entropy
e = -(log2(2/8)/8*2+log2(6/8)/8*6)#wind_weak entropy
a - e * 8 / 14 - d * 6 / 14#wind entropy
