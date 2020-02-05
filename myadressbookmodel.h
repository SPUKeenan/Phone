#ifndef MYADRESSBOOKMODEL_H
#define MYADRESSBOOKMODEL_H

#include <QAbstractTableModel>


class MyAdressBookModel: public QAbstractTableModel
{
public:
    MyAdressBookModel(QObject *parent);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void openFile(QString filePath);
    QString getPhoneNumber(int index);
    std::vector<QString> firstNames;
    std::vector<QString> lastNames;
    std::vector<QString> phoneNumbers;
};

#endif // MYADRESSBOOKMODEL_H
