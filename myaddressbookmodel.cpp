#include "myaddressbookmodel.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
MyAddressBookModel::MyAddressBookModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int MyAddressBookModel::rowCount(const QModelIndex &parent) const
{
    return contactList.size();
}

int MyAddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyAddressBookModel::data(const QModelIndex &index, int role) const
{Person contact;

    if(role == Qt::DisplayRole)
    {

    switch(index.column())
    {
         case 0:
            return contactList[index.row()].firstName;
         case 1:
              return contactList[index.row()].lastName;
         case 2:
              return contactList[index.row()].phoneNumber;
    }
    }
    return QVariant();
}



void MyAddressBookModel::openFile(QString filePath)
{
    Person contact;
    contactList.push_back(contact);
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    contact.firstName.clear();
    contact.lastName.clear();
    contact.phoneNumber.clear();

    for (int i = 0; !in.atEnd(); i++)
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(i == 0) continue;

    for(int j = 0; j < fields.length(); j++)
    {
            std::cout << "[" << j << "]" << fields[j].toStdString();
        }
    std::cout << std::endl;
    contact.firstName = fields[0];
     contact.lastName = fields[1];
    contact.phoneNumber= fields[7];
    contactList.push_back(contact);
   std::cout << "" << std::endl;
}
    file.close();
    emit layoutChanged();
}




