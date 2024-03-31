library(shiny)
# Define UI for application that draws a histogram
shinyUI(fluidPage( 
  # Application title
  titlePanel("Hello Shiny!"), # page title
  # Sidebar with a slider input for the number of bins
  sidebarLayout(
    sidebarPanel(
      sliderInput("bins", # input ID(給電腦看)
                  "Number of bins:", #label(給人看)
                  min = 1,
                  max = 50,
                  value = 30) #default value
    ),  
    # Show a plot of the generated distribution
    mainPanel(
      plotOutput("distPlot") #output ID(給電腦看)
    )
  )
))