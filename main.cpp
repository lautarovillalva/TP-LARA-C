#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "datos.h"
#include "prototipos.h"
#include "plato.h"
#include "validaciones.h"
#include "menus.h"

int main()
{
    setColor(WHITE);
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
