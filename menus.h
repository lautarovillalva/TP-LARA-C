#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void menuprincipal()
{
    system("cls");
    borde();
    cout<<"-            MENU PRINCIPAL"<<endl;
    borde();
    cout<<"-        1) PLATOS"<<endl;
    cout<<"-        2) CLIENTES"<<endl;
    cout<<"-        3) PEDIDOS"<<endl;
    cout<<"-        4) REPORTES"<<endl;
    cout<<"-        5) CONFIGURACION"<<endl;
    borde();
    cout<<"-        0) SALIR DEL PROGRAMA"<<endl;
    borde();
    borde();
}
void menuplatos()
{
    system("cls");
    borde();
    cout<<"-            MENU PLATOS"<<endl;
    borde();
    cout<<"-        1) NUEVO PLATO"<<endl;
    cout<<"-        2) MODIFICAR PLATO"<<endl;
    cout<<"-        3) LISTAR PLATO POR ID"<<endl;
    cout<<"-        4) LISTAR PLATOS POR RESTAURANT"<<endl;
    cout<<"-        5) LISTAR TODOS LOS PLATOS"<<endl;
    cout<<"-        6) ELIMINAR PLATO"<<endl;
    borde();
    cout<<"-        0) VOLVER AL MENU PRINCIPAL"<<endl;
    borde();
    borde();
}
void menuclientes()
{
    system("cls");
    borde();
    cout<<"-            MENU CLIENTES"<<endl;
    borde();
    cout<<"-        1) NUEVO CLIENTE"<<endl;
    cout<<"-        2) MODIFICAR CLIENTE"<<endl;
    cout<<"-        3) LISTAR CLIENTE POR ID"<<endl;
    cout<<"-        4) LISTAR TODOS LOS CLIENTES"<<endl;
    cout<<"-        5) ELIMINAR CLIENTE"<<endl;
    borde();
    cout<<"-        0) VOLVER AL MENU PRINCIPAL"<<endl;
    borde();
    borde();
}
void menupedidos()
{
    system("cls");
    borde();
    cout<<"-            MENU PEDIDOS"<<endl;
    borde();
    cout<<"-        1) NUEVO PEDIDO"<<endl;
    cout<<"-        2) MODIFICAR PEDIDO"<<endl;
    cout<<"-        3) LISTAR PEDIDO POR ID"<<endl;
    cout<<"-        4) LISTAR TODOS LOS PEDIDOS"<<endl;
    borde();
    cout<<"-        0) VOLVER AL MENU PRINCIPAL"<<endl;
    borde();
    borde();
}
void menuconfiguracion()
{
    system("cls");
    borde();
    cout<<"-            MENU CONFIGURACION"<<endl;
    borde();
    cout<<"-        1) REALIZAR COPIA DE SEGURIDAD"<<endl;
    cout<<"-        2) RESTAURAR COPIA DE SEGURIDAD"<<endl;
    borde();
    cout<<"-        0) VOLVER AL MENU PRINCIPAL"<<endl;
    borde();
    borde();
}
bool salida(bool &s)
{
    borde();
    cout<<"-         MUCHAS GRACIAS! HASTA LUEGO! " << endl;
    borde();
    borde();
    s= true;
    system("pause");
    return s;
}

void salidadefault()
{
    borde();
    cout<<"-         OPCION NO VALIDA! "<< endl;
    borde();
    borde();
    system("pause");

}



#endif // MENUS_H_INCLUDED
