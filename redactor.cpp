#include "redactor.h"
#include "ui_redactor.h"
#include "studenttable.h"

Redactor::Redactor(QWidget *parent) : QMainWindow(parent), ui(new Ui::Redactor)
{
    ui->setupUi(this);
    StudentTable *model = new StudentTable;
    ui->mainTable->setModel(model);
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
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}


void Redactor::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

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
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}


void Redactor::on_actionAbout_triggered()
{
}

void Redactor::on_actionQuit_triggered()
{
     QApplication::quit();
}
