library(shiny)
source("global.r")
shinyUI(fluidPage(
  titlePanel("P14"),
  sidebarLayout(
    sidebarPanel(
      selectInput("dataset", "Choose a dataset:",
                  choices = c("Hotel", "Viewpoint")),
      numericInput("obs", "Number of observations to view:, 10")
    ),
    mainPanel(
      h3(textOutput("Caption", container = span)),
      tableOutput("view")
    )
  )
))