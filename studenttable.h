#ifndef STUDENTTABLE_H
#define STUDENTTABLE_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QObject>
#include <QDataStream>

#define COLS_COUNT 3
#define ROWS_COUNT 5
#define NAME_SIZE  30

class StudentTable : public QAbstractTableModel
{
    Q_OBJECT

public:
    struct Person
    {
        char*    name;
        uint     course;
        uint     group;
    };

    StudentTable(QObject *parent = 0);

    //void sort (int column, Qt::SortOrder order = Qt::AscendingOrder); //!!сортировка

    bool            insertRows   (int position, int rows, const QModelIndex &index);
    bool            removeRows   (int position, int rows, const QModelIndex &index);
    int             rowCount     (const QModelIndex &parent = QModelIndex()) const;
    int             columnCount  (const QModelIndex &parent = QModelIndex()) const;
    QVariant        data         (const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool            setData      (const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant        headerData   (int section, Qt::Orientation orientation, int role) const;
    void            drawRow    (QVector<StudentTable::Person> items);

    QVector <Person> students;
};

bool operator<<(QDataStream &output, const StudentTable::Person &item);

bool operator>>(QDataStream &input, StudentTable::Person &item);
Q_DECLARE_METATYPE(StudentTable::Person)
Q_DECLARE_METATYPE(char*)
#endif // STUDENTTABLE_H
