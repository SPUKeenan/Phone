#ifndef MYADRESSBOOKMODEL_H
#define MYADRESSBOOKMODEL_H

#include <QAbstractTableModel>


class MyAddressBookModel: public QAbstractTableModel
{
public:
    MyAddressBookModel(QObject *parent);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void openFile(QString filePath);
    QString getPhoneNumber(int index);
    QString convertNameToNumbers(QString name);
    int convertCharToNum(char letter);

    struct Person{
        QString firstName;
        QString lastName;
        QString phoneNumber;
    };
    std::vector<Person> contactList;

};

#endif // MYADRESSBOOKMODEL_H
