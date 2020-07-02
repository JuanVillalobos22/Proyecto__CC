 #ifndef REGISTRARADMINDIALOG_H
#define REGISTRARADMINDIALOG_H

#include <QDialog>
#include <administrador.h>

namespace Ui {
class RegistrarAdminDialog;
}

class RegistrarAdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrarAdminDialog(QWidget *parent = nullptr);
    ~RegistrarAdminDialog();
    Administrador getAdmin() const {return admin;}

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RegistrarAdminDialog *ui;
    Administrador admin;
};

#endif // REGISTRARADMINDIALOG_H
