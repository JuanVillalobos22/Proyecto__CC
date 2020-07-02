#ifndef TIENDA_H
#define TIENDA_H
#include "Dispositivo.h"
#include "Laptop.h"
#include "Celular.h"
#include "Licuadora.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

class Tienda{
    string nombre;
    Laptop* laptops[100];
    Celular* celulares[100];
    Licuadora* licuadoras[100]; 
    int act_laptop;
    int act_celular;
    int act_licuadora;
    public:
    Tienda();
    void agregar_dispositivo();
    void eliminar_dispositivo();
    void eliminar_laptop(string);
    void eliminar_celular(string);
    void eliminar_licuadora(string);
    void mostrar_stock();
    void mostrar_laptops();
    void mostrar_celulares();
    void mostrar_licuadoras();
    void buscar_marca(string);
    void buscar_modelo(string);
    void buscar_codigo(string);
    bool codigo_existe(string);
    void vender();

};
Tienda::Tienda(){
    act_laptop=0;
    act_celular=0;
    act_licuadora=0;
    nombre="";
    laptops[act_laptop]=NULL;
    celulares[act_celular]=NULL;
    licuadoras[act_licuadora]=NULL;
}
void Tienda::agregar_dispositivo(){
    string codigo,modelo,marca;
    string RAM,pantalla,memoria,SO;
    string camara;
    string motor;
    double precio;
    int opcion;
    fflush(stdin);
    cout<<"¿Que dispositivo desea agregar?"<<endl;
    cout<<"1.-Laptop"<<endl;
    cout<<"2.-Celular"<<endl;
    cout<<"3.-Licuadora"<<endl;
    cin>>opcion;
    switch(opcion){
    case 1:
        fflush(stdin);
        cout<<"Ingresa el codigo de la laptop: ";
        getline(cin,codigo);
        while(codigo_existe(codigo)){
            cout<<"Codigo ya ingresado anteriormente: "<<endl;
            cout<<"Ingresa el codigo de la laptop: ";
            getline(cin,codigo);
        }
        cout<<"Ingresa el modelo de la laptop: ";
        getline(cin,modelo);
        cout<<"Ingrese la marca: ";
        getline(cin,marca);
        cout<<"Ingrese el precio: ";
        cin>>precio;
        fflush(stdin);
        cout<<"Ingresa la cantidad de RAM: ";
        getline(cin,RAM);
        cout<<"Ingresa el tamanio de la pantalla: ";
        getline(cin,pantalla);
        cout<<"Ingresa la cantidad de memoria: ";
        getline(cin,memoria);
        cout<<"Ingresa el sistema operativo: ";
        getline(cin,SO);
        laptops[act_laptop]=new Laptop;
        laptops[act_laptop]->modificar_dispositivo(codigo,modelo,marca,precio,RAM,pantalla,memoria,SO);
        cout<<"Dispositivo ingresado correctamente"<<endl;
        act_laptop++;
        system("cls");
        break;
    case 2:
        fflush(stdin);
        cout<<"Ingresa el codigo del celular: ";
        getline(cin,codigo);
        while(codigo_existe(codigo)){
            cout<<"Codigo ya ingresado anteriormente: "<<endl;
            cout<<"Ingresa el codigo del celular: ";
            getline(cin,codigo);
        }
        cout<<"Ingresa el modelo del celular: ";
        getline(cin,modelo);
        cout<<"Ingrese la marca: ";
        getline(cin,marca);
        cout<<"Ingrese el precio: ";
        cin>>precio;
        fflush(stdin);
        cout<<"Ingresa el tamanio de la pantalla: ";
        getline(cin,pantalla);
        cout<<"Ingrese la calidad de la camara: ";
        getline(cin,camara);
        celulares[act_celular]=new Celular;
        celulares[act_celular]->modificar_dispositivo(codigo,modelo,marca,precio,camara,pantalla);
        cout<<"Dispositivo ingresado correctamente"<<endl;
        act_celular++;
        system("cls");
        break;
    case 3:
        fflush(stdin);
        cout<<"Ingresa el codigo de la licuadora: ";
        getline(cin,codigo);
        while(codigo_existe(codigo)){
            cout<<"Codigo ya ingresado anteriormente: "<<endl;
            cout<<"Ingresa el codigo de la licuadora: ";
            getline(cin,codigo);
        }
        cout<<"Ingresa el modelo de la licuadora: ";
        getline(cin,modelo);
        cout<<"Ingrese la marca: ";
        getline(cin,marca);
        cout<<"Ingrese el precio: ";
        cin>>precio;
        fflush(stdin);
        cout<<"Ingrese la potencia del motor: ";
        getline(cin,motor);
        licuadoras[act_licuadora]=new Licuadora;
        licuadoras[act_licuadora]->modificar_dispositivo(codigo,modelo,marca,precio,motor);
        cout<<"Dispositivo ingresado correctamente"<<endl;
        act_licuadora++;
        system("cls");
        break;
    default:
        cout<<"Ha ingresado una opcion incorrecta";
        break;
    }
}
void Tienda::eliminar_dispositivo(){
    string eliminar;
    int opcion;
    fflush(stdin);
    cout<<"¿Que dispositivo desea eliminar?"<<endl;
    cout<<"1.-Laptop"<<endl;
    cout<<"2.-Celular"<<endl;
    cout<<"3.-Licuadora"<<endl;
    cin>>opcion;
    switch (opcion){
    case 1:
        mostrar_laptops();
        cout<<"Ingrese el codigo del producto que desea eliminar: ";
        fflush(stdin);
        getline(cin,eliminar);
        eliminar_laptop(eliminar);
        cout<<"Producto eliminado correctamente"<<endl;
        break;
    case 2:
        mostrar_celulares();
        cout<<"Ingrese el codigo del celular que desea eliminar ";
        fflush(stdin);
        getline(cin,eliminar);
        eliminar_celular(eliminar);
        cout<<"Producto eliminado correctamente"<<endl;
        break;
    case 3:
        mostrar_licuadoras();
        cout<<"Ingrese el codigo de la licuadora que desea eliminar: ";
        fflush(stdin);
        getline(cin,eliminar);
        eliminar_licuadora(eliminar);
        cout<<"Producto eliminado correctamente"<<endl;
        break;
    default:
        cout<<"Ha ingresado una opcion incorrecta "<<endl;
        break;
    }
}

