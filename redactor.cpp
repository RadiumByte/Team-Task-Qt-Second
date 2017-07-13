#include "redactor.h"
#include "ui_redactor.h"
#include "studenttable.h"

Redactor::Redactor(QWidget *parent) : QMainWindow(parent), ui(new Ui::Redactor)
{
    ui->setupUi(this);
    StudentTable *model = new StudentTable;
    ui->mainTable->setModel(model);
    ui->mainTable->verticalHeader()->setVisible(true);
    ui->mainTable->setShowGrid(true);
}

Redactor::~Redactor()
{
    delete ui;
}

void Redactor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Dat Files (*.dat)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        else
        {
            QDataStream input(&file);

            StudentTable::Person current;
            StudentTable *model = new StudentTable;

            // reading from file
            while (true)
            {
                input >> current;
                model->students.push_back(current);
                if (input.atEnd())
                    break;
            }

            ui->mainTable->setModel(model);

            file.close();
        }
    }
}


void Redactor::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Dat Files (*.dat"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        else
        {
            QDataStream output(&file);
            StudentTable::Person current;
            QModelIndex index;

            // writing to file: read every cell, form new person, then write
            for (int i = 0; i < ui->mainTable->model()->rowCount(); ++i)
            {
                index = ui->mainTable->model()->index(i,0);
                current.name = ui->mainTable->model()->data(index, Qt::DisplayRole).value<QString>();
                index = ui->mainTable->model()->index(i,1);
                current.course = (ui->mainTable->model()->data(index, Qt::DisplayRole)).value<uint>();
                index = ui->mainTable->model()->index(i,2);
                current.group = (ui->mainTable->model()->data(index, Qt::DisplayRole)).value<uint>();
                output << current;
            }
        }
        file.close();
    }
}


void Redactor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About developers", "Anton Fedyashov, Denis Teplyukov\n\nMMCS SFEDU\n2017");
}

void Redactor::on_actionQuit_triggered()
{
     QApplication::quit();
}

// creates three empty rows
void Redactor::on_actionCreate_new_triggered()
{
    StudentTable::Person current;
    StudentTable *model = new StudentTable;
    current.name = "";
    current.group = 0;
    current.course = 0;
    model->students.push_back(current);
    current.name = "";
    current.group = 0;
    current.course = 0;
    model->students.push_back(current);
    current.name = "";
    current.group = 0;
    current.course = 0;
    model->students.push_back(current);
    ui->mainTable->setModel(model);
}

void Redactor::on_addButton_clicked()
{
    QModelIndex current = ui->mainTable->currentIndex();
    ui->mainTable->model()->insertRows(1, 1, current);
}

void Redactor::on_deleteButton_clicked()
{
    QModelIndex current = ui->mainTable->currentIndex();
    if (ui->mainTable->model()->rowCount() != 1)
    {
        ui->mainTable->model()->removeRows(1, 1, current);
    }
}

