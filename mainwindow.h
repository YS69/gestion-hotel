#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <hotel.h>
#include <chambres.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_supprimer_clicked();

    void on_ajouter_hotel_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_ajouter_chambre_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    Hotel tmphotel;
    Chambres tmpchambres;
QSystemTrayIcon * mysystem;
};

#endif // MAINWINDOW_H
