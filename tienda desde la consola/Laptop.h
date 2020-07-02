#ifndef LAPTOP_H
#define LAPTOP_H
#include "Dispositivo.h"
#include<iostream>
using namespace std;
class Laptop:public Dispositivo{
    string RAM;
    string pantalla;
    string memoria;
    string SO;
    public:
    Laptop():Dispositivo(){
        this->RAM="";
        this->pantalla="";
        this->memoria="";
        this->SO=""; 
    }
    Laptop(string codigo,string modelo, string marca,double precio,string RAM,string pantalla,string memoria,string SO):Dispositivo(codigo,modelo,marca,precio){
        this->RAM=RAM;
        this->pantalla=pantalla;
        this->memoria=memoria;
        this->SO=SO;
    }
    void modificar_dispositivo(string codigo,string modelo, string marca,double precio,string RAM,string pantalla,string memoria,string SO){
        Dispositivo::modificar_dispositivo(codigo,modelo,marca,precio);
		this->RAM=RAM;
        this->pantalla=pantalla;
        this->memoria=memoria;
        this->SO=SO;
    }
    void modificar_precio(double precio){
    	Dispositivo::modificar_precio(precio);
    }
    void mostrar_dispositivo(){
    	Dispositivo::mostrar_dispositivo();
    	cout<<"RAM: "<<RAM<<endl;
    	cout<<"Pantalla: "<<pantalla<<endl;
    	cout<<"Memoria: "<<memoria<<endl;
    	cout<<"SO: "<<SO<<endl;
    	cout<<"--------------------------------------------"<<endl;
    }
    string get_modelo(){
        return modelo;
    }
    string get_marca(){
        return marca;
    }
    string get_codigo(){
        return codigo;
    }
};
#endif