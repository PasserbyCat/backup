library(shiny)
library(plotly)
source("global.r")

shinyUI(fluidPage(
  titlePanel("s1081447_HW2"),
  sidebarLayout(
    sidebarPanel(
      selectInput("place", 
                  "Choose a dataset:",
                  choices = c("Taiwan", "Global")), 
      radioButtons("chart","Chart:",
                   choices = c("pie chart",
                               "bar chart")),
      submitButton("submit")
    ),
    mainPanel(
      plotlyOutput("plot")
    )
  )
))
