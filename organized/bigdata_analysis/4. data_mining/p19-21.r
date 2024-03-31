hc = hcluster(USArrests,method = "euclidean", link = "complete")
hc
hc$merge #column紀錄哪兩項合併(>0表示和第幾次合併的結果合併
         #                     <0表示和第幾項合併)
         #raw共有個數-1項
hc$height#紀錄每次合併的高度
hc$label#記錄每一州