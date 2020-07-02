#ifndef USUARIO_H
#define USUARIO_H

#include <QString>


class Usuario
{
    int idUsuario;
    QString nombreUsuario;
    QString claveUsuario;

public:
    Usuario(int id = -1, const QString &nombre = "", const QString &clave = "" );

    int getId() const {return idUsuario;}
    QString getNombre() const {return nombreUsuario;};
    QString getClave() const {return claveUsuario;};

    void setId(int newId) {idUsuario = newId;}
    void setNombre(QString &newNombre) {nombreUsuario = newNombre;}
    void setClave(QString &newClave) {claveUsuario = newClave;}


};

#endif // USUARIO_H
