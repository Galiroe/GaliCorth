#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialogButtonBox>
#include <QPair>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void loadCurve(int nosta,QDate jdatedeb);
    void generCoth (QPair<double, double> xy);

    ~MainWindow();

private slots:
    void selectMeasurement();
    void selectStation(int index);
    void exportBareme();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
