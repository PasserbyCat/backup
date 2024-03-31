x = c(1, 2, 4, 3, 1, 2, 3, 4, 1)
factor(x)#分類的感覺,無法視為數字
factor(x, labels = c("A", "B", "C", "D")) # set level name
factor(x, ordered = TRUE)#order通常處理日期