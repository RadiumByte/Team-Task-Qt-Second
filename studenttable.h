#ifndef STUDENTTABLE_H
#define STUDENTTABLE_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QObject>

#define COLS_COUNT 3
#define ROWS_COUNT 5

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

//protected:
    //bool            dropMimeData (const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    bool            insertRows   (int position, int rows, const QModelIndex &index);
    bool            removeRows   (int position, int rows, const QModelIndex &index);
    int             rowCount     (const QModelIndex &parent = QModelIndex()) const;
    int             columnCount  (const QModelIndex &parent = QModelIndex()) const;
    QVariant        data         (const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool            setData      (const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant        headerData   (int section, Qt::Orientation orientation, int role) const;
    //bool            setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags   flags        (const QModelIndex &index) const;
    bool            readFile     (const QString filename);
    bool            wrtieFile    (const QString filename);

private:
    QList <Person> students;

};
#endif // STUDENTTABLE_H
