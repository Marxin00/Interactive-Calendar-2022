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
                y[col] =var.toString();

           }
       }

       ui->label_1->setText(y[1]);
       ui->label_2->setText(y[2]);
       ui->label_3->setText(y[3]);
       ui->label_4->setText(y[4]);

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
   }
}

