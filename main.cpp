#include "redactor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Redactor w;
    Redactor *about = new Redactor();
    w.show();

    return a.exec();
}
