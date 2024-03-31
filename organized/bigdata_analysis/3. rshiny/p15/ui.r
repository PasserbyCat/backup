library(shiny)
source("global.r")
shinyUI(fluidPage(
  titlePanel("P15"),
  sidebarLayout(
    sidebarPanel(
      selectInput("dist", "Choose a dataset:",
                  choices = unique(x[,1])),#取地區
      numericInput("bins", "Number of bins:", min = 1, max = 50, value = 30)
    ),
    mainPanel(
      verbatimTextOutput("summary"),
      plotOutput("distPlot")
    )
  )
))