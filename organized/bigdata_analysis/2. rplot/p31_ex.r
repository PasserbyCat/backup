cn = colnames(iris)
for(i in c(1:4)) {
  for(j in c(1:4)) {
    mt = paste0(cn[i], "*", cn[j])
    fn = paste0("p31_ex_png/", mt, ".png")
    png(fn,width = 10,height = 10,res = 300,units="in")
    x = iris[,i]
    y = iris[,j]
    plot(x, y,
         main = mt,
         xlab = cn[i],
         ylab = cn[j],
         xlim = c(min(x, y),max(x, y)), 
         ylim = c(min(x, y),max(x, y)))
    fit = lm(y~x)
    abline(fit, col = 2)
    abline(0, 1, col = 3) # diagonal line
    legend("topleft",
           c("Diagonal line",
             "Fitted line",
             paste("R-square =", round(summary(fit)$r.squared,4)),
             paste("y = ", round(fit$coefficients[2], 2)," x + (", round(fit$coefficients[1], 2), ")", sep="")),
           lty = c(1, 1, 0, 0),
           col = c(2, 3, "white", "white"),
           bg = "white")
    dev.off()
  }
}
