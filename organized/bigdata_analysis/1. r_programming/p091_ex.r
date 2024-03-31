n = 5#定義三角形大小
a = array(0, c(n,n))#最上row已定義
a[,1] = 1#定義最column
for (i in 2:n) {#剩下可依照巴斯卡三角形規則計算
  for (j in 2:i) {#另一半三角形已定義為0
    a[i,j] = a[i-1,j] + a[i-1,j-1]
  }
}
a