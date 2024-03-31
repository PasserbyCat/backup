library(shiny)
library(leaflet)
source("global.r")
shinyUI(fluidPage(
  titlePanel("P23-24"),
  sidebarLayout(
    sidebarPanel(
      selectInput("Type", "Choose type of air pollutant:", 
                  choices = c("AQI","SO2", "CO", "O3","PM10","PM2.5","NO2"))      
    ),    
    mainPanel(
      h3(textOutput("time", container = span)),
      leafletOutput("mpgPlot")
    )
  )
))