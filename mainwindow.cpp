#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include <QDate>

using namespace QXlsx;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

QDate data=ui->dateEdit->date();// pobierz datę z widgetu.
int numer_dnia = data.dayOfYear();// uzyskaj numer dnia w roku na podstawie daty.


QXlsx::Document xlsx;

Document xlsxR("DATA.xlsx");
   if (xlsxR.load()) // load excel file
   {
       int row = numer_dnia+1; QString y[5];
       for(int col=1; col<5; col++){
           Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
           if ( cell != NULL )
           {
               QVariant var = cell->readValue();
               QString x=var.toString();
               y[col]=x;
               qDebug() << x;
               ui->label_1->setText(y[1]);
           }
       }
   }
}

