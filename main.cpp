#include "calqulator.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Calqulator w;
    w.show();
    return a.exec();
}
