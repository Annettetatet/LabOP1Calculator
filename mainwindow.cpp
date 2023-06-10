#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clearModelState(&modelState);
    updateScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateScreen() {
    ui->screenEdt->setText(QString::fromStdString(getScreenValue(&modelState)));
    ui->screenEdt->setAlignment(Qt::AlignRight);

    ui->plusBtn->setEnabled(!isSecondNumberEditing(&modelState));
    ui->minusBtn->setEnabled(!isSecondNumberEditing(&modelState));
    ui->multiplyBtn->setEnabled(!isSecondNumberEditing(&modelState));
    ui->divideBtn->setEnabled(!isSecondNumberEditing(&modelState));

    ui->dotBtn->setEnabled(isDotAvailable(&modelState));
    ui->resultBtn->setEnabled(isEqualAvailable(&modelState));
    ui->delBtn->setEnabled(isDeleteAvailable(&modelState));
}


void MainWindow::on_onBtn_clicked()
{
    close();
}


void MainWindow::on_number0Btn_clicked()
{
    addNumber(&modelState, 0);
    updateScreen();
}


void MainWindow::on_number1Btn_clicked()
{
    addNumber(&modelState, 1);
    updateScreen();
}


void MainWindow::on_number2Btn_clicked()
{
    addNumber(&modelState, 2);
    updateScreen();
}


void MainWindow::on_number3Btn_clicked()
{
    addNumber(&modelState, 3);
    updateScreen();
}


void MainWindow::on_number4Btn_clicked()
{
    addNumber(&modelState, 4);
    updateScreen();
}


void MainWindow::on_number5Btn_clicked()
{
    addNumber(&modelState, 5);
    updateScreen();
}


void MainWindow::on_number6Btn_clicked()
{
    addNumber(&modelState, 6);
    updateScreen();
}


void MainWindow::on_number7Btn_clicked()
{
    addNumber(&modelState, 7);
    updateScreen();
}


void MainWindow::on_number8Btn_clicked()
{
    addNumber(&modelState, 8);
    updateScreen();
}


void MainWindow::on_number9Btn_clicked()
{
    addNumber(&modelState, 9);
    updateScreen();
}


void MainWindow::on_cBtn_clicked()
{
    clearModelState(&modelState);
    updateScreen();
}


void MainWindow::on_plusBtn_clicked()
{
    applyOperation(&modelState, OperationTypeEnum::plus);
    updateScreen();
}


void MainWindow::on_minusBtn_clicked()
{
    applyOperation(&modelState, OperationTypeEnum::minus);
    updateScreen();
}


void MainWindow::on_multiplyBtn_clicked()
{
    applyOperation(&modelState, OperationTypeEnum::multiply);
    updateScreen();
}


void MainWindow::on_divideBtn_clicked()
{
    applyOperation(&modelState, OperationTypeEnum::divide);
    updateScreen();
}


void MainWindow::on_resultBtn_clicked()
{
    double result = calculateResult(&modelState);
    updateScreen();
    if (result == 987654e-99) {
        QMessageBox::warning(this, "Внимание",
                             "Деление на ноль");
    }
}


void MainWindow::on_delBtn_clicked()
{
    del(&modelState);
    updateScreen();
}


void MainWindow::on_dotBtn_clicked()
{
    addDot(&modelState);
    updateScreen();
}

