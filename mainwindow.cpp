#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QMessageBox>

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


QString MainWindow::on_button1_clicked()
{
   if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
   {

       ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "1");
   }
   else
   {
        phoneNumber+= "1";
          ui->display->setText(phoneNumber);
   }
   return phoneNumber;
}



QString MainWindow::on_button2_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {

        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "2");
    }
    else
    {
         phoneNumber+= "2";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button3_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "3");
    }
    else
    {
         phoneNumber+= "3";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button4_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {

        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "4");
    }
    else
    {
         phoneNumber+= "4";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button5_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {

        ui->display->setText(phoneNumber += "-");
          ui->display->setText(phoneNumber += "5");
    }
    else
    {
         phoneNumber+= "5";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button6_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "6");
    }
    else
    {
         phoneNumber+= "6";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button7_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {

        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "7");
    }
    else
    {
         phoneNumber+= "7";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button8_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "8");
    }
    else
    {
         phoneNumber+= "8";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button9_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
        ui->display->setText(phoneNumber += "-");
        ui->display->setText(phoneNumber += "9");
   }
    else
    {
         phoneNumber+= "9";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_starbutton_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
        ui->display->setText(phoneNumber += "-");
        ui->display->setText(phoneNumber += "*");
    }
    else
    {
         phoneNumber+= "*";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_button0_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {

        ui->display->setText(phoneNumber += "-");
         ui->display->setText(phoneNumber += "0");
    }
    else
    {
         phoneNumber+= "0";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_poundbutton_clicked()
{
    if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
         ui->display->setText(phoneNumber += "-");
          ui->display->setText(phoneNumber += "#");
    }
    else
    {
         phoneNumber+= "#";
           ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

QString MainWindow::on_Backspace_clicked()
{
    if(phoneNumber.size() > 0)
    {
        phoneNumber.remove(phoneNumber.size()-1, 1);
        ui->display->setText(phoneNumber);
    }
    return phoneNumber;
}

void MainWindow::on_callbutton_clicked()
{
    QMessageBox text;
    text.setText("Calling: " + phoneNumber);
    text.exec();
    phoneNumber = nullptr;
    ui->display->setText(phoneNumber);


}


