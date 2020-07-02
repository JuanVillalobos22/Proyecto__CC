#ifndef CELULAR_H
#define CELULAR_H
#include "Dispositivo.h"
#include<iostream>
using namespace std;
class Celular:public Dispositivo{
    string camara;
    string pantalla;
    public:
    Celular():Dispositivo(){
        this->camara="";
        this->pantalla="";
    }
    Celular(string codigo,string modelo, string marca,double precio,string camara,string pantalla):Dispositivo(codigo,modelo,marca,precio){
		this->camara=camara;
        this->pantalla=pantalla;
    }
    void modificar_dispositivo(string codigo,string modelo, string marca,double precio,string camara,string pantalla){
        Dispositivo::modificar_dispositivo(codigo,modelo,marca,precio);
		this->camara=camara;
        this->pantalla=pantalla;
    }
    void modificar_precio(double precio){
    	Dispositivo::modificar_precio(precio);
    }
    void mostrar_dispositivo(){
    	Dispositivo::mostrar_dispositivo();
    	cout<<"Camara: "<<camara<<endl;
    	cout<<"Pantalla: "<<pantalla<<endl;
    	cout<<"--------------------------------------------"<<endl;
    }
    string get_modelo(){
        return modelo;
    }
    string get_marca(){
        return marca;
    }
};
#endif
