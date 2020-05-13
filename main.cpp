#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <time.h>
#include "datos.h"
#include "prototipos.h"
#include "validaciones.h"
#include "plato.h"
#include "cliente.h"
#include "pedido.h"
#include "configuracion.h"
#include "menus.h"

int main()
{
    bool salir = false;
    int opcion;
    while(!salir)
    {
        setColor(WHITE);
        menuprincipal();
        opcion= ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:     //PLATOS
        {
            plato_main();
        }
        break;
        case 2:     //CLIENTES
        {
            cliente_main();
        }
        break;
        case 3:     //PEDIDOS
        {
            pedido_main();
        }
        break;
        case 4:     //REPORTES
        {

        } break;
        case 5:     //CONFIGURACION
        {
            configuracion_main();
        }
        break;
        case 0:     //SALIDA
        {
            salida(salir);
        }
        break;
        default:    //OPCION NO VALIDA!
        {
            salidadefault();
        }
        break;

        }
    }
    return 0;
}
