#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;
#include "menus.h"
#include "platos.h"
#include "validaciones.h"

int main()
{
    bool salir = false;
    int opcion;
    while(!salir)
    {
        menuprincipal();
        cin>>opcion;
        switch(opcion)
        {
        case 1:     //PLATOS
        {
            plato_main();
        } break;
        case 2:     //CLIENTES
        {

        } break;
        case 3:     //PEDIDOS
        {

        } break;
        case 4:     //REPORTES
        {

        } break;
        case 5:     //CONFIGURACION
        {

        } break;
        case 0:     //SALIDA
        {
            salida(salir);
        } break;
        default:    //OPCION NO VALIDA!
        {
            salidadefault();
        } break;

        }
    }
    return 0;
}
