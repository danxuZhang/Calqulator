#ifndef CALQULATOR_H
#define CALQULATOR_H

#include <QMainWindow>
#include <QRegularExpression>

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

  private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void AllClear();
    void ChangeNumberSign();
};
#endif // CALQULATOR_H
