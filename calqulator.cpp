#include "calqulator.h"

#include "./ui_calqulator.h"

Calqulator::Calqulator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calqulator) {
    ui->setupUi(this);
}

Calqulator::~Calqulator() {
    delete ui;
}
