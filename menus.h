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
    cout<<"-        4) PLATOS POR RESTAURANT"<<endl;
    cout<<"-        5) LISTAR TODOS LOS PLATOS"<<endl;
    cout<<"-        6) ELIMINAR PLATO"<<endl;
    borde();
    cout<<"-        0) VOLVER AL MENU PRINCIPAL"<<endl;
    borde();
}

bool salida(bool &s)
{
    borde();
    cout<<"-         MUCHAS GRACIAS! HASTA LUEGO! " << endl;
    borde();
    s= true;
    system("pause");
    return s;
}

void salidadefault()
{
    borde();
    cout<<"-         OPCION NO VALIDA! "<< endl                  ;
    borde();
    system("pause");

}



#endif // MENUS_H_INCLUDED
