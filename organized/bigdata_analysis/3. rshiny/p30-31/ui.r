library(shiny)
# Define UI for dataset viewer application
shinyUI(fluidPage(  
  # Application title
  titlePanel("submitButton"),  
  # submitButton defers the rendering of output until the user explicitly clicks the button   
  #(rather than doing it immediately when inputs change) 
  sidebarLayout(
    sidebarPanel(
      selectInput("dataset", "Choose a dataset:", choices = c("iris", "mtcars", "USArrests")),      
      numericInput("obs", "Number of observations to view:", 10),
      submitButton("Update View")#可防止server崩潰(只會在提交後才運算)
    ),    
    mainPanel(
      verbatimTextOutput("summary"),      
      tableOutput("view")
    )
  )
))
