#ifndef CALQULATOR_H
#define CALQULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calqulator;
}
QT_END_NAMESPACE

class Calqulator : public QMainWindow {
    Q_OBJECT

  public:
    Calqulator(QWidget *parent = nullptr);
    ~Calqulator();

  private:
    Ui::Calqulator *ui;
};
#endif // CALQULATOR_H
