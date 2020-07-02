#include "registraradmindialog.h"
#include "ui_registraradmindialog.h"
#include <QMessageBox>
#include <QDebug>

RegistrarAdminDialog::RegistrarAdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrarAdminDialog),
    admin(-1, "", "")
{
    ui->setupUi(this);
    ui->claveLineEdit->setEchoMode(QLineEdit::Password);
    ui->repiteClaveLineEdit->setEchoMode(QLineEdit::Password);
}

RegistrarAdminDialog::~RegistrarAdminDialog()
{
    delete ui;
}

void RegistrarAdminDialog::on_buttonBox_accepted()
{
    admin.setId(1);
    QString name = ui->usuarioLineEdit->text();
    QString password = ui->claveLineEdit->text();


    admin.setNombre(name);
    admin.setClave(password);

    qDebug() << admin.getId();
    qDebug() << admin.getNombre();
    qDebug() << admin.getClave();


    if (admin.getClave() != ui->repiteClaveLineEdit->text())
    {
        QMessageBox::critical(this, "Error", "Las contraseñas deben ser iguales");

        return;
    }
    accept();
}

void RegistrarAdminDialog::on_buttonBox_rejected()
{
    reject();
}
