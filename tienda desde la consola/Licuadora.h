#ifndef LICUADORA_H
#define LICUADORA_H
#include "Dispositivo.h"
#include<iostream>
using namespace std;
class Licuadora:public Dispositivo{
    string motor;
    public:
    Licuadora():Dispositivo(){
      this->motor="";
    }
    Licuadora(string codigo,string modelo, string marca,double precio,string motor):Dispositivo(codigo,modelo,marca,precio){
		  this->motor=motor;
    }
    void modificar_dispositivo(string codigo,string modelo, string marca,double precio,string motor){
      Dispositivo::modificar_dispositivo(codigo,modelo,marca,precio);
		  this->motor=motor;
    }
    void modificar_precio(double precio){
    	Dispositivo::modificar_precio(precio);
    }
    void mostrar_dispositivo(){
    	Dispositivo::mostrar_dispositivo();
    	cout<<"Motor: "<<motor<<endl;
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
