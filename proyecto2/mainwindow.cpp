#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

#include <QMessageBox>

MainWindow::MainWindow(int tipo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (tipo == Dialog::ADMINISTRADOR )
    {

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAgregair_elementos_triggered()
{
    QMessageBox::information(this, "Datos", "Se deben mostrar los datos");
}

void MainWindow::on_actionEliminar_elementos_triggered()
{
    QMessageBox::information(this, "Datos", "Se deben eliminar los datos");
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::information(this, "Mensaje", "Este programa fue desarrollado por el equipo DELTA");
}
