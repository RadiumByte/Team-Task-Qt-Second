#include "studenttable.h"

StudentTable::StudentTable(QObject *parent):QAbstractTableModel(parent)
{}

bool StudentTable::insertRows(int position, int rows, const QModelIndex &index)
{
    return true;
}

bool StudentTable::removeRows(int position, int rows, const QModelIndex &index)
{
    return true;
}

int StudentTable::rowCount(const QModelIndex &parent) const
{
    return students.size();
}

int StudentTable::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant StudentTable::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

bool StudentTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        m_gridData[index.row()][index.column()] = value.toString();
        //for presentation purposes only: build and emit a joined string
        QString result;
        for (int row= 0; row < ROWS; row++)
        {
            for(int col= 0; col < COLS; col++)
            {
                result += m_gridData[row][col] + ' ';
            }
        }
        emit editCompleted( result );
    }
    return true;
}

QVariant StudentTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Name");
            case 2:
                return QString("Course");
            case 3:
                return QString("Group");
            }
        }
    }
    return QVariant();
}

/*
bool StudentTable::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return true;
}
*/

Qt::ItemFlags StudentTable::flags(const QModelIndex &index) const
{
    return 0;
}



