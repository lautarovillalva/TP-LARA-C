#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

int generarid_plato()
{
    FILE *p;
    p=fopen(ARCHIVO_PLATOS,"ab");
    fseek(p,0,SEEK_END);
    int id=((ftell(p)/sizeof(plato))+1)*100;
    fclose(p);
    return id;
}
int cantidadplatos()
{

    FILE * p;
    p= fopen(ARCHIVO_PLATOS, "rb");
    if(p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    int cant= ftell(p)/sizeof(plato);
    fclose(p);
    return cant;
}
bool cargar_plato(plato *reg)
{
    cout<<"-        1) NUEVO PLATO"<<endl;
    borde();
    reg->id=generarid_plato();
    cout<<"- ID AUTO GENERADO                : ";
    cout<< reg->id << endl;
    cout<<"- CARGAR NOMBRE                   : ";
    char cadaux[50];
    cargarcadena(cadaux, 50);
    strcpy(cadaux,strupr(cadaux));
    if (validar_plato_nombre(cadaux)!=1)
        return 0;
    strcpy(reg->nombre_plato, cadaux);
    cout<<"- CARGAR COSTO DE PREPARACION     : $";
    reg->costo_de_preparacion= ingresoFlotanteValidado();
    if (validar_plato_costodepreparacion(reg->costo_de_preparacion)!=1)
        return 0;
    cout<<"- CARGAR VALOR DE VENTA           : $";
    reg->valor_de_venta=ingresoFlotanteValidado();
    if (validar_plato_valordeventa(reg->valor_de_venta,reg->costo_de_preparacion) !=1)
        return 0;
    cout<<"- CARGAR MINUTOS DE PREPARACION   : ";
    reg->tiempo_de_preparacion= ingresoEnteroValidado();
    if (validar_plato_tiempodepreparacion(reg->tiempo_de_preparacion)!=1)
        return 0;
    cout<<"- CARGAR ID DE RESTAURANTE        : ";
    reg->id_restaurante= ingresoEnteroValidado();
    if (validar_plato_idrestaurante(reg->id_restaurante) !=1)
        return 0;
    cout<<"- CARGAR COMISION RESTAURANTE     : ";
    reg->comision_restaurante= ingresoEnteroValidado();
    if (validar_plato_comisionrestaurante(reg->comision_restaurante) !=1)
        return 0;
    cout<<"- CARGAR CATEGORIA                : ";
    reg->id_categoria= ingresoEnteroValidado();
    if (validar_plato_idcategoria(reg->id_categoria) !=1)
        return 0;
    reg->estado=true;
    return 1;
    borde();
}
bool guardar_plato(plato reg)
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_PLATOS,"ab");
    if(p!=NULL)
    {
        fwrite(&reg,sizeof(plato), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}

void modificar_plato()
{
    cout<<"-        2) MODIFICAR PLATO"<<endl;
    borde();
    int idaux;
    cout<<"- ID PLATO QUE DESEA MODIFICAR: ";
    idaux= ingresoEnteroValidado();
    bool modificado=false;
    FILE * p;
    plato reg;
    p = fopen(ARCHIVO_PLATOS, "rb+");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(idaux==reg.id && reg.estado==true)
        {
            borde();
            cout<<"- "<< strupr(reg.nombre_plato)<< endl;
            cout<<"- MODIFICAR NUEVO VALOR DE VENTA: $";
            reg.valor_de_venta= ingresoFlotanteValidado();
            cout<<"- MODIFICAR NUEVO TIEMPO DE PREPARACION: ";
            reg.tiempo_de_preparacion= ingresoEnteroValidado();
            borde();
            if(validar_plato_tiempodepreparacion(reg.tiempo_de_preparacion)==1 && validar_plato_valordeventa(reg.valor_de_venta, reg.costo_de_preparacion)==1)
            {
                modificado=true;
                fseek(p, ftell(p)-sizeof(plato), SEEK_SET);
                fwrite(&reg, sizeof(plato), 1, p);
                borde();
                cout<<"- GUARDADO EXITOSO!" <<endl;
                borde();
                break;
            }
        }
    }
    if(modificado==false)
    {
        borde();
        cout<<"- ERROR AL MODIFICAR PLATO!" << endl;
        borde();
    }
    fclose(p);
}
void mostrarplato(plato reg)
{
    borde();
    cout<<"-  ID AUTOGENERADO        "<<": "<< reg.id << endl;
    cout<<"-  ESTADO                 "<<": "<< reg.estado << endl;
    cout<<"-  NOMBRE                 "<<": "<< reg.nombre_plato << endl;
    cout<<"-  COSTO DE PREPARACION   "<<": $"<< reg.costo_de_preparacion<< endl;
    cout<<"-  VALOR DE VENTA         "<<": $"<<reg.valor_de_venta<< endl;
    cout<<"-  MINUTOS DE PREPARACION "<<": "<< reg.tiempo_de_preparacion<< endl;
    cout<<"-  ID DE RESTAURANTE      "<<": "<<reg.id_restaurante<< endl;
    cout<<"-  COMISION RESTAURANTE   "<<": "<<reg.comision_restaurante<< endl;
    cout<<"-  CATEGORIA              "<<": "<<reg.id_categoria << endl;
    borde();

}
void listarplatoxid()
{
    cout<<"-        3) LISTAR PLATO POR ID"<<endl;
    borde();
    bool mostrado=false;
    int idaux;
    cout<<"- ID PLATO QUE DESEA LISTAR: ";
    idaux= ingresoEnteroValidado();
    FILE * p;
    plato reg;
    p = fopen(ARCHIVO_PLATOS, "rb");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(idaux==reg.id && reg.estado==true)
        {
            mostrarplato(reg);
            mostrado=true;
        }
    }
    if(mostrado==false)
    {
        borde();
        cout<<"- ID PLATO NO ENCONTRADO!" << endl;
        borde();
    }
    fclose(p);
}
void listarplatoxrestaurante()
{

    cout<<"-        4) PLATOS POR RESTAURANT"<<endl;
    borde();
    bool mostrado=false;
    int resaux;
    cout<<"- ID RESTAURANTE QUE DESEA LISTAR: ";
    resaux= ingresoEnteroValidado();
    FILE * p;
    plato reg;
    p = fopen(ARCHIVO_PLATOS, "rb");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(resaux==reg.id_restaurante && reg.estado==true)
        {
            mostrarplato(reg);
            mostrado=true;
        }
    }
    if(mostrado==false)
    {
        borde();
        cout<<"- ID RESTAURANTE NO ENCONTRADO!" << endl;
        borde();
    }
    fclose(p);
}
void listarplatos()
{
    cout<<"-        5) LISTAR TODOS LOS PLATOS"<<endl;
    borde();
    FILE * p;
    plato reg;
    p = fopen(ARCHIVO_PLATOS, "rb");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(reg.estado==true)
        {
            mostrarplato(reg);
        }
    }
    fclose(p);
}
void nuevo_plato()
{
    plato reg;
    if(cargar_plato(&reg)==1)
    {
        if(guardar_plato(reg)==1)
        {
            borde();
            cout<<"- GUARDADO EXITOSO!" <<endl;
            borde();
        }
        else
        {
            borde();
            cout<<"- ERROR AL GUARDAR!" <<endl;
            borde();
        }
    }
    else
    {
        borde();
        cout<<"- ERROR AL CARGAR!" << endl;
        borde();
    }
}
void eliminarplato()
{
    cout<<"-        6) ELIMINAR PLATO"<<endl;
    borde();
    bool eliminado= false;
    int idaux;
    plato reg;
    FILE * p;
    p= fopen(ARCHIVO_PLATOS,"rb+");
    if(p==NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    borde();
    cout<<"- ID PLATO A ELIMINAR: ";
    idaux= ingresoEnteroValidado();
    borde();
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(idaux==reg.id && reg.estado==true)
        {
            reg.estado=false;
            eliminado=true;
            fseek(p,ftell(p)-sizeof(plato), SEEK_SET);
            fwrite(&reg, sizeof(plato), 1, p);
            fclose(p);
            borde();
            cout<<"- "<< strupr(reg.nombre_plato) << endl;
            cout<<"- PLATO ELIMINADO!"<< endl;
            borde();
            return;
        }
    }
    if(eliminado==false)
    {
        borde();
        cout<<"- ID PLATO NO ENCONTRADO! " << endl;
        borde();
    }
    fclose(p);
}
int buscarplato(int idb)
{
    plato reg;
    int i=0;
    FILE * p;
    p = fopen(ARCHIVO_PLATOS, "rb");
    if (p == NULL)
        return -2;
    while(fread(&reg, sizeof(plato), 1, p)==1)
    {
        if(reg.id==idb)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
plato leerplato(int pos)
{
    plato reg;
    FILE * p;
    p = fopen(ARCHIVO_PLATOS, "rb");
    if(p == NULL)
    {
        reg.id = -1;
        return reg;
    }
    fseek(p, pos * sizeof(plato), SEEK_SET);
    fread(&reg, sizeof(plato), 1, p);
    fclose(p);
    return reg;
}
void plato_main()
{
    bool salir=false;
    int opcion;
    while(!salir)
    {
        menuplatos();
        opcion = ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:     //NUEVO PATO
        {
            nuevo_plato();
            system("pause");
        }
        break;
        case 2:     //MODIFICAR PLATO
        {
            modificar_plato();
            system("pause");
        }
        break;
        case 3:     //LISTAR PLATO X ID
        {
            listarplatoxid();
            system("pause");
        }
        break;
        case 4:     //LISTAR PLATOS POR RESTAURANTE
        {
            listarplatoxrestaurante();
            system("pause");
        }
        break;
        case 5:     //LISTAR PLATOS
        {
            listarplatos();
            system("pause");
        }
        break;
        case 6:     //ELIMINAR PLATO
        {
            eliminarplato();
            system("pause");
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
}
#endif // PLATOS_H_INCLUDED
