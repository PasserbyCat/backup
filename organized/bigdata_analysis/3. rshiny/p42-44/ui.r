shinyUI(fluidPage(           
  dateInput("from", label = h3("From Date"), value = "2014-01-01"),    
  dateInput("to", label = h3("To Date"), value = "2014-12-31"), 
  radioButtons("type", "TYPE",choices = c("PM10", "PM2.5")),
  hr(),  
  fluidRow(column(12, plotOutput("mpgPlot"))) 
))
