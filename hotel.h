#ifndef HOTEL_H
#define HOTEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Hotel
{public:
    Hotel();
    Hotel(int,QString,QString);
    QString get_nom();
    QString get_adresse();
    int get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rechercher(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel * chercher(int num);
private:
    QString nom,adresse;
    int num;
};

#endif // HOTEL_H
