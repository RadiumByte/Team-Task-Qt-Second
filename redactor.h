#ifndef REDACTOR_H
#define REDACTOR_H

#include <QMainWindow>

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
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

private:
    Ui::Redactor *ui;
};

#endif // REDACTOR_H
