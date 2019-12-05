#include "hotel.h"
#include <QDebug>
#include <QSqlError>
Hotel::Hotel()
{
num=0;
nom="";
adresse="";
}
Hotel::Hotel(int num,QString nom,QString adresse)
{
  this->num=num;
  this->nom=nom;
  this->adresse=adresse;
}
QString Hotel::get_nom(){return  nom;}
QString Hotel::get_adresse(){return adresse;}
int Hotel::get_num(){return  num;}

bool Hotel::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("INSERT INTO hotel (NUM, NOM, ADRESSE) "
                    "VALUES (:num, :nom, :adresse)");
query.bindValue(":num", res);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
qDebug()<<query.lastError().text();
return    query.exec();
}

QSqlQueryModel * Hotel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from hotel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
}

bool Hotel::supprimer(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from hotel where Num = :num ");
query.bindValue(":num", res);
query.exec();
return query.exec();
}

bool Hotel::rechercher(int num){
    QSqlQuery query;
    query.prepare("select * from hotel where num = :num;");
    query.bindValue(":num", num);
    query.exec();
    return query.first();
}

bool Hotel::modifier(int a,QString b,QString c){
    QSqlQuery query;
    query.prepare("update hotel set num=:num ,nom=:nom ,adresse=:adresse  where num = :num;");
    query.bindValue(":num", a);
    query.bindValue(":nom", b);
    query.bindValue(":adresse", c);
    return query.exec();
}

    bool rech(int);
    bool modifier(int,QString,QString);

    QSqlQueryModel * Hotel::chercher(int num)
     {

         QSqlQueryModel * model = new QSqlQueryModel();
         QSqlQuery query;
         query.prepare(QString("select * from hotel WHERE num=:num"));

         query.bindValue(":num",num);

          query.exec();
         model->setQuery(query);
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));


    return model;
     }







