#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myaddressbookmodel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QString on_button1_clicked();

    QString on_button2_clicked();

    QString on_button3_clicked();

    QString on_button4_clicked();

    QString on_button5_clicked();

    QString on_button6_clicked();

    QString on_button7_clicked();

    QString on_button8_clicked();

    QString on_button9_clicked();

    QString on_starbutton_clicked();

    QString on_button0_clicked();

    QString on_poundbutton_clicked();

    QString on_Backspace_clicked();

    void on_callbutton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_actionImport_Contacts_List_triggered();

    void on_actionExit_triggered();

private:
      QString phoneNumber;
private:
    Ui::MainWindow *ui;
    MyAddressBookModel *myModel;
};
#endif // MAINWINDOW_H
