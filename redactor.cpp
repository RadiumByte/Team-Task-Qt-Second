#include "redactor.h"
#include "ui_redactor.h"
#include "studenttable.h"

Redactor::Redactor(QWidget *parent) : QMainWindow(parent), ui(new Ui::Redactor)
{
    ui->setupUi(this);
    StudentTable *model = new StudentTable;
    ui->mainTable->setModel(model);
    //bool value = model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    //model->setHeaderData(1, Qt::Horizontal, "Name");
    //model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
    //model->setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));
}

Redactor::~Redactor()
{
    delete ui;
}