void Tienda::eliminar_laptop(string codigo){
    for(int i=0;i<act_laptop;i++){
        if(laptops[i]->get_codigo()==codigo){
            for(int i2;i2<act_laptop;i2++){
                laptops[i2]=laptops[i2+1];
            }
            delete laptops[act_laptop];
            act_laptop--;
        }
    }
}

void Tienda::eliminar_celular(string codigo){
    for(int l=0;l<act_celular;l++){
        if(celulares[l]->get_codigo()==codigo){
            for(int l2;l2<act_celular;l2++){
                celulares[l2]=celulares[l2+1];
            }
            delete celulares[act_celular];
            act_celular--;
        }
    }
}

void Tienda::eliminar_licuadora(string codigo){
    for(int k=0;k<act_licuadora;k++){
        if(licuadoras[k]->get_codigo()==codigo){
            for(int k2;k2<act_licuadora;k2++){
                licuadoras[k2]=licuadoras[k2+1];
            }
            delete licuadoras[act_licuadora];
            act_licuadora--;
        }
    }
}
void Tienda::mostrar_stock(){
    cout<<endl<<endl<<"\tMostrando las laptops disponibles"<<endl;
    for(int i=0;i<act_laptop;i++){
        laptops[i]->mostrar_dispositivo();
    }
    cout<<endl<<endl<<"\tMostrando las celulares disponibles"<<endl;
    for(int l=0;l<act_celular;l++){
        celulares[l]->mostrar_dispositivo();
    }
    cout<<endl<<endl<<"\tMostrando las licuadoras disponibles"<<endl;
    for(int k=0;k<act_licuadora;k++){
        licuadoras[k]->mostrar_dispositivo();
    }
}
void Tienda::mostrar_laptops(){
    cout<<endl<<endl<<"\tMostrando las laptops disponibles"<<endl;
    for(int i=0;i<act_laptop;i++){
        laptops[i]->mostrar_dispositivo();
    }
}
void Tienda::mostrar_celulares(){
    cout<<endl<<endl<<"\tMostrando las celulares disponibles"<<endl;
    for(int l=0;l<act_celular;l++){
        celulares[l]->mostrar_dispositivo();
    }
}
void Tienda::mostrar_licuadoras(){
    cout<<endl<<endl<<"\tMostrando las licuadoras disponibles"<<endl;
    for(int k=0;k<act_licuadora;k++){
        licuadoras[k]->mostrar_dispositivo();
    }
}
void Tienda::buscar_marca(string marca){
    cout<<endl<<endl<<"\tMostrando las laptops disponibles"<<endl;
    for(int i=0;i<act_laptop;i++){
        if(laptops[i]->get_marca()==marca)
            laptops[i]->mostrar_dispositivo();
    }
    cout<<endl<<endl<<"\tMostrando las celulares disponibles"<<endl;
    for(int l=0;l<act_celular;l++){
        if(celulares[l]->get_marca()==marca)
            celulares[l]->mostrar_dispositivo();
    }
    cout<<endl<<endl<<"\tMostrando las licuadoras disponibles"<<endl;
    for(int k=0;k<act_licuadora;k++){
        if(licuadoras[k]->get_marca()==marca)
            licuadoras[k]->mostrar_dispositivo();
    }
}
void Tienda::buscar_modelo(string modelo){
    cout<<endl<<endl<<"\tMostrando las laptops disponibles"<<endl;
    for(int i=0;i<act_laptop;i++){
        if(laptops[i]->get_modelo()==modelo)
            laptops[i]->mostrar_dispositivo();
    }
    cout<<endl<<endl<<"\tMostrando las celulares disponibles"<<endl;
    for(int l=0;l<act_celular;l++){
        if(celulares[l]->get_modelo()==modelo)
            celulares[l]->mostrar_dispositivo();
    }
    cout<<endl<<endl<<"\tMostrando las licuadoras disponibles"<<endl;
    for(int k=0;k<act_licuadora;k++){
        if(licuadoras[k]->get_modelo()==modelo)
            licuadoras[k]->mostrar_dispositivo();
    }
}

