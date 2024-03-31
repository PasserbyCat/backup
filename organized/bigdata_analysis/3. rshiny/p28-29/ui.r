library(shiny)
# Define UI for iris dataset
shinyUI(fluidPage(
  # Application title
  titlePanel("Tabsets"), 
  sidebarLayout(
    sidebarPanel(
      radioButtons("dataset", "Column", choices = c("Sepal.Length", "Sepal.Width", "Petal.Length", "Petal.Width")),
    # The br() element to introduce extra vertical spacing     
      br(),
      sliderInput("n", "Number of observations:", value = 10, min = 1, max = 150)
    ),   
    # Show a tabset that includes a plot, summary, and table view of the generated distribution
    mainPanel(
      tabsetPanel(type = "tabs", 
                  tabPanel("Plot", plotOutput("plot")), #小分頁
                  tabPanel("Summary", verbatimTextOutput("summary")), 
                  tabPanel("Table", tableOutput("table"))
      )
    )
  )
))
