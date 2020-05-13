#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

// STRUCTS, CONSTANTES
const char ARCHIVO_PLATOS[]= "platos.dat";
const char ARCHIVO_CLIENTES[]= "clientes.dat";
const char ARCHIVO_PEDIDOS[]= "pedidos.dat";

const char ARCHIVO_bkp_PLATOS[]= "platos.bkp";
const char ARCHIVO_bkp_CLIENTES[]= "clientes.bkp";
const char ARCHIVO_bkp_PEDIDOS[]= "pedidos.bkp";

struct fecha
{
    int dia=0;
    int mes=0;
    int ano=0;
};
struct pedido{
    int id=0;
    int id_plato=0;
    int id_cliente=0;
    int cantidad=0;
    float precio=0;
    fecha fp;
    float valoracion=0;
    int estado;

};
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
struct cliente
{
    int id=0;
    char nombre[50]="\0";
    char apellido[50]="\0";
    char mail[50]="\0";
    char domicilio[100]="\0";
    int cp=0;
    fecha nacimiento;
    bool estado= false;
};
void borde()
{
    cout<<"---------------------------------------------------------"<<endl;
}

#endif // DATOS_H_INCLUDED
