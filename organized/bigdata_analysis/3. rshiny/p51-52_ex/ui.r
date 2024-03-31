library(shiny)
shinyUI(fluidPage(  
  titlePanel("Comic Viewer"),  
  sidebarLayout(
    sidebarPanel(
      textInput("url", "Input URL:", "https://www.cartoonmad.com/5e596/1152/"),  
      numericInput("vol","Volume:",value=1),
      numericInput("n", "Number:", value=10),
      submitButton("Get Comics")
    ),    
    mainPanel(     
      htmlOutput("view")
    )
  )
))

