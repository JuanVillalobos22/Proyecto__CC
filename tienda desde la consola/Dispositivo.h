#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H
#include<iostream>
using namespace std;

class Dispositivo{
    protected:
    string codigo;
    string modelo;
    string marca;
    double precio;
    public:
    Dispositivo(){
        codigo="";
        marca="";
        modelo="";
        precio=0.0;
    }
    Dispositivo(string codigo,string modelo, string marca,double precio){
        this->codigo=codigo;
        this->modelo=modelo;
        this->marca=marca;
        this->precio=precio;
    }
    Dispositivo(Dispositivo &dispositivo){
        codigo=dispositivo.codigo;
        modelo=dispositivo.modelo;
        marca=dispositivo.marca;
        precio=dispositivo.precio;
    }
    virtual void modificar_dispositivo(string codigo,string modelo,string marca,double precio){
        this->codigo=codigo;
        this->modelo=modelo;
        this->marca=marca;
        this->precio=precio;
    }
    virtual void modificar_precio(double precio){
        this->precio=precio;
    }
    virtual void mostrar_dispositivo(){
        cout<<"--------------------------------------------"<<endl;
        cout<<"\t\t"<<modelo<<endl;
        cout<<"Codigo del producto: "<<codigo<<endl;
        cout<<"Marca: "<<marca<<endl;
        cout<<"Precio: $"<<precio<<" dolares"<<endl;
    }
    virtual string get_modelo(){
        return modelo;
    }
    virtual string get_marca(){
        return marca;
    }
    virtual string get_codigo(){
        return codigo;
    }
};
#endif
