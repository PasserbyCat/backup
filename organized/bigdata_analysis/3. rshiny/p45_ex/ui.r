library(shiny)
shinyUI(fluidPage(
     dateInput("from",
               label = h3("From Date"),
               format="yyyy-mm-dd",
               value = "2007-01-01"),
     dateInput("to",
               label = h3("To Date"),
               format="yyyy-mm-dd",
               value = "2007-01-31"),
     radioButtons("stno",
                  "Station",
                  choices = c("Taipei"="466920",#前面使用者,後面伺服器
                              "New Taipei"="466880",
                              "Taichung"="467490",
                              "Tainan"="467420",
                              "Kaohsiung"="467440"),
                  inline=TRUE),#變成橫向的排版
     radioButtons("type", 
                  "TYPE", 
                  choices = c("Ave Temp."= "TX01",
                              "Max Temp."= "TX04",
                              "Min Temp."= "TX06",
                              "Wind Speed"= "WD01",
                              "Ave Humidity"= "RH01",
                              "Ave Air Pressure"= "PS01"),
                  inline=TRUE),
     hr(),
     submitButton("Update View"),
     
     fluidRow(column(12,  plotOutput("mpgPlot")))
   ))
