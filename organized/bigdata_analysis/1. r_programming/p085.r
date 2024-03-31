score = 60
if (score >= 80){ 
  print("A")
} else if (score >= 70 && score < 80){ #注意語法,在R語言裡面else必須寫在大括號後面
  print("B")
} else if (score >= 60 && score < 70){ 
  print("C")
} else{ 
  print("D")
}