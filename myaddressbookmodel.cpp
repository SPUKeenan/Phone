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
            return contactList.at(filteredIndex[index.row()]).firstName;
         case 1:
              return contactList.at(filteredIndex[index.row()]).lastName;
         case 2:
              return contactList.at(filteredIndex[index.row()]).phoneNumber;
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
        contact.phoneNumber = fields[7];
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

    for (unsigned long long i =0; i < contactList.size(); i++){
        MyAddressBookModel::Person user = contactList.at(i);
        QString numWithoutDash = fStr;
        numWithoutDash.replace('-', "");

        if(user.phoneNumber.startsWith(fStr)){
            filteredIndex.push_back(i);
            continue;
        }  if(convertNameToNumbers(user.firstName).startsWith(numWithoutDash)){
            filteredIndex.push_back(i);
            continue;
        }  if(convertNameToNumbers(user.lastName).startsWith(numWithoutDash)){
            filteredIndex.push_back(i);
            continue;
        }
    }
    emit layoutChanged();

}


QString MyAddressBookModel::convertNameToNumbers(QString name)
{
    QString nameInNumbers = "";
    for(int i = 0; i < name.size(); i++){
        nameInNumbers.append(convertCharToNum(name.at(i).toLatin1()));
    }
    return nameInNumbers;

}

QString MyAddressBookModel::convertCharToNum(char letter)
{
    letter = tolower(letter);
    if(letter == QChar( 'a'))
        return "2";
    if(letter == QChar( 'b'))
        return "2";
    if(letter == QChar( 'c'))
        return "2";
    if(letter == QChar( 'd'))
        return "3";
    if(letter == QChar( 'e'))
        return "3";
    if(letter == QChar( 'f'))
        return "3";
    if(letter == QChar( 'g'))
        return "4";
    if(letter == QChar( 'h'))
        return "4";
    if(letter == QChar( 'i'))
        return "4";
    if(letter == QChar( 'j'))
        return "5";
    if(letter == QChar( 'k'))
        return "5";
    if(letter == QChar( 'l'))
        return "5";
    if(letter == QChar( 'm'))
        return "6";
    if(letter == QChar( 'n'))
        return "6";
    if(letter == QChar( 'o'))
        return "6";
    if(letter == QChar( 'p'))
        return "7";
    if(letter == QChar( 'q'))
        return "7";
    if(letter == QChar( 'r'))
        return "7";
    if(letter == QChar( 's'))
        return "7";
    if(letter == QChar( 't'))
        return "8";
    if(letter == QChar( 'u'))
        return "8";
    if(letter == QChar( 'v'))
        return "8";
    if(letter == QChar( 'w'))
        return "9";
    if(letter == QChar( 'x'))
        return "9";
    if(letter == QChar( 'y'))
        return "9";
    if(letter == QChar( 'z'))
        return "9";

    return nullptr;
}


