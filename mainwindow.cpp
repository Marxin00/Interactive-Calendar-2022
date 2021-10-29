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

    QXlsx::Document xlsx;

    Document xlsxR("Test.xlsx");
       if (xlsxR.load()) // load excel file
       {
           int row = 1; int col = 1;
           Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
           if ( cell != NULL )
           {
               QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
               qDebug() << var; // display value. it is 'Hello Qt!'.
           }
       }

QDate data =ui->dateEdit->date();
qDebug()<< "data to"<<data;
QString data_string=data.toString("dd MM yyyy");

int dni;
int miesiace;
int lata;

dni=data_string.split(" ")[0].toInt();
miesiace=data_string.split(" ")[1].toInt();
lata=data_string.split(" ")[2].toInt();
qDebug()<<"dni "<<dni;
qDebug()<<"miesiące "<<miesiace;
qDebug()<<"Lata "<<lata;
qDebug()<<"data string to "<<data_string;

int numer_dnia=dni+((13*(miesiace)-2)/5)+22+(22/4)+(20/4)-2*20;
qDebug()<<"dzień w roku "<<numer_dnia;
}

