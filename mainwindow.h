#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMetaEnum>
#include <QMessageBox>
#include "zolnierz.h"
#include "dialog.h"
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
    void on_pushButton_dodaj_clicked();
    void on_pushButton_najmlodszy_clicked();

private:

    void dodajZolnierza(QString nazwisko, int wiek, int rank);
    void dodajElement(int wie, int kol, QString tekst);
    void aktualizujTabele();
    QString rangaDoString(int ranga);
    int StringDoRangi(QString string);
    Ui::MainWindow *ui;
    QList <zolnierz> lista;
    Dialog * m_okno;

};
#endif // MAINWINDOW_H
