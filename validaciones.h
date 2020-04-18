#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
#include "platos.h"
using namespace rlutil;

bool validar_plato_nombre(char nombre[50])
{
    bool val = true;
    if(strcasecmp(nombre,"\0")==0)
    {
        val=false;
        return val;
    }
    FILE * p;
    plato reg;
    p= fopen(PLATOS, "rb");
    if(p!=NULL)
    {
        while(fread(&reg, sizeof(plato), 1, p)==1)
        {
            if(strcmp(nombre, reg.nombre_plato)==0)
            {
                val=false;
                fclose(p);
                return val;
            }
        }
    }
    fclose(p);
    return val;

}
bool validar_plato_costodepreparacion(float costo)
{
    bool val=true;
    if(costo<0)
        val= false;
    return val;
}
bool validar_plato_valordeventa(float precio, float costo)
{
    bool val= true;
    if(precio<0 || precio<costo)
        val= false;
    return val;
}
bool validar_plato_tiempodepreparacion(int tiempo)
{
    bool val= true;
    if(tiempo< 0)
        val= false;
    return val;
}
bool validar_plato_idrestaurante( int idr)
{
    bool val= true;
    if(idr<0)
        val= false;
    return val;
}
bool validar_plato_comisionrestaurante(int com)
{
    bool val= true;
    if( com<0 || com>100)
        val= false;
    return val;
}
bool validar_plato_idcategoria(int idc)
{
    bool val=true;
    if(idc<0)
        val=false;
    return val;
}
bool validar_plato(plato reg)
{
    bool val= false;
    if(validar_plato_nombre(reg.nombre_plato)==1 && validar_plato_costodepreparacion(reg.costo_de_preparación)==1 && validar_plato_valordeventa(reg.valor_de_venta)==1 && validar_plato_tiempodepreparacion(reg.tiempo_de_preparación)==1 && validar_plato_idrestaurante(reg.id_restaurante)==1 && validar_plato_comisionrestaurante(reg.comisión_restaurante)==1 && validar_plato_idcategoria(reg.id_categoría)==1 &&)
    {
        val=true;
    }
    return val;
}

#endif // VALIDACIONES_H_INCLUDED
