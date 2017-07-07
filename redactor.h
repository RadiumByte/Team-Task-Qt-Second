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

private:
    Ui::Redactor *ui;
};

#endif // REDACTOR_H
