#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"

class Administrador : public Usuario
{
public:
    Administrador(int id, const QString &nombre, const QString &clave);
};

#endif // ADMINISTRADOR_H
