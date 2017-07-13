#include "studenttable.h"
#include <algorithm>

StudentTable::StudentTable(QObject *parent):QAbstractTableModel(parent)
{}

bool StudentTable::insertRows(int position, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(), position, position);

    Person p;
    p.name = "";
    p.course = 0;
    p.group = 0;
    students.resize(students.size()+1);
    students.insert(index.row()+1, p);

    endInsertRows();
    return true;
}

bool StudentTable::removeRows(int position, int rows, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), position, position);

    students.removeAt(index.row());

    endRemoveRows();
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
        case 0: return students.at(index.row()).name;
        case 1: return students.at(index.row()).course;
        case 2: return students.at(index.row()).group;
        default: break;
        }
    }
    return QVariant();
}

bool StudentTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        int row = index.row();
        int col = index.column();
        Person p = students.value(row);
        switch (col)
        {
        case 0:
        {
            p.name = value.value<QString>();
            break;
        }
        case 1:
        {
            p.course = value.toUInt();
            break;
        }
        case 2:
        {
            p.group = value.toUInt();
            break;
        }
        default:
            return false;
        }
        students.replace(row, p);
        emit(dataChanged(index, index));
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
    output << item.name;
    return true;
}

bool operator>>(QDataStream &input, StudentTable::Person &item)
{
    input >> item.course;
    input >> item.group;
    input >> item.name;
    return true;
}

Qt::ItemFlags StudentTable::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
