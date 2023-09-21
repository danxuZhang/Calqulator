#include "calqulator.h"

#include "./ui_calqulator.h"

double calcVal    = 0.0;
bool addTriggered = false;
bool subTriggered = false;
bool mulTriggered = false;
bool divTriggered = false;

Calqulator::Calqulator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calqulator) {
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];

    for (int i = 0; i < 10; ++i) {
        QString buttonName = "Button" + QString::number(i);
        numButtons[i]      = Calqulator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Plus, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->Equals, SIGNAL(released()), this, SLOT(EqualButtonPressed()));
    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
    connect(ui->Clear, SIGNAL(released()), this, SLOT(AllClear()));
}

Calqulator::~Calqulator() {
    delete ui;
}

void Calqulator::NumPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString butVal      = button->text();
    QString displayVal  = ui->Display->text();

    if (displayVal.toDouble() == 0 || displayVal.toDouble() == 0.0) {
        ui->Display->setText(butVal);
    } else {
        QString newVal   = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void Calqulator::MathButtonPressed() {
    addTriggered = false;
    subTriggered = false;
    mulTriggered = false;
    divTriggered = false;

    QString displayVal  = ui->Display->text();
    calcVal             = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal      = button->text();
    if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0) {
        addTriggered = true;
    } else if (QString::compare(butVal, "-", Qt::CaseInsensitive) == 0) {
        subTriggered = true;
    } else if (QString::compare(butVal, "*", Qt::CaseInsensitive) == 0) {
        mulTriggered = true;
    } else if (QString::compare(butVal, "/", Qt::CaseInsensitive) == 0) {
        divTriggered = true;
    }

    ui->Display->setText("");
}

void Calqulator::EqualButtonPressed() {
    double solution      = 0.0;
    QString displayVal   = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if (addTriggered || subTriggered || mulTriggered || divTriggered) {
        if (addTriggered) {
            solution = calcVal + dblDisplayVal;
        } else if (subTriggered) {
            solution = calcVal - dblDisplayVal;
        } else if (mulTriggered) {
            solution = calcVal * dblDisplayVal;
        } else if (divTriggered) {
            solution = calcVal / dblDisplayVal;
        }
    }

    ui->Display->setText(QString::number(solution));
}

void Calqulator::ChangeNumberSign() {
    QString displayVal = ui->Display->text();
    QRegularExpression reg("[-]?[0-9.]*");
    if (reg.match(displayVal).hasMatch()) {
        double dblDisplayVal     = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}

void Calqulator::AllClear() {
    addTriggered = false;
    subTriggered = false;
    mulTriggered = false;
    divTriggered = false;

    calcVal = 0;
    ui->Display->setText(QString::number(calcVal));
}
