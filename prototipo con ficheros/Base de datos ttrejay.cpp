//Registro de productos

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;


class menu
{
private:
    string nombre;
    string precio;
    string cantidad;
    string Fecha;
    string codigo;

public:
    void registrar();
    void eliminar();
    void modificar();
    void listar();
    void menuPrincipal();
    void detalles();
    void mostarRegistro(string codigo);
};

void pausa();
void error();

void menu::menuPrincipal()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Registro de productos THE THREEJAY***\t\t\t\t\n\n";
        cout<<"1. Registrar un Producto\n\n";
        cout<<"2. Mostrar detalles de un Producto\n\n";
        cout<<"3. Listar Productos\n\n";
        cout<<"4. Eliminar un Producto\n\n";
        cout<<"5. Modificar un Producto\n\n";
        cout<<"6. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            registrar();
            break;

        case 2:
            detalles();
            break;

        case 3:
            listar();
            break;

        case 4:
            eliminar();
            break;

        case 5:
            modificar();
            break;

        case 6:
            break;
        }
    }
    while(opcion!=6);
}

void menu::registrar()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***registrar un producto***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del producto: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"c\242digo de producto no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigo);
            while(!verificador.eof())
            {
                getline(verificador,nombre);
                getline(verificador,precio);
                getline(verificador,cantidad);
                getline(verificador,Fecha);

                if(codigo==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un producto con ese c\242digo!\n\n";
                    cout<<"El producto con ese c\242digo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nc\242digo de producto no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigo);
            }

            if(verificador.eof()&&auxCodigo!=codigo)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigo=auxCodigo;
        cout<<"\t\t\t\t***Registrar un producto***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del producto: ";
        cout<<codigo;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del producto: ";
        getline(cin,nombre);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el precio del producto: ";
        getline(cin,precio);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa cantidad de unidades del producto: ";
        getline(cin,cantidad);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la fecha de inscripci\242n del  producto: ";
        getline(cin,Fecha);
        cout<<"\n\n";

        escritura<<codigo<<"\n"<<nombre<<"\n"<<precio<<"\n"<<cantidad
                 <<"\n"<<Fecha<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu::eliminar()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Eliminar un producto***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del producto que deseas eliminar: ";
        getline(cin,auxCodigo);
        getline(lectura,codigo);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,precio);
            getline(lectura,cantidad);
            getline(lectura,Fecha);

            if(auxCodigo==codigo)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigo<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Precio: "<<precio<<endl;
                cout<<"Unidades: "<<cantidad<<endl;
                cout<<"Fecha de inscripci\242n: "<<Fecha<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas eliminar a: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl se ha eliminado el producto correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nproducto conservado\n\n";
                    auxiliar<<codigo<<"\n"<<nombre<<"\n"<<precio<<"\n"<<cantidad
                            <<"\n"<<Fecha<<"\n";

                }

            }
            else
            {
                auxiliar<<codigo<<"\n"<<nombre<<"\n"<<precio<<"\n"<<cantidad
                        <<"\n"<<Fecha<<"\n";
            }
            getline(lectura,codigo);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::detalles()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("clientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar detalles de un producto***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del producto que deseas consultar detalles: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigo);
        while(!mostrar.eof())
        {
            getline(mostrar,nombre);
            getline(mostrar,precio);
            getline(mostrar,cantidad);
            getline(mostrar,Fecha);

            if(auxCodigo==codigo)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigo<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Precio: "<<precio<<endl;
                cout<<"Cantidad: "<<cantidad<<endl;
                cout<<"Fecha de inscripci\242n: "<<Fecha<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,codigo);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}

void menu::modificar()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxNombre;
    string auxDomicilio;
    string auxCelular;
    string auxFecha;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("clientes.txt",ios::in);
    verificador.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un producto***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del producto que deseas modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<"c\242digo de producto no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,codigo);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,precio);
            getline(lectura,cantidad);
            getline(lectura,Fecha);

            if(auxCodigo==codigo)
            {
                encontrado=true;
                mostarRegistro(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el producto\n\n";
                fflush(stdin);
                cout<<"Ingresa el c\242digo del producto: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigo);
                        while(!verificador.eof())
                        {
                            getline(verificador,nombre);
                            getline(verificador,precio);
                            getline(verificador,cantidad);
                            getline(verificador,Fecha);

                            if(auxCodigo==codigo)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un producto con ese c\242digo!\n\n";
                                cout<<"El producto con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de producto no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,codigo);
                        }

                        if(verificador.eof()&&auxCodigo!=codigo)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un producto***\n\n";
                cout<<"Ingresa el c\242digo del producto que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el producto\n\n";
                cout<<"Ingresa el c\242digo del producto: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del producto: ";
                getline(cin,auxNombre);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa el precio del cliente: ";
                getline(cin,auxDomicilio);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la cantidad de unidades del producto: ";
                getline(cin,auxCelular);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la fecha de inscripci\242n del producto: ";
                getline(cin,auxFecha);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxNombre<<"\n"<<auxDomicilio<<"\n"<<auxCelular
                        <<"\n"<<auxFecha<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigo<<"\n"<<nombre<<"\n"<<precio<<"\n"<<cantidad
                        <<"\n"<<Fecha<<"\n";
            }


            getline(lectura,codigo);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::listar()
{
    int i=0;
    ifstream lectura;
    lectura.open("clientes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los productos***\t\t\t\t\n\n";
        getline(lectura,codigo);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,nombre);
            getline(lectura,precio);
            getline(lectura,cantidad);
            getline(lectura,Fecha);
            cout<<"C\242digo: "<<codigo<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Precio: "<<precio<<endl;
            cout<<"Cantidad de unidades: "<<cantidad<<endl;
            cout<<"Fecha de inscripci\242n: "<<Fecha<<endl;
            cout<<"\n\n";
            getline(lectura,codigo);
        }

        if(i==1)
            cout<<"Hay un solo producto registrado\n\n";

        else

            cout<<"Hay un total de "<<i<<" productos registrados \n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}

int main()
{
    system ("color f0");
    menu inicio;
    inicio.menuPrincipal();
    return 0;
}

void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void menu::mostarRegistro(string codigo)
{

    ifstream mostrar;
    mostrar.open("clientes.txt",ios::in);
    getline(mostrar,codigo);
    while(!mostrar.eof())
    {
        getline(mostrar,nombre);
        getline(mostrar,precio);
        getline(mostrar,cantidad);
        getline(mostrar,Fecha);

        if(codigo==codigo)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"C\242digo: "<<codigo<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Precio: "<<precio<<endl;
            cout<<"Cantidad de unidades: "<<cantidad<<endl;
            cout<<"Fecha de inscripci\242n: "<<Fecha<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,codigo);
    }

    mostrar.close();
}
