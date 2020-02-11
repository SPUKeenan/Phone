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
    return filteredIndex.size();
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
            return contactList.at(/*filteredIndex[*/index.row()).firstName;
         case 1:
              return contactList.at(/*filteredIndex[*/index.row()).lastName;
         case 2:
              return contactList.at(/*filteredIndex[*/index.row()).phoneNumber;
    }
    }
    return QVariant();
}



void MyAddressBookModel::openFile(QString filePath)
{
    Person contact;
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
        filteredIndex.push_back(i);
        std::cout << "" << std::endl;
    }
    file.close();
    emit layoutChanged();
}

void MyAddressBookModel::setFilterString(QString fStr)
{
    filteredIndex.clear();
    //Check if
    for (unsigned long long i =0; i < contactList.size(); i++){
        MyAddressBookModel::Person user = contactList.at(i);
        if(user.phoneNumber.startsWith(fStr)){
            filteredIndex.push_back(i);
            continue;
        }
        fStr = fStr.remove('-');

        if(convertNameToNumbers(user.lastName).startsWith(fStr)){
            filteredIndex.push_back(i);
            continue;
        }

        if(convertNameToNumbers(user.firstName).startsWith(fStr)){
            filteredIndex.push_back(i);
            continue;
        }
    }

    emit layoutChanged();
}


QString MyAddressBookModel::convertNameToNumbers(QString name)
{
    QString nameInNumbers;
    for(int i = 0; i < name.size(); i++){
        nameInNumbers.append(convertCharToNum(name.at(i).toLatin1()));
    }
    return nameInNumbers;
}

int MyAddressBookModel::convertCharToNum(char letter)
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


