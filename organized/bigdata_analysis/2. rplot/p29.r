matplot(iris[,1:4],#每個col獨立畫線
        type="b",
        pch=1:4)
legend("topleft",#設定圖示位置
       dimnames(iris)[[2]][1:4],#dimnames(iris)[[2]]和colname(iris)一樣
       pch=1:4,
       lty=1:4,
       col=1:4)
