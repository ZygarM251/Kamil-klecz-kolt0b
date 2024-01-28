#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_dodaj_clicked()
{
    m_okno = new Dialog(nullptr);
    int result = m_okno->exec();
    if(result){
        int wiek = m_okno->getWiek();
        int ranga = StringDoRangi(m_okno->getRanga());
        QString nazwisko = m_okno->getNazwisko();
        if(wiek > 0){
            dodajZolnierza(nazwisko, wiek, ranga);
            aktualizujTabele();
        }else{
            ui->statusbar->showMessage("Nieprawidłowy wiek", 5000);
        }
    }
    delete m_okno;
}

void MainWindow::dodajZolnierza(QString nazwisko, int wiek, int rank){
    zolnierz zol(nazwisko, wiek, rank);
    lista.push_back(zol);
    std::sort(lista.begin(), lista.end());
}

void MainWindow::dodajElement(int wie, int kol, QString tekst){
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(tekst);
    ui->tableWidget->setItem(wie,kol,item);
}

void MainWindow::aktualizujTabele(){
    int rozmiarListy = lista.size();
    ui->tableWidget->setRowCount(rozmiarListy);
    for (int nrZol = 0; nrZol < rozmiarListy; ++nrZol) {
        dodajElement(nrZol, 0, rangaDoString(lista[nrZol].getRanga()));
        dodajElement(nrZol, 1, lista[nrZol].getNazwisko());
        dodajElement(nrZol, 2, QString::number(lista[nrZol].getWiek()));
    }
}

void MainWindow::on_pushButton_najmlodszy_clicked()
{
    int rozmiarListy = lista.size();
    int wybranyNumer = 0;
    int najmniejszyWiek = INT_MAX;
    int wybranaRanga = StringDoRangi(ui->comboBox->currentText());
    bool czyIstnieje = false;
    for (int nrZol = 0; nrZol < rozmiarListy; ++nrZol) {
        if(lista[nrZol].getRanga() == wybranaRanga && lista[nrZol].getWiek() < najmniejszyWiek){
            wybranyNumer = nrZol;
            najmniejszyWiek = lista[nrZol].getWiek();
            czyIstnieje = true;
        }
    }
    QMessageBox mbox(this);
    QString tekst = "";
    if(czyIstnieje){
        tekst = "Najmłodszy " + ui->comboBox->currentText() +": \nWiek:\t\t" + QString::number(najmniejszyWiek)
                        + "\nNazwisko:\t" + lista[wybranyNumer].getNazwisko();
    }else{
        tekst = "Kompania nie ma żołnieża\n   o podanej randze";
    }
    mbox.setText(tekst);
    mbox.exec();
}

QString MainWindow::rangaDoString(int ranga){


    switch(ranga){

    case 1: return "szeregowy"; break;
    case 2: return "kapral"; break;
    case 3: return "brygadzista";
    }
    return "invalid";
}

int MainWindow::StringDoRangi(QString string){

    if(string=="szeregowy"){
        return 1;
    } else if(string=="kapral"){
        return 2;
    }else{
        return 3;
    }
}



















