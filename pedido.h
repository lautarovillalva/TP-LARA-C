#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

void nuevo_pedido()
{
    pedido reg;
    if(cargar_pedido(&reg)==1)
    {
        if(guardar_pedido(reg)==1)
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
}
int generarid_pedido()
{
    FILE *p;
    p=fopen(ARCHIVO_PEDIDOS,"ab");
    fseek(p,0,SEEK_END);
    int id=((ftell(p)/sizeof(pedido))+1);
    fclose(p);
    return id;
}
bool cargar_pedido(pedido * reg)
{
    cout<<"-        1) NUEVO PEDIDO"<<endl;
    borde();
    reg->id = generarid_pedido();
    cout<<"- ID AUTO GENERADO                : ";
    cout << reg->id<< endl;
    int pos, idaux;
    plato paux;
    cliente caux;
    cout<<"- CARGAR ID PLATO                 : ";
    idaux= ingresoEnteroValidado();
    pos = buscarplato(idaux);
    if(pos<0)
        return 0;
    paux = leerplato(pos);
    reg->id_plato= paux.id;
    reg->precio= paux.valor_de_venta;
    cout<<"- NOMBRE PLATO                    : "<< strupr(paux.nombre_plato) << endl;
    cout<<"- VALOR DE VENTA                  : $"<<reg->precio<< endl;
    cout<<"- CARGAR ID CLIENTE               : ";
    idaux= ingresoEnteroValidado();
    pos = buscarcliente(idaux);
    if(pos<0)
        return 0;
    caux = leercliente(pos);
    reg->id_cliente=caux.id;
    cout<<"- NOMBRE CLIENTE                  : "<< caux.apellido << ", " << strupr(caux.nombre) << endl;
    cout<<"- CARGAR CANTIDAD                 : ";
    reg->cantidad= ingresoEnteroValidado();
    if(validar_pedido_cantidad(reg->cantidad)!=1)
        return 0;
    cout<<"- CARGAR VALORACION               : ";
    reg->valoracion= ingresoFlotanteValidado();
    if(validar_pedido_valoracion(reg->valoracion)!=1)
        return 0;
    cout<<"- CARGAR DIA DEL PEDIDO           : ";
    reg->fp.dia= ingresoEnteroValidado();
    cout<<"- CARGAR MES DEL PEDIDO           : ";
    reg->fp.mes= ingresoEnteroValidado();
    cout<<"- CARGAR ANO DEL PEDIDO           : ";
    reg->fp.ano= ingresoEnteroValidado();
    if(validar_fecha(reg->fp.dia, reg->fp.mes, reg->fp.ano)!=1)
        return 0;
    reg->estado=1;
    return 1;
}
bool guardar_pedido(pedido reg)
{
    bool guardado=false;
    FILE * p;
    p=fopen(ARCHIVO_PEDIDOS,"ab");
    if(p!=NULL)
    {
        fwrite(&reg,sizeof(pedido), 1, p);
        guardado=true;
    }
    fclose(p);
    return guardado;
}
int cantidadpedidos()
{
    FILE * p;
    p= fopen(ARCHIVO_PEDIDOS, "rb");
    if(p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    int cant= ftell(p)/sizeof(pedido);
    fclose(p);
    return cant;
}
int buscarpedido(int idb)
{
    pedido reg;
    int i=0;
    FILE * p;
    p = fopen(ARCHIVO_PEDIDOS, "rb");
    if (p == NULL)
        return -2;
    while(fread(&reg, sizeof(pedido), 1, p)==1)
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
pedido leerpedido(int pos)
{
    pedido reg;
    FILE * p;
    p = fopen(ARCHIVO_PEDIDOS, "rb");
    if(p == NULL)
    {
        reg.id = -1;
        return reg;
    }
    fseek(p, pos * sizeof(pedido), SEEK_SET);
    fread(&reg, sizeof(pedido), 1, p);
    fclose(p);
    return reg;
}

void mostrarpedido(pedido reg)
{

    borde();
    cout<<"-  ID AUTOGENERADO        "<<": "<< reg.id << endl;
    cout<<"-  ESTADO                 "<<": "<< reg.estado;
    if(reg.estado==1)
    {
        setColor(YELLOW);
        cout<<"> PEDIDO EN CURSO! "<<endl;
    }
    if(reg.estado==2)
    {
        setColor(LIGHTGREEN);
        cout<<"> PEDIDO COMPLETADO! "<<endl;
    }
    if(reg.estado==3)
    {
        setColor(LIGHTRED);
        cout<<"> PEDIDO CANCELADO! "<<endl;
    }
    setColor(WHITE);
    cout<<"-  ID CLIENTE             "<<": "<< reg.id_cliente << endl;
    cout<<"-  ID PLATO               "<<": "<< reg.id_plato << endl;
    cout<<"-  CANTIDAD               "<<": "<< reg.cantidad << endl;
    cout<<"-  PRECIO UNITARIO        "<<": $"<< reg.precio << endl;
    cout<<"-  VALORACION             "<<": "<< reg.valoracion << endl;
    cout<<"-  FECHA DE PEDIDO        "<<": "<< reg.fp.dia<<"/"<< reg.fp.mes<<"/"<<  reg.fp.ano<< endl;
    borde();
}
void modificar_pedido()
{
    cout<<"-        2) MODIFICAR PEDIDO"<<endl;
    borde();
    int idaux;
    cout<<"- ID PEDIDO QUE DESEA MODIFICAR: ";
    idaux= ingresoEnteroValidado();
    bool modificado=false;
    FILE * p;
    pedido reg;
    p = fopen(ARCHIVO_PEDIDOS, "rb+");
    if(p== NULL)
    {
        borde();
        cout<<"- NO SE PUDO ABRIR EL ARCHIVO!"<< endl;
        borde();
        return;
    }
    while(fread(&reg, sizeof(pedido), 1, p)==1)
    {
        if(idaux==reg.id)
        {
            int estado;
            cout<<"- 2) PEDIDO COMPLETADO. "<<endl;
            cout<<"- 3) PEDIDO CANCELADO. "<<endl;
            cout<<"- NUEVO ESTADO DE PEDIDO: ";
//            cout<<"- ";
            estado= ingresoEnteroValidado();
            borde();
            if(validar_pedido_estado(estado)==1)
            {
                reg.estado=estado;
                modificado=true;
                fseek(p, ftell(p)-sizeof(pedido), SEEK_SET);
                fwrite(&reg, sizeof(pedido), 1, p);
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
        cout<<"- ERROR AL MODIFICAR PEDIDO!" << endl;
        borde();
    }
    fclose(p);
}
void listarpedidos()
{
    cout<<"-        4) LISTAR TODOS LOS PEDIDOS"<<endl;
    borde();
    pedido reg;
    int cant =cantidadpedidos(), i;
    for(i=0; i<cant; i++)
    {
        reg =  leerpedido(i);
        if(reg.id>0)
            mostrarpedido(reg);
    }
}
void listarpedidoxid()
{
    cout<<"-        3) LISTAR PEDIDO POR ID"<<endl;
    borde();
    int idb, pos;
    pedido reg;
    cout<<"- ID PEDIDO QUE DESEA LISTAR: ";
    idb= ingresoEnteroValidado();
    pos= buscarpedido(idb);
    if(pos>=0)
    {
        reg = leerpedido(pos);
        mostrarpedido(reg);
    }

}
void pedido_main()
{
    bool salir=false;
    int opcion;
    while(!salir)
    {
        menupedidos();
        opcion = ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:     //NUEVO PEDIDO
        {
            nuevo_pedido();
            system("pause");
        }
        break;
        case 2:     //MODIFICAR PEDIDO
        {
            modificar_pedido();
            system("pause");
        }
        break;
        case 3:     //LISTAR PEDIDO X ID
        {
            listarpedidoxid();
            system("pause");
        }
        break;
        case 4:     //LISTAR PEDIDOS
        {
            listarpedidos();
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

#endif // PEDIDO_H_INCLUDED
