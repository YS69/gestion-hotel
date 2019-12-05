#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <hotel.h>
#include <chambres.h>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->tabhotel->setModel(tmphotel.afficher());
    ui->tabchambres->setModel(tmpchambres.afficher());
    mysystem=new QSystemTrayIcon(this);
        mysystem->setIcon(QIcon(":/icon.png"));
        mysystem->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_hotel_clicked()
{
mysystem->showMessage(tr("Notification"),tr("L'hotel a été ajouté"));
    int num = ui->lineEdit_num->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString adresse= ui->lineEdit_adresse->text();
  Hotel h(num,nom,adresse);
  bool test=h.ajouter();
  if(test)
{ui->tabhotel->setModel(tmphotel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un hotel"),
                  QObject::tr("Hotel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }

  else{
      QMessageBox ok;
      ok.setWindowTitle("Notification");
      ok.setText("Hotel existe deja !");
      ok.setStandardButtons(QMessageBox::Ok);
      ok.exec();

  }

}





void MainWindow::on_supprimer_clicked()
{
    int num = ui->lineEdit_nums->text().toInt();


    Hotel h;
    if(h.rechercher(num)){
        bool test = h.supprimer(num);
        if(test){
            ui->tabhotel->setModel(tmphotel.afficher());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un hotel"),
                              QObject::tr("Hotel suprrimé.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

    else{
        QMessageBox ok;
        ok.setWindowTitle("Notification");
        ok.setText("Hotel inexistant !");
        ok.setStandardButtons(QMessageBox::Ok);
        ok.exec();

    }
    }





void MainWindow::on_pushButton_clicked()
{
        int num = ui->lineEdit_numm->text().toInt();
        QString nom = ui->lineEdit_nomm->text();
        QString adresse = ui->lineEdit_adressem->text();

        Hotel h;
        if(h.rechercher(num)){
            bool test = h.modifier(num,nom,adresse);
            if(test){
                ui->tabhotel->setModel(tmphotel.afficher());
                QMessageBox::information(nullptr, QObject::tr("Modifier un hotel"),
                                  QObject::tr("Hotel modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else{
            QMessageBox ok;
            ok.setWindowTitle("Notification");
            ok.setText("Hotel inexistant !");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();

        }


}



void MainWindow::on_ajouter_chambre_clicked()
{
    mysystem->showMessage(tr("Notification"),tr("La chambre a été ajoutée"));

    int num = ui->lineEdit_numc->text().toInt();
    int etage= ui->lineEdit_etagec->text().toInt();
    QString type= ui->lineEdit_typec->text();
    QString etat=ui->lineEdit_etatc->text();
  Chambres c(num,etage,type,etat);
  bool test=c.ajouter();
  if(test)
{ui->tabchambres->setModel(tmpchambres.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Chambre ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else{
      QMessageBox ok;
      ok.setWindowTitle("Notification");
      ok.setText("Chambre existe deja !");
      ok.setStandardButtons(QMessageBox::Ok);
      ok.exec();

  }
}

void MainWindow::on_pushButton_9_clicked()
{
    int num = ui->lineEdit_14->text().toInt();
    Chambres c;
    if(c.rechercher(num)){
        bool test=c.supprimer(num);
        if(test)
        {ui->tabchambres->setModel(tmpchambres.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer une chambre"),
                        QObject::tr("Chambre supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else{
            QMessageBox ok;
            ok.setWindowTitle("Notification");
            ok.setText("Chambre inexistante !");
            ok.setStandardButtons(QMessageBox::Ok);
            ok.exec();

        }
    }
}




void MainWindow::on_pushButton_6_clicked()
{
    int num = ui->lineEdit_18->text().toInt();
    int etage = ui->lineEdit_19->text().toInt();
    QString type = ui->lineEdit_20->text();
    QString etat = ui->lineEdit_21->text();
       Chambres c;
       if(c.rechercher(num)){
           bool test = c.modifier(num,etage,type,etat);
           if(test){
               ui->tabchambres->setModel(tmpchambres.afficher());
               QMessageBox::information(nullptr, QObject::tr("Modifier une chambre"),
                                 QObject::tr("Chambre modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           }
           else{ QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
           }
           }
       else{
           QMessageBox ok;
           ok.setWindowTitle("Notification");
           ok.setText("Chambre inexistante !");
           ok.setStandardButtons(QMessageBox::Ok);
           ok.exec();

       }
       }



void MainWindow::on_pushButton_3_clicked()
{
    int num = ui->lineEdit_4->text().toInt();
    ui->tabhotel->setModel(tmphotel.chercher(num));
}

void MainWindow::on_pushButton_4_clicked()
{
    int num = ui->lineEdit_3->text().toInt();
    ui->tabchambres->setModel(tmpchambres.chercher(num));
}








