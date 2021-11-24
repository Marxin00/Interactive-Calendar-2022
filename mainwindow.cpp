#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <stdio.h>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include <QDate>
#include <QFile>

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

QPixmap now_img(":/img/now.jpg");
QPixmap pelnia_img(":/img/pelnia.jpg");
QPixmap pierwsza_kwarta_img(":/img/pierwsza_kwadra.jpg");
QPixmap ostatnia_kwarta_img(":/img/ostatnia_kwarta.jpg");

QDate data=ui->dateEdit->date();// pobierz datę z widgetu.

int jd = data.toJulianDay();// uzyskaj numer dnia w roku na podstawie daty.

float faza=((jd/29.5305902778)-0.3033);
int x= floor(faza);
float y=faza-x;

if(0<=y and y<0.25)
{
   ui->label_1->setText("Nów");
   ui->lable_pic->setPixmap(now_img);
}
if(0.25<=y and y<0.50)
{
    ui->label_1->setText("pierwsza kwarta");
    ui->lable_pic->setPixmap(pierwsza_kwarta_img);
}
if(0.50<=y and y<0.75)
{
    ui->label_1->setText("pełnia");
    ui->lable_pic->setPixmap(pelnia_img);

}
if(0.75<=y)
{
    ui->label_1->setText("ostatnia kwarta");
    ui->lable_pic->setPixmap(ostatnia_kwarta_img);
}
 qDebug()<<"y"<<y;

 QString dzien=("C:/Users/marci/Interactive-Calendar-2022/notatki/plik_nr")+QString::number(data.dayOfYear())+(".txt");

 QFile plik(dzien);
 if(!plik.open(QIODevice::OpenModeFlag::ReadWrite)){
     qDebug()<<"błąd";
 }
 plik.write("test działania");
 plik.close();

/*
QXlsx::Document xlsx;

Document xlsxR(":/DATA.xlsx");
   if (xlsxR.load()) // load excel file
   {
       int row = numer_dnia+1; QString y[5];
       for(int col=1; col<5; col++){
           Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
           if ( cell != NULL )
           {
               QVariant var = cell->readValue();
                y[col] =var.toString();
           }
       }

       ui->label_1->setText(y[1]);
       ui->label_2->setText(y[2]);
       ui->label_3->setText(y[3]);

       QPixmap now_img(":/img/now.jpg");
       QPixmap pelnia_img(":/img/pelnia.jpg");
       QPixmap pierwsza_kwarta_img(":/img/pierwsza_kwadra.jpg");
       QPixmap ostatnia_kwarta_img(":/img/ostatnia_kwarta.jpg");

       QString now="Nów";
       QString pelnia="Pełnia";
       QString pierwsza="Pierwsza kwarta";
       QString ostatnia="Ostatnia kwarta";

      if(y[1]==now){
          ui->lable_pic->setPixmap(now_img);
      }
      if(y[1]==pelnia){
          ui->lable_pic->setPixmap(pelnia_img);

      }
      if(y[1]==pierwsza){
          ui->lable_pic->setPixmap(pierwsza_kwarta_img);

      }
      if(y[1]==ostatnia){
          ui->lable_pic->setPixmap(ostatnia_kwarta_img);

      }
   }*/
}

