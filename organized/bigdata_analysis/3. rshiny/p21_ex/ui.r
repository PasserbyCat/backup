library(shiny)

shinyUI(fluidPage(  
  titlePanel("P21_ex"),  
  sidebarLayout(
    sidebarPanel(
      selectInput("dist", "Choose Location:", 
                  choices =unique(x[,'locationName'])),      
      selectInput("type", "Choose Types:", 
                  choices =c("Max Temp","Min Temp"))
      
    ),    
    mainPanel(
      textOutput("caption"),
      tableOutput("table"),
      plotOutput("distPlot")
    )
  )
))
