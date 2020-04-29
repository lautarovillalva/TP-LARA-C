#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

int generarid_plato()
{
    FILE *p;
    p=fopen(ARCHIVO_PLATOS,"ab");
    fseek(p,SEEK_SET,SEEK_END);
    int id=(ftell(p)/sizeof(plato))+1000;
    fclose(p);
    return id;
}
bool cargar_plato(plato *reg)
{
    borde();
    reg->id=generarid_plato();
    cout<<"- ID AUTO GENERADO                : ";
    cout<< reg->id << endl;
    cout<<"- CARGAR NOMBRE                   : ";
    cargarcadena(reg->nombre_plato, 50);
    if (validar_plato_nombre(reg->nombre_plato)!=1)
        return 0;
    cout<<"- CARGAR COSTO DE PREPARACION     : $";
    cin>> reg->costo_de_preparacion;
    if (validar_plato_costodepreparacion(reg->costo_de_preparacion)!=1)
        return 0;
    cout<<"- CARGAR VALOR DE VENTA           : $";
    cin>> reg->valor_de_venta;
    if (validar_plato_valordeventa(reg->valor_de_venta,reg->costo_de_preparacion) !=1)
        return 0;
    cout<<"- CARGAR MINUTOS DE PREPARACION   : ";
    cin>> reg->tiempo_de_preparacion;
    if (validar_plato_tiempodepreparacion(reg->tiempo_de_preparacion)!=1)
        return 0;
    cout<<"- CARGAR ID DE RESTAURANTE        : ";
    cin>> reg->id_restaurante;
    if (validar_plato_idrestaurante(reg->id_restaurante) !=1)
        return 0;
    cout<<"- CARGAR COMISION RESTAURANTE     : ";
    cin>> reg->comision_restaurante;
    if (validar_plato_comisionrestaurante(reg->comision_restaurante) !=1)
        return 0;
    cout<<"- CARGAR CATEGORIA                : ";
    cin>> reg->id_categoria;
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
void nuevo_plato()
{
    plato reg;
    if(cargar_plato(&reg)==1)
    {
        if(guardar_plato(reg)==1)
        {
            borde();
            cout<<"- PLATO GUARDADO!" <<endl;
            borde();
        }
        else
        {
            borde();
            cout<<"- ERROR AL GUARDAR PLATO!" << endl;
            borde();
        }
    }
    else
    {
        borde();
        cout<<"- ERROR AL CARGAR PLATO!" << endl;
        borde();
    }
    system("pause");
}
void modificar_plato()
{
    borde();
    int idaux;
    cout<<"- ID PLATO QUE DESEA MODIFICAR: ";
    cin>>idaux;
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
            cout<<"- MODIFICAR NUEVO COSTO DE VENTA: $";
            cin>> reg.valor_de_venta;
            cout<<"- MODIFICAR NUEVO TIEMPO DE PREPARACION: ";
            cin>> reg.tiempo_de_preparacion;
            borde();
            if(validar_plato_tiempodepreparacion(reg.tiempo_de_preparacion)==1 && validar_plato_valordeventa(reg.valor_de_venta, reg.costo_de_preparacion)==1)
            {
                modificado=true;
                fseek(p, ftell(p)-sizeof(plato), SEEK_SET);
                fwrite(&reg, sizeof(plato), 1, p);
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
    cout<<"-  NOMBRE                 "<<": "<< strupr(reg.nombre_plato) << endl;
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
    borde();
    bool mostrado=false;
    int idaux;
    cout<<"- ID PLATO QUE DESEA LISTAR: ";
    cin>>idaux;
    bool modificado=false;
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
    borde();
    bool mostrado=false;
    int resaux;
    cout<<"- ID RESTAURANTE QUE DESEA LISTAR: ";
    cin>>resaux;
    bool modificado=false;
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
void eliminarplato()
{
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
    cin>>idaux;
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
                    borde();
                    cout<<"- GUARDADO EXITOSO!" <<endl;
                    borde();
                    system("pause");
                }
                else
                {
                    borde();
                    cout<<"- ERROR AL GUARDAR!" <<endl;
                    borde();
                    system("pause");
                }
            }
            else
            {
                borde();
                cout<<"- ERROR AL CARGAR!" << endl;
                borde();
                system("pause");
            }
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
