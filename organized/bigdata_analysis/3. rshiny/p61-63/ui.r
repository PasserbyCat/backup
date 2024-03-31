library(shiny)
library(plotly)
shinyUI(fluidPage(
  titlePanel("Bar Plot"),
  sidebarLayout(
    sidebarPanel(
    fileInput('file1','Upload File',accept=c('text/csv',
              'text/comma-separated-values,text/plain','.csv',
              '.txt','text/txt','text/plain')),
    uiOutput("ui")#動態產生(selectInput)
  ),
  mainPanel(
    plotlyOutput("plot")
  )
  )
))
