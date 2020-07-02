#include<iostream>
#include "Tienda.h"
#include "Dispositivo.h"
#include "Laptop.h"
#include "Celular.h"
#include "Licuadora.h"

using namespace std;
int main(){
    Tienda JJJ,eliminar;
    int opcion,opcion2;
    do{
        cout<<".:BIENVENIDO A LA TIENDA VIRTUAL THE THREE JAY"<<endl;
        cout<<"Ingrese el proceso que desee realizar: "<<endl;
        cout<<"1.-Ingresar un producto"<<endl;
        cout<<"2.-Mostrar los productos"<<endl;
        cout<<"3.-Eliminar un producto"<<endl;
        cout<<"4.-Vender un producto"<<endl;
        cout<<"5.-Salir del programa"<<endl;
        cin>>opcion;

        switch (opcion){
        case 1:
            JJJ.agregar_dispositivo();
            break;
        case 2:
            cout<<"¿Que productos quiere que sean mostrados?"<<endl;
            cout<<"1.-Todos"<<endl;
            cout<<"2.-Laptops"<<endl;
            cout<<"3.-Celulares"<<endl;
            cout<<"4.-Licuadoras";
            fflush(stdin);cin>>opcion2;
            switch (opcion2){
            case 1:
                JJJ.mostrar_stock();
                break;
            case 2:
                JJJ.mostrar_laptops();
                break;
            case 3:
                JJJ.mostrar_celulares();
                break;
            case 4:
                JJJ.mostrar_licuadoras();
                break;
            default:
                break;
            }
            break;
        case 3:
            JJJ.eliminar_dispositivo();
            break;
        case 4:
            JJJ.vender();
            break;
        case 5:
            cout<<"Gracias por usar el programa :)"<<endl;
            break;
        default:
            break;
        }
    }while(opcion!=5);
}
/*
televisor
licuadora
laptops
pcs
celulares
tablet
relojes
audifonos (opcional)
consolas
impresoras
*/