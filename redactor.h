#ifndef REDACTOR_H
#define REDACTOR_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

namespace Ui
{
    class Redactor;
}

class Redactor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Redactor(QWidget *parent = 0);
    ~Redactor();

private slots:
    // open new document
    void on_actionOpen_triggered();

    // save document
    void on_actionSave_triggered();

    // about window
    void on_actionAbout_triggered();

    // quit from program
    void on_actionQuit_triggered();

    // create new document
    void on_actionCreate_new_triggered();

    // add row after selected cell
    void on_addButton_clicked();

    // delete selected cell
    void on_deleteButton_clicked();

private:
    Ui::Redactor *ui;
};

#endif // REDACTOR_H
