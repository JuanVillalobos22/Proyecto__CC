#include "dialog.h"
#include "ui_dialog.h"
#include "registraradmindialog.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->claveLineEdit->setEchoMode(QLineEdit::Password);

    compruebaAdmin();

    ui->usuarioNormalRadioButton->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    QSqlQuery q;
    Usuario u(-1, ui->usuarioLineEdit->text(), ui->claveLineEdit->text());
    int cantidad;
    bool esUsuario;

    if (ui->usuarioNormalRadioButton->isChecked())
    {
        q.exec(QString("SELECT COUNT(*) FROM usuario WHERE nombre LIKE"
                       " '%1' AND clave LIKE '%2'").arg(u.getNombre()) .arg(u.getClave()));
        q.next();
        cantidad = q.value(0).toInt();
        if (cantidad == 0)
        {
            QMessageBox::warning(this, "Aviso", "El nombre de usuario o la contraseña son incorrectos" );
            return;
        }
        esUsuario = true;
    }
    else
    {
        q.exec(QString("SELECT COUNT(*) FROM administrador WHERE nombre LIKE"
                       " '%1' AND clave LIKE '%2'").arg(u.getNombre()) .arg(u.getClave()));
        q.next();

        cantidad = q.value(0).toInt();

        if (cantidad == 0)
        {
            QMessageBox::warning(this, "Aviso", "El nombre de usuario o la contraseña son incorrectos" );
            return;
        }
        esUsuario = false;

    }

    if (esUsuario)
    {
        tipo = USUARIO;
    }
    else
    {
        tipo = ADMINISTRADOR;
    }
    accept();

}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_registrarAdminPushButton_clicked()
{
    RegistrarAdminDialog d(this);
    if (d.exec()==QDialog::Rejected)
    {
        return;
    }
    auto admin = d.getAdmin();

    QSqlQuery q;
    q.exec(QString("INSERT INTO administrador (nombre, clave) VALUES ('%1', '%2')")
           .arg(admin.getNombre()) .arg(admin.getClave()) );

    compruebaAdmin();

}


void Dialog::compruebaAdmin()
{

    QSqlQuery q;
    q.exec("SELECT count(*) FROM administrador");
    q.next();

    const int cantidadAdmins = q.value(0).toInt();
    if (cantidadAdmins != 2)
    {
        ui->registrarAdminPushButton->setEnabled(true);
    }
    else
    {
        ui->registrarAdminPushButton->setEnabled(false);
    }
}
