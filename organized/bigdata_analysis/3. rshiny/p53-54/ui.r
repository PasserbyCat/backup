library(shiny)
shinyUI(fluidPage(
  titlePanel("Uploading Files"),
  sidebarLayout(
    sidebarPanel(
      fileInput('file1', 
                'Choose CSV File', 
                accept=c('text/csv',
                         'text/comma-separated-values,
                         text/plain',
                         '.csv')),#支援甚麼樣的格式
      tags$hr(),#排版好看的分隔線
      checkboxInput('header', 'Header', TRUE),
      radioButtons('sep',
                   'Separator',
                   c(Comma=',',
                     Semicolon=';',
                     Tab='\t'), ','),
      radioButtons('quote',
                   'Quote',
                   c(None='',
                     'Double Quote'='"',
                     'Single Quote'="'"),'"')
    ),
    mainPanel(
      tableOutput('contents')
    )
  )
))
