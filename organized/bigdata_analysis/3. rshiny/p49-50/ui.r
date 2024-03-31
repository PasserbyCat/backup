library(shiny)
shinyUI(fluidPage(  
  titlePanel("Image tag"),  
  sidebarLayout(
    sidebarPanel(
      selectInput("dataset", "Choose a image:", choices = c("R", "Java"))
    ),
    mainPanel(      
      htmlOutput("view")
    )
  )
))