void Tienda::buscar_codigo(string codigo){
    bool encontrar=false;
    for(int i=0;i<act_laptop;i++){
        if(laptops[i]->get_codigo()==codigo){
            encontrar=true;
            cout<<"\t\tDispositivo con codigo "<<codigo<<" encontrado: "<<endl;
            laptops[i]->mostrar_dispositivo();
            break;
        }
    }
    if(encontrar==false){
        for(int l=0;l<act_celular;l++){
            if(celulares[l]->get_codigo()==codigo){
                encontrar=true;
                cout<<"\t\tDispositivo con codigo "<<codigo<<" encontrado: "<<endl;
                celulares[l]->mostrar_dispositivo();
                break;
            }
        }
    }
    if(encontrar==false){
        for(int k=0;k<act_licuadora;k++){
            if(licuadoras[k]->get_codigo()==codigo){
                encontrar=true;
                cout<<"\t\tDispositivo con codigo "<<codigo<<" encontrado: "<<endl;
                licuadoras[k]->mostrar_dispositivo();
                break;
            }
        } 
    }
}

bool Tienda::codigo_existe(string codigo){
    for(int i=0;i<act_laptop;i++){
        if(laptops[i]->get_codigo()==codigo){
            return true;
        }
    }
    for(int l=0;l<act_celular;l++){
        if(celulares[l]->get_codigo()==codigo){
            return true;
        }
    }
    for(int k=0;k<act_licuadora;k++){
        if(licuadoras[k]->get_codigo()==codigo){
            return true;
        }
    } 
    return false;
}
void Tienda::vender(){
    int opcion;
    string comprar;
    bool confirmacion;
    cout<<"Ingrese que tipo de dispositivo desea comprar: ";
    cout<<"1.-Laptop"<<endl;
    cout<<"2.-Celular"<<endl;
    cout<<"3.-Licuadora"<<endl;
    cin>>opcion;
    switch(opcion){
    case 1:
        this->mostrar_laptops();
        cout<<"Ingrese el codigo del producto que desea comprar: ";
        fflush(stdin);
        getline(cin,comprar);
        this->buscar_codigo(comprar);
        cout<<"¿Esta seguro que desea comprar este modelo: ?";
        cout<<"Escriba 1 para terminar la compra o 0 para cancelar: ";
        cin>>confirmacion;
        if(confirmacion){
            eliminar_laptop(comprar);
            cout<<"Compra realizada exitosamente"<<endl;
        }
        break;
    case 2:
        this->mostrar_celulares();
        cout<<"Ingrese el codigo del producto que desea comprar: ";
        fflush(stdin);
        getline(cin,comprar);
        this->buscar_codigo(comprar);
        cout<<"¿Esta seguro que desea comprar este modelo: ?";
        cout<<"Escriba 1 para terminar la compra o 0 para cancelar: ";
        cin>>confirmacion;
        if(confirmacion){
            eliminar_celular(comprar);
            cout<<"Compra realizada exitosamente"<<endl;
        }
        break;
    case 3:
        this->mostrar_licuadoras();
        cout<<"Ingrese el codigo del producto que desea comprar: "<<endl;
        fflush(stdin);
        getline(cin,comprar);
        this->buscar_codigo(comprar);
        cout<<"¿Esta seguro que desea comprar este modelo: ?"<<endl;
        cout<<"Escriba 1 para terminar la compra o 0 para cancelar: ";
        cin>>confirmacion;
        if(confirmacion){
            eliminar_licuadora(comprar);
            cout<<"Compra realizada exitosamente"<<endl;
        }
        break;
    default:
        cout<<"Ha ingresado una opcion incorrecta"<<endl;
        break;
    }
}
#endif