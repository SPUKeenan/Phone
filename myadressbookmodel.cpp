#include "myadressbookmodel.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
MyAdressBookModel::MyAdressBookModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int MyAdressBookModel::rowCount(const QModelIndex &parent) const
{
    return firstNames.size();
}

int MyAdressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyAdressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
    switch(index.column())
    {
        case 0:
        return firstNames.at(index.row());
    case 1:
        return lastNames.at(index.row());
      case 2:
        return  phoneNumbers.at(index.row());
    }
    }
    return QVariant();
}



void MyAdressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    firstNames.clear();
    lastNames.clear();
    phoneNumbers.clear();

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

    firstNames.push_back(fields[0]);
    lastNames.push_back(fields[1]);
    phoneNumbers.push_back(fields[7]);
}
    file.close();
    emit layoutChanged();
}



