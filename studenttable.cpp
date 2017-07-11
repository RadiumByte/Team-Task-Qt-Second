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
    return 3;
}

QVariant StudentTable::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0: return tr(students.at(index.row()).name);
        case 1: return students.at(index.row()).group;
        case 2: return students.at(index.row()).course;
        default: break;
        }
    }
    return QVariant();
}

bool StudentTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    /*
    if (role == Qt::EditRole)
    {
        m_gridData[index.row()][index.column()] = value.toString();

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
    */
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
                return QString("Name");
            case 1:
                return QString("Course");
            case 2:
                return QString("Group");
            }
        }
    }
    return QVariant();
}

bool operator<<(QDataStream &output, const StudentTable::Person &item)
{
    output << item.course;
    output << item.group;
    output.writeBytes(item.name,NAME_SIZE);
    return true;
}

bool operator>>(QDataStream &input, StudentTable::Person &item)
{
    input >> item.course;
    input >> item.group;
    char* name;
    uint size = NAME_SIZE;
    input.readBytes(name,size);
    item.name = (char*)name;
    return true;
}

void StudentTable::drawRow(QVector<StudentTable::Person> items)
{
    beginInsertRows(QModelIndex(), items.size(), items.size());
    /*
    S FF;
    FF.Name = r;
    FF.Name1 = n;
    FF.Name2 = b;
    FF.Name3 = z;
    listclient.append(FF);
    */
    endInsertRows();
}
