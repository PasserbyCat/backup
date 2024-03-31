remove_outliers <- function(x) {
  qnt = quantile(x, probs=c(.25, .75))
  H = 1.5 * IQR(x)
  y = x
  y[x < (qnt[1] - H)] = NA
  y[x > (qnt[2] + H)] = NA#把上下的極端直接設為NA(直接移除)
  y
}

x=iris[,2]
y = remove_outliers(x)

boxplot(x)
boxplot(y)