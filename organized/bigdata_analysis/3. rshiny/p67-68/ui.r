library(shiny)
shinyUI(fluidPage(  
  titlePanel("Text & Table"),  
  sidebarLayout(
    sidebarPanel(
      textInput("caption", "Caption:", "Data Summary"),
      selectInput("dataset", "Choose a dataset:", 
      choices = c("iris", "mtcars", "USArrests")),      
      numericInput("obs", "Number of observations to view:", 10)
    ),    
    mainPanel(
      h3(textOutput("caption", container = span)),
      verbatimTextOutput("summary"),      
      DT::dataTableOutput("view")#可讓使用者對資料表做調整(說明使用DT套件)
    )
  )
))
