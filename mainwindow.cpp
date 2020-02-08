#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myaddressbookmodel.h"
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myModel(new MyAddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView ->setModel(myModel);
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
    if(phoneNumber.size() <= 12)
    text.setText("Calling: " + phoneNumber);
    else
        text.setText("Invalid Phone Number!");
    text.exec();
    phoneNumber = nullptr;
    ui->display->setText(phoneNumber);


}

std::vector<MyAddressBookModel::Person> MainWindow::lookPersonUp(QString phoneNumber)
{
    std::vector<MyAddressBookModel::Person> returnList;
    //auto iteratorPerson = std::find(myModel->contactList.begin()->phoneNumber, myModel->contactList.end()->phoneNumber, searchQuery);
    //auto iteratorFirstName = std::find(convertNameToNumbers(myModel->contactList.begin()->firstName), convertNameToNumbers(myModel->contactList.end()->firstName), searchQuery);
    //auto iteratorLastName = std::find(convertNameToNumbers(myModel->contactList.begin()->lastName), convertNameToNumbers(myModel->contactList.end()->lastName), searchQuery);



    /*if(iteratorPerson != myModel->contactList.end()){
        return *iteratorPerson;
    }*/

    for(unsigned long long i = 0; i < myModel->contactList.size(); i++){
        MyAddressBookModel::Person user = myModel->contactList.at(i);
        if(user.phoneNumber.contains(phoneNumber)){
            returnList.push_back(user);
            continue;
        }

        if(convertNameToNumbers(user.lastName).contains(phoneNumber)){
            returnList.push_back(user);
            continue;
        }

        if(convertNameToNumbers(user.firstName).contains(phoneNumber)){
            returnList.push_back(user);
            continue;
        }
    }

    return returnList;
}

QString MainWindow::convertNameToNumbers(QString name)
{
    QString nameInNumbers;
    for(int i = 0; i < name.size(); i++){
        nameInNumbers.append(convertCharToNum(name.at(i).toLatin1()));
    }
    return nameInNumbers;
}

int MainWindow::convertCharToNum(char letter)
{
    switch (tolower(letter)){
    case 'a':
        return 2;
    case 'b':
        return 2;
    case 'c':
        return 2;
    case 'd':
        return 3;
    case 'e':
        return 3;
    case 'f':
        return 3;
    case 'g':
        return 4;
    case 'h':
        return 4;
    case 'i':
        return 4;
    case 'j':
        return 5;
    case 'k':
        return 5;
    case 'l':
        return 5;
    case 'm':
        return 6;
    case 'n':
        return 6;
    case 'o':
        return 6;
    case 'p':
        return 7;
    case 'q':
        return 7;
    case 'r':
        return 7;
    case 's':
        return 7;
    case 't':
        return 8;
    case 'u':
        return 8;
    case 'v':
        return 8;
    case 'w':
        return 9;
    case 'x':
        return 9;
    case 'y':
        return 9;
    case 'z':
        return 9;
    default:
        return 0;
    }
}

void MainWindow::on_OpenAddressBook_clicked()
{
    QString fileName = QFileDialog::getOpenFileName
            (this, tr("Open Adress Book"), "", tr("Adress Book (*.csv);; Files(*)"));
    std::cout << fileName.toStdString() << std::endl;
    myModel->openFile(fileName);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->display -> setText(myModel -> contactList[index.row()].phoneNumber);
    phoneNumber = myModel->contactList[index.row()].phoneNumber;

}
