#include "chambres.h"
#include <QDebug>
#include <QSqlError>
Chambres::Chambres()
{
num=0;
etage=0;
type="";
}
Chambres::Chambres(int num,int etage,QString type,QString etat)
{
  this->num=num;
  this->etage=etage;
  this->type=type;
  this->etat=etat;
}
int Chambres::get_num(){return  num;}
int Chambres::get_etage(){return etage;}
QString Chambres::get_type(){return  type;}

bool Chambres::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
QString res2= QString::number(etage);
query.prepare("INSERT INTO chambre (NUM, ETAGE, TYPE,ETAT) "
                    "VALUES (:num, :etage, :type,:etat)");
query.bindValue(":num", res);
query.bindValue(":etage", res2);
query.bindValue(":type", type);
query.bindValue(":etat", etat);

return    query.exec();
}

QSqlQueryModel * Chambres::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chambre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etage "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}

bool Chambres::supprimer(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from chambre where Num = :num ");
query.bindValue(":num", res);
query.exec();
return query.exec();
}
bool Chambres::modifier(int a,int b, QString d,QString c){
    QSqlQuery query;
    QString res= QString::number(a);
    QString res2= QString::number(b);
    query.prepare("update chambre set etage=:etage ,type=:type,etat=:etat  where num= :numero");
    query.bindValue(":numero", res);
    query.bindValue(":type", d);
    query.bindValue(":etage", res2);
    query.bindValue(":etat", c);
    return query.exec();
}
bool Chambres::rechercher(int x){
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from chambre where num = :num;");
    query.bindValue(":num", res);
    query.exec();
    return query.first();
}
QSqlQueryModel * Chambres::chercher(int num)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from chambre WHERE num=:num"));

     query.bindValue(":num",num);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etage"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etat"));


return model;
 }

