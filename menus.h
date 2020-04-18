#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;

void menuprincipal()
{
    cout<<"    MENÚ PRINCIPAL"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1) PLATOS"<<endl;
    cout<<"2) CLIENTES"<<endl;
    cout<<"3) PEDIDOS"<<endl;
    cout<<"4) REPORTES"<<endl;
    cout<<"5) CONFIGURACIÓN"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"0) SALIR DEL PROGRAMA"<<endl<<endl;
}
void menuplatos()
{
    cout<<"    MENÚ PLATOS"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1) NUEVO PLATO"<<endl;
    cout<<"2) MODIFICAR PLATO"<<endl;
    cout<<"3) LISTAR PLATO POR ID"<<endl;
    cout<<"4) PLATOS POR RESTAURANT"<<endl;
    cout<<"4) LISTAR TODOS LOS PLATOS"<<endl;
    cout<<"5) ELIMINAR PLATO"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl<<endl;
}

bool salida(bool &s)
{
    cout<<" MUCHAS GRACIAS! HASTA LUEGO! " << endl;
    system("pause");
    s= true;
    return s;
}

void salidadefault()
{
    cout<<" OPCION NO VALIDA! "<< endl;
    system("pause");
}
#endif // MENUS_H_INCLUDED
