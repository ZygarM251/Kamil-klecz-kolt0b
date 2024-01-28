#ifndef ZOLNIERZ_H
#define ZOLNIERZ_H
#include <QString>

class zolnierz
{

private:
    QString nazwisko;
    int rank;
    int wiek;

public:

/*
    enum ranga{
        szeregowy = 1,
        kapral = 2,
        brygadzista = 3
    };
*/
    zolnierz();
    zolnierz(QString nazwisko, int wiek, int rank);
    QString getNazwisko(){return nazwisko;}
    int getRanga(){return rank;}
    int getWiek(){return wiek;}

    bool operator<(zolnierz &rhs){
        if(wiek > rhs.wiek){
            return true;
        }
        return false;
    }



};



#endif // ZOLNIERZ_H
