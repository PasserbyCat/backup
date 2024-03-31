library(shiny)
shinyUI(fluidPage(  
  titlePanel("Downloading Data"),  
  sidebarLayout(
    sidebarPanel(
      selectInput("dataset", 
                  "Choose a dataset:", 
                  choices = c("iris", "mtcars", "USArrests")),
      downloadButton('downloadData', 'Download')#按此鍵下載
    ),    
    mainPanel(
      tableOutput("view")
    )
  )
))
