#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
#include "menus.h"
#include "validaciones.h"
using namespace rlutil;

const char PLATOS[]= "platos.dat";

struct plato
{
    int id=0;
    char nombre_plato[50]="\0";
    float costo_de_preparacion=0;
    float valor_de_venta=0;
    int tiempo_de_preparacion=0;
    int id_restaurante=0;
    int comision_restaurante=0;
    int id_categoria=0;
    bool estado=false;
};
int generarid_plato()
{
    FILE *p;
    p=fopen(PLATOS,"ab");
    fseek(p,0,SEEK_END);
    int id=(ftell(p)/sizeof(plato))+1;
    return id;
    fclose(p);
}
bool cargar_plato(plato *reg)
{
    bool cargado=false;

    cout<<" CARGAR NOMBRE: ";
    cin.getline(reg->nombre_plato,50);
    cout<<" CARGAR COSTO DE PREPARACION: $";
    cin>> reg->costo_de_preparacion;
    cout<<" CARGAR VALOR DE VENTA: $";
    cin>> reg->valor_de_venta;
    cout<<" CARGAR MINUTOS DE PREPARACION: ";
    cin>> reg->tiempo_de_preparacion;
    cout<<" CARGAR ID DE RESTAURANTE: ";
    cin>> reg->id_restaurante;
    cout<<" CARGAR COMISION RESTAURANTE: ";
    cin>> reg->comision_restaurante;
    cout<<" CARGAR CATEGORIA: ";
    cin>> reg->id_categoria;
    reg->id=generarid_plato();
    cout<<" ID AUTO GENERADO: ";
    cout<< reg->id << endl;
    reg->estado=validar_plato(reg);
    return reg->estado;
}
bool guardar_plato(plato reg)
{
    bool guardado=false;
    FILE * p;
    p=fopen(PLATOS,"ab");
    if(p!=NULL)
    {
        fwrite(&reg,sizeof(plato), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
void nuevo_plato()
{
    plato reg;
    if(cargar_plato(&reg)==1)
    {
        if(guardar_plato(reg)==1)
        {
            cout<<" PLATO GUARDADO!" <<endl;
        }
        else
        {
            cout<<" ERROR AL GUARDAR PLATO!" << endl;
        }
    }
    else
    {
        cout<<" ERROR AL CARGAR PLATO!" << endl;
    }
    system("pause");
}
void modificar_plato()
{
    int idaux;
    cout<<" ID PLATO QUE DESEA MODIFICAR: ;";
    cin>>idaux;
    bool modificado=false;
    FILE * p;
    plato reg;
    p = fopen(PLATOS, "rb+");
    if(p== NULL)
    {
        cout<<" NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(idaux==reg.id)
        {
            cout<< "MODIFICAR NUEVO COSTO DE VENTA: $";
            cin>> reg.valor_de_venta;
            cout<< "MODIFICAR NUEVO TIEMPO DE PREPARACION: ";
            cin>> reg.tiempo_de_preparacion;
            if(validar_plato_tiempodepreparacion(reg.tiempo_de_preparacion)==1 && validar_plato_valordeventa(reg.valor_de_venta, reg.costo_de_preparacion)==1)
            {
                modificado=true;
                fseek(p, ftell(p)-sizeof(plato), SEEK_SET);
                fwrite(&reg, sizeof(plato), 1, p);
            }
        }
    }
    if(modificado==false)
    {
        cout<<" ERROR AL MODIFICAR PLATO!" << endl;
    }
    fclose(p);
}
void mostrarplato(plato reg)
{
    cout<< endl;
    cout<<"  NOMBRE: "<< reg.nombre_plato << endl;
    cout<<"  COSTO DE PREPARACION: $"<< reg.costo_de_preparacion<< endl;
    cout<<"  VALOR DE VENTA: $"<< reg.valor_de_venta<< endl;
    cout<<"  MINUTOS DE PREPARACION: "<< reg.tiempo_de_preparacion<< endl;
    cout<<"  ID DE RESTAURANTE: "<< reg.id_restaurante<< endl;
    cout<<"  COMISION RESTAURANTE: "<< reg.comision_restaurante<< endl;
    cout<<"  CATEGORIA: "<< reg.id_categoria << endl;
    cout<<"  ID AUTOGENERADO: "<<reg.id << endl;
}
void listarplatoxid()
{
    bool mostrado=false;
    int idaux;
    cout<<" ID PLATO QUE DESEA LISTAR: ;";
    cin>>idaux;
    bool modificado=false;
    FILE * p;
    plato reg;
    p = fopen(PLATOS, "rb");
    if(p== NULL)
    {
        cout<<" NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(idaux==reg.id)
        {
            mostrarplato(reg);
            bool mostrado=true;
        }
    }
    if(mostrado==false)
    {
        cout<<" ID PLATO NO ENCONTRADO!" << endl;
    }
    fclose(p);
}
void listarplatoxrestaurante()
{
    bool mostrado=false;
    int resaux;
    cout<<" ID RESTAURANTE QUE DESEA LISTAR: ;";
    cin>>resaux;
    bool modificado=false;
    FILE * p;
    plato reg;
    p = fopen(PLATOS, "rb");
    if(p== NULL)
    {
        cout<<" NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(resaux==reg.id_restaurante)
        {
            mostrarplato(reg);
            bool mostrado=true;
        }
    }
    if(mostrado==false)
    {
        cout<<" ID RESTAURANTE NO ENCONTRADO!" << endl;
    }
    fclose(p);
}
void listarplatos()
{
    FILE * p;
    plato reg;
    p = fopen(PLATOS, "rb");
    if(p== NULL)
    {
        cout<<" NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        mostrarplato(reg);
    }
    fclose(p);
}
void eliminarplato()
{
    bool eliminado= false;
    int idaux;
    plato reg;
    FILE * p;
    p= fopen(PLATOS,"rb+");
    if(p==NULL)
    {
        cout<<" NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(idaux==reg.id)
        {
            reg.estado=false;
            eliminado=true;
            fseek(p, ftell(p)-sizeof(plato),SEEK_SET);
            fwrite(&reg, sizeof(plato), 1, p);
        }
    }
    if(eliminado==false)
    {
        cout<<" ID PLATO NO ENCONTRADO! " << endl;
    }
    fclose(p);
}

void plato_main()
{
    bool salir=false;
    int opcion;
    while(!salir)
    {
        menuplatos();
        cin>>opcion;
        switch(opcion)
        {
        case 1:     //NUEVO PATO
        {
            plato reg;
            if(cargar_plato(&reg)==1)
            {
                if(guardar_plato(reg)==1)
                {
                    cout<<" GUARDADO EXITOSO!" <<endl;
                    system("pause");
                }
                else
                {
                    cout<<" ERROR AL GUARDAR!" <<endl;
                    system("pause");
                }
            }
            else
            {
                cout<<" ERROR AL CARGAR!" << endl;
                system("pause");
            }
        }
        break;
        case 2:     //MODIFICAR PLATO
        {
            modificar_plato();
            system("pause");
        } break;
        case 3:     //LISTAR PLATO X ID
        {
            listarplatoxid();
            system("pause");
        } break;
        case 4:     //LISTAR PLATOS POR RESTAURANTE
        {
            listarplatoxrestaurante();
            system("pause");
        } break;
        case 5:     //LISTAR PLATOS
        {
            listarplatos();
            system("pause");
        } break;
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
}
#endif // PLATOS_H_INCLUDED


























