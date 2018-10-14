#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QDate>
#include <QMap>
#include <QVector>

#include <QDebug>
#include <QSqlError>

QString baremeDir = ("D:\\Sauvegarde_cle_terrain\\6_BDD\\BAREME_2005.MDB");
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
QVector<int> stationNosta;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<QVector<QString > > corthTable;


    //Connexion a la base BAREME et recuperation des informations
    db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+baremeDir);
    if(db.open()) {
        qDebug () << "win";
        QSqlQuery queryBareme;
        queryBareme.prepare("SELECT `nosta`, `nom`, `codehydro` FROM `station` ORDER BY `codehydro`;");
        queryBareme.exec();
        QStringList StationList;
        while (queryBareme.next()){
            StationList.append(queryBareme.value(2).toString()+" "+queryBareme.value(1).toString());
            stationNosta.push_back(queryBareme.value(0).toInt());
        }
        ui->StationComboBox->insertItems(0,StationList);
    }
    else
        qDebug () << "Loose";

    selectStation(0);
    ui->dateEdit_fin->setDate(QDate::currentDate());

    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(selectMeasurement()));
    QObject::connect(ui->StationComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectStation(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::selectStation(int index) {
    int nosta = stationNosta[index];
    //Connexion a la base BAREME et recuperation des informations
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+baremeDir);
    if(db.open()) {
        QSqlQuery qyeryCorthDate;

        qyeryCorthDate.prepare ("SELECT TOP 1 `ladate` FROM `courbecorrection` WHERE (`nosta` = "+QString::number(nosta)+") ORDER BY `ladate` DESC;");
        qyeryCorthDate.exec();

        while (qyeryCorthDate.next()){
            QDate lastCorth = qyeryCorthDate.value(0).toDate();
            ui->dateEdit_deb->setDate(lastCorth);
        }
    }
    else
        qDebug () << "LooseDATECorth";
}

void MainWindow::selectMeasurement() {
    qDebug () << "Corth";
    QDate dateDeb = ui->dateEdit_deb->date();
    QDate dateFin = ui->dateEdit_fin->date();


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//    QMap mapCoth = ;

    //Connexion a la base BAREME et recuperation des informations
    db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+baremeDir);
    if(db.open()) {
        qDebug () << "winCorth";
        QSqlQuery queryJaugeageBareme;
        int nosta = stationNosta[ui->StationComboBox->currentIndex()];
        qDebug() << "nosta = "+QString::number(nosta);

//VOIR JAUGEAGES DOUTEUX ?
        queryJaugeageBareme.prepare ("SELECT `jdatedeb`, `jcote`, `jdebit` FROM `jaugeage` WHERE (`nosta` = "+QString::number(nosta)+") AND (`jdatedeb` BETWEEN "+dateDeb.toString("#yyyy/MM/dd#")+" AND "+dateFin.toString("#yyyy/MM/dd#")+");");


        queryJaugeageBareme.exec();
        while (queryJaugeageBareme.next()){
            qDebug() << queryJaugeageBareme.value(0).toString()+" "+queryJaugeageBareme.value(1).toString()+" "+queryJaugeageBareme.value(2).toString();
        }
    }
    else
        qDebug () << "LooseCorth";

}


void MainWindow::loadCurve(int nosta,QDate jdatedeb) {

}

void MainWindow::generCoth (QPair<double, double> xy){

}

void MainWindow::exportBareme() {

}
