for (i in 1:5) {
  if (i==3) next else print(i)#next就是原本的continue
}
for (i in 1:5) { 
  if (i==3) break else print(i)
}