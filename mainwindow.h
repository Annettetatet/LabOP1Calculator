#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculatorlogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_onBtn_clicked();

    void on_number0Btn_clicked();
    void on_number1Btn_clicked();
    void on_number2Btn_clicked();
    void on_number3Btn_clicked();
    void on_number4Btn_clicked();
    void on_number5Btn_clicked();
    void on_number6Btn_clicked();
    void on_number7Btn_clicked();
    void on_number8Btn_clicked();
    void on_number9Btn_clicked();

    void on_cBtn_clicked();
    void on_plusBtn_clicked();
    void on_minusBtn_clicked();
    void on_multiplyBtn_clicked();
    void on_divideBtn_clicked();
    void on_resultBtn_clicked();
    void on_delBtn_clicked();
    void on_dotBtn_clicked();

private:
    Ui::MainWindow *ui;
    ModelState modelState;

    void updateScreen();
};
#endif // MAINWINDOW_H
