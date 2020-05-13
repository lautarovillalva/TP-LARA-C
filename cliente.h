#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

int generarid_cliente()
{
    FILE *p;
    p=fopen(ARCHIVO_CLIENTES,"ab");
    fseek(p,0,SEEK_END);
    int id=((ftell(p)/sizeof(cliente))+1);
    fclose(p);
    return id;
}
bool cargar_cliente(cliente * reg)
{
    cout<<"-        1) NUEVO CLIENTE"<<endl;
    borde();
    reg->id=generarid_cliente();
    cout<<"- ID AUTO GENERADO          : ";
    cout<< reg->id << endl;
    cout<<"- CARGAR APELLIDO           : ";
    char cadaux[50];
    cargarcadena(cadaux, 50);
    if(validar_cliente_NAD(cadaux)!=1)
        return 0;
    strcpy(reg->apellido,strupr(cadaux));
    cout<<"- CARGAR NOMBRE             : ";
    cargarcadena(reg->nombre, 50);
    if(validar_cliente_NAD(reg->nombre)!=1)
        return 0;
    cout<<"- CARGAR MAIL               : ";
    cargarcadena(reg->mail, 50);
    if(validar_cliente_mail(reg->mail)!=1)
        return 0;
    cout<<"- CARGAR DOMICILIO          : ";
    cargarcadena(reg->domicilio, 100);
    if(validar_cliente_NAD(reg->domicilio)!=1)
        return 0;
    cout<<"- CARGAR CODIGO POSTAL      : ";
    reg->cp= ingresoEnteroValidado();
    if(validar_cliente_cp(reg->cp)!=1)
        return 0;
    cout<<"- CARGAR DIA DE NACIMIENTO  : ";
    reg->nacimiento.dia= ingresoEnteroValidado();
    cout<<"- CARGAR MES DE NACIMIENTO  : ";
    reg->nacimiento.mes= ingresoEnteroValidado();
    cout<<"- CARGAR ANO DE NACIMIENTO  : ";
    reg->nacimiento.ano= ingresoEnteroValidado();
    if(validar_fecha(reg->nacimiento.dia, reg->nacimiento.mes, reg->nacimiento.ano)!=1)
        return 0;
    reg->estado=true;
    return 1;
    borde();
}
bool guardar_cliente(cliente reg)
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_CLIENTES,"ab");
    if(p!=NULL)
    {
        fwrite(&reg,sizeof(cliente), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
void nuevo_cliente()
{
    cliente reg;
    if(cargar_cliente(&reg)==1)
    {
        if(guardar_cliente(reg)==1)
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

void modificar_cliente()
{
    cout<<"-        2) MODIFICAR CLIENTE"<<endl;
    borde();
    int idaux;
    cout<<"- ID CLIENTE QUE DESEA MODIFICAR: ";
    idaux= ingresoEnteroValidado();
    bool modificado=false;
    FILE * p;
    cliente reg;
    p = fopen(ARCHIVO_CLIENTES, "rb+");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(cliente), 1, p)==1)
    {
        if(idaux==reg.id && reg.estado==true)
        {
            borde();
            cout<<"-  APELLIDO Y NOMBRE      "<<": "<<strupr(reg.apellido)   << ", " <<strupr(reg.nombre) << endl;
            cout<<"- MODIFICAR NUEVO DOMICILIO       : ";
            cargarcadena(reg.domicilio,100);
            borde();
            if(validar_cliente_NAD(reg.domicilio)==1)
            {
                modificado=true;
                fseek(p, ftell(p)-sizeof(cliente), SEEK_SET);
                fwrite(&reg, sizeof(cliente), 1, p);
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
        cout<<"- ERROR AL MODIFICAR CLIENTE!" << endl;
        borde();
    }
    fclose(p);
}
void mostrarcliente(cliente reg)
{
    borde();
    cout<<"-  ID AUTOGENERADO        "<<": "<< reg.id << endl;
    cout<<"-  ESTADO                 "<<": "<< reg.estado << endl;
    cout<<"-  APELLIDO Y NOMBRE      "<<": "<<strupr(reg.apellido)   << ", " <<strupr(reg.nombre) << endl;
    cout<<"-  DOMICILIO              "<<": "<< strupr(reg.domicilio) << endl;
    cout<<"-  MAIL                   "<<": "<< strupr(reg.mail) << endl;
    cout<<"-  CODIGO POSTAL          "<<": "<< reg.cp << endl;
    cout<<"-  FECHA DE NACIMIENTO    "<<": "<< reg.nacimiento.dia<<"/"<<reg.nacimiento.mes<<"/"<< reg.nacimiento.ano << endl;
    borde();
}
void listarclientexid()
{
    cout<<"-        3) LISTAR CLIENTE POR ID"<<endl;
    borde();
    bool mostrado=false;
    int idaux;
    cout<<"- ID CLIENTE QUE DESEA LISTAR: ";
    idaux= ingresoEnteroValidado();
    FILE * p;
    cliente reg;
    p = fopen(ARCHIVO_CLIENTES, "rb");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(cliente), 1, p)==1)
    {
        if(idaux==reg.id && reg.estado==true)
        {
            mostrarcliente(reg);
            mostrado=true;
        }
    }
    if(mostrado==false)
    {
        borde();
        cout<<"- ID CLIENTE NO ENCONTRADO!" << endl;
        borde();
    }
    fclose(p);
}
void listarclientes()
{
    cout<<"-        4) LISTAR TODOS LOS CLIENTES"<<endl;
    borde();
    FILE * p;
    cliente reg;
    p = fopen(ARCHIVO_CLIENTES, "rb");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(cliente), 1, p)==1)
    {
        if(reg.estado==true)
        {
            mostrarcliente(reg);
        }
    }
    fclose(p);
}
void eliminarcliente()
{
    cout<<"-        5) ELIMINAR CLIENTE"<<endl;
    borde();
    bool eliminado= false;
    int idaux;
    cliente reg;
    FILE * p;
    p= fopen(ARCHIVO_CLIENTES,"rb+");
    if(p==NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    borde();
    cout<<"- ID CLIENTE A ELIMINAR: ";
    idaux= ingresoEnteroValidado();
    borde();
    while(fread(&reg, sizeof(cliente), 1, p)==1)
    {
        if(idaux==reg.id && reg.estado==true)
        {
            reg.estado=false;
            eliminado=true;
            fseek(p,ftell(p)-sizeof(cliente), SEEK_SET);
            fwrite(&reg, sizeof(cliente), 1, p);
            fclose(p);
            borde();
            cout<<"- "<< strupr(reg.nombre) << " "<< strupr(reg.apellido)<< endl;
            cout<<"- CLIENTE ELIMINADO!"<< endl;
            borde();
            return;
        }
    }
    if(eliminado==false)
    {
        borde();
        cout<<"- ID CLIENTE NO ENCONTRADO! " << endl;
        borde();
    }
    fclose(p);
}
int buscarcliente(int idb)
{
    cliente reg;
    int i=0;
    FILE * p;
    p = fopen(ARCHIVO_CLIENTES, "rb");
    if (p == NULL)
        return -2;
    while(fread(&reg, sizeof(cliente), 1, p)==1)
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
int cantidadclientes()
{
    FILE * p;
    p= fopen(ARCHIVO_CLIENTES, "rb");
    if(p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    int cant= ftell(p)/sizeof(cliente);
    fclose(p);
    return cant;
}
void ordenar_vcl(cliente * v, int tam)
{
    int i, j, posmin;
    cliente aux;
    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
            if(v[j].apellido[0]<v[posmin].apellido[0])
                posmin=j;
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}
void listarclientes_memdin()
{
    cout<<"-        4) LISTAR TODOS LOS CLIENTES"<<endl;
    borde();
    int cant = cantidadclientes();
    cliente *vec;
    vec= (cliente *) malloc(cant *sizeof(cliente));
    if(vec==NULL)
    {
        cout<<"- NO HAY MEMORIA DISPONIBLE! " <<endl;
        return;
    }
    FILE * p;
    p= fopen(ARCHIVO_CLIENTES,"rb");
    if(p==NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    fread(&vec[0], sizeof(cliente), cant, p);
    fclose(p);
    ordenar_vcl(vec, cant);
    for(int i=0; i<cant; i++)
    {
        if(vec[i].estado==1)
            mostrarcliente(vec[i]);
    }
    free(vec);
}
cliente leercliente(int pos)
{
    cliente reg;
    FILE * p;
    p = fopen(ARCHIVO_CLIENTES, "rb");
    if(p == NULL)
    {
        reg.id = -1;
        return reg;
    }
    fseek(p, pos * sizeof(cliente), SEEK_SET);
    fread(&reg, sizeof(cliente), 1, p);
    fclose(p);
    return reg;
}
void cliente_main()
{
    bool salir=false;
    int opcion;
    while(!salir)
    {
        menuclientes();
        opcion = ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:     //NUEVO CLIENTE
        {
            nuevo_cliente();
            system("pause");
        }
        break;
        case 2:     //MODIFICAR CLIENTE
        {
            modificar_cliente();
            system("pause");
        }
        break;
        case 3:     //LISTAR CLIENTE X ID
        {
            listarclientexid();
            system("pause");
        }
        break;
        case 4:     //LISTAR CLIENTES
        {
//            listarclientes();
            listarclientes_memdin();
            system("pause");
        }
        break;
        case 5:     //ELIMINAR CLIENTE
        {
            eliminarcliente();
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
        }   // } SWICH
    }       // } WHILE
}


#endif // CLIENTE_H_INCLUDED
