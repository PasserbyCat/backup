library(shiny)
# Define UI for miles per gallon application
shinyUI(fluidPage(
  # Application title
  titlePanel("Miles Per Gallon"),  
  # Sidebar with controls to select the variable to plot against
  # mpg and to specify whether outliers should be included
  sidebarLayout(
    sidebarPanel(
      selectInput("variable", "Variable:",
                  c("Cylinders" = "cyl",#前面顯示給使用者
                    "Transmission" = "am",
                    "Gears" = "gear")),#後面為id給電腦讀
      checkboxInput("outliers", "Show outliers", FALSE)
    ),    
    # Show the caption and plot of the requested variable against mpg
    mainPanel(
      h3(textOutput("caption")),      
      plotOutput("mpgPlot")
    )
  )
))