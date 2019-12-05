#ifndef CHAMBRES_H
#define CHAMBRES_H


#define CHAMBRES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Chambres
{
public:
    Chambres();
    Chambres(int,int,QString,QString);
    int get_num();
    int get_etage();
    QString get_type();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int ,int, QString,QString);
    bool rechercher(int);
    QSqlQueryModel * chercher(int num);
private:
    int num,etage;
    QString type;
    QString etat;
};



#endif // CHAMBRES_H
