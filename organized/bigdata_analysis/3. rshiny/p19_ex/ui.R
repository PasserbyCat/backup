library(shiny)
source("global.R")
shinyUI(fluidPage(  
  titlePanel("P19_ex"), 
  titlePanel("Air Quality"),  
  sidebarLayout(
    sidebarPanel(
      selectInput("type", "Choose Type:", 
                  choices = c("PM2.5", "PM10"))
    ),    
    mainPanel(
      h3(textOutput("caption", container = span)),
      plotOutput("mpgPlot")
    )
  )
))
