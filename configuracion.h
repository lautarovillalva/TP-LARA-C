#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

bool restaurarbkp_plato()
{
    plato * vec;
    bool val= false, escribio;

    FILE * p;
    p= fopen(ARCHIVO_bkp_PLATOS, "rb");
    if(p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    int cant= ftell(p)/sizeof(plato);
    if(cant==0)
        return false;

    vec= (plato *) malloc(cant *sizeof(plato));
    if(vec==NULL)
        return 0;
    fseek(p, 0, SEEK_SET);
    fread(&vec[0], sizeof(plato), cant, p);
    fclose(p);


    FILE * p1;
    p1 = fopen(ARCHIVO_PLATOS,"wb");
    if(p1 == NULL)
    {
        free(vec);
        return 0;
    }
    escribio = fwrite(&vec[0], sizeof(plato), cant, p1);
    if(escribio==true)
        val= escribio;
    fclose(p1);
    free(vec);
    return val;
}

bool restaurarbkp_cliente()
{
    cliente * vec;
    bool val= false, escribio;

    FILE * p;
    p= fopen(ARCHIVO_bkp_CLIENTES, "rb");
    if(p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    int cant= ftell(p)/sizeof(cliente);
    if(cant==0)
        return false;


    vec= (cliente *) malloc(cant *sizeof(cliente));
    if(vec==NULL)
        return 0;
    fseek(p, 0, SEEK_SET);
    fread(&vec[0], sizeof(cliente), cant, p);
    fclose(p);


    FILE * p1;
    p1 = fopen(ARCHIVO_CLIENTES,"wb");
    if(p1 == NULL)
    {
        free(vec);
        return 0;
    }
    escribio = fwrite(&vec[0], sizeof(cliente), cant, p1);
    if(escribio==true)
        val= escribio;
    fclose(p1);
    free(vec);
    return val;
}

bool restaurarbkp_pedido()
{
    pedido * vec;
    bool val= false, escribio;

    FILE * p;
    p= fopen(ARCHIVO_bkp_PEDIDOS, "rb");
    if(p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    int cant= ftell(p)/sizeof(pedido);
    if(cant==0)
        return false;


    vec= (pedido *) malloc(cant *sizeof(pedido));
    if(vec==NULL)
        return 0;
    fseek(p, 0, SEEK_SET);
    fread(&vec[0], sizeof(pedido), cant, p);
    fclose(p);


    FILE * p1;
    p1 = fopen(ARCHIVO_PEDIDOS,"wb");
    if(p1 == NULL)
    {
        free(vec);
        return 0;
    }
    escribio = fwrite(&vec[0], sizeof(pedido), cant, p1);
    if(escribio==true)
        val= escribio;
    fclose(p1);
    free(vec);
    return val;
}

bool bkp_plato()
{
    plato * vec;
    bool val= false, escribio;
    int cant = cantidadplatos();
    if(cant==0)
        return false;
    vec= (plato *) malloc(cant *sizeof(plato));
    if(vec==NULL)
        return 0;
    FILE * p1;
    p1= fopen(ARCHIVO_PLATOS,"rb");
    if(p1==NULL)
        return 0;
    fread(&vec[0], sizeof(plato), cant, p1);
    fclose(p1);
    FILE * p2;
    p2 = fopen(ARCHIVO_bkp_PLATOS,"wb");
    if(p2 == NULL)
    {
        free(vec);
        return 0;
    }
    escribio = fwrite(&vec[0], sizeof(plato), cant, p2);
    if(escribio==true)
        val= escribio;
    free(vec);
    fclose(p2);
    return val;
}
bool bkp_pedido()
{
    pedido * vec;
    bool val= false, escribio;
    int cant = cantidadpedidos();
    if(cant==0)
        return false;
    vec= (pedido *) malloc(cant *sizeof(pedido));
    if(vec==NULL)
        return 0;
    FILE * p1;
    p1= fopen(ARCHIVO_PEDIDOS,"rb");
    if(p1==NULL)
        return 0;
    fread(&vec[0], sizeof(pedido), cant, p1);
    fclose(p1);
    FILE * p2;
    p2 = fopen(ARCHIVO_bkp_PEDIDOS,"wb");
    if(p2 == NULL)
    {
        free(vec);
        return 0;
    }
    escribio = fwrite(&vec[0], sizeof(pedido), cant, p2);
    if(escribio==true)
        val= escribio;
    fclose(p2);
    free(vec);
    return val;
}
bool bkp_cliente()
{
    cliente * vec;
    bool val= false, escribio;
    int cant = cantidadclientes();
    if(cant==0)
        return false;
    vec= (cliente *) malloc(cant *sizeof(cliente));
    if(vec==NULL)
        return 0;
    FILE * p1;
    p1= fopen(ARCHIVO_CLIENTES,"rb");
    if(p1==NULL)
        return 0;
    fread(&vec[0], sizeof(cliente), cant, p1);
    fclose(p1);
    FILE * p2;
    p2 = fopen(ARCHIVO_bkp_CLIENTES,"wb");
    if(p2 == NULL)
    {
        free(vec);
        return 0;
    }
    escribio = fwrite(&vec[0], sizeof(cliente), cant, p2);
    if(escribio==true)
        val= escribio;
    free(vec);
    fclose(p2);
    return val;
}
void realizar_bkp()
{
    srand(time(NULL));
    int num, numaux;
    num = 1000 + rand() % (10000 - 1000);
    cout<<"-        1) REALIZAR COPIA DE SEGURIDAD"<<endl;
    borde();
    cout<<"- CONFIRMACION DE USUARIO : " << num << endl;
    cout<<"-               CONFIRMAR : ";
    numaux= ingresoEnteroValidado();
    borde();
    if(numaux==num)
    {
        if(bkp_plato()==1)
            cout<<"- ARCHIVO: "<<ARCHIVO_bkp_PLATOS<<"   CREADO CORRECTAMENTE!"<< endl;
        else
            cout<<"- ERROR AL CREAR ARCHIVO: " << ARCHIVO_bkp_PLATOS << endl;
        if(bkp_cliente()==1)
            cout<<"- ARCHIVO: "<<ARCHIVO_bkp_CLIENTES<<" CREADO CORRECTAMENTE!"<< endl;
        else
            cout<<"- ERROR AL CREAR ARCHIVO: " << ARCHIVO_bkp_CLIENTES << endl;
        if(bkp_pedido()==1)
            cout<<"- ARCHIVO: "<<ARCHIVO_bkp_PEDIDOS<< "  CREADO CORRECTAMENTE!"<< endl;
        else
            cout<<"- ERROR AL CREAR ARCHIVO: " << ARCHIVO_bkp_PEDIDOS << endl;
    }
    else
        cout<< "- ERROR DE CONFIRMACION!" <<endl;
    borde();
    borde();
}

void restaurar_bkp()
{
    srand(time(NULL));
    int num, numaux;
    num = 1000 + rand() % (10000 - 1000);
    cout<<"-        2) RESTAURAR COPIA DE SEGURIDAD"<<endl;
    borde();
    cout<<"- CONFIRMACION DE USUARIO : " << num << endl;
    cout<<"-               CONFIRMAR : ";
    numaux= ingresoEnteroValidado();
    borde();
    if(numaux==num)
    {
        if(restaurarbkp_plato()==1)
            cout<<"- ARCHIVO: "<< ARCHIVO_PLATOS << "   RESTAURADO CORRECTAMENTE!"<< endl;
        else
            cout<<"- ERROR AL RESTAURAR ARCHIVO: " << ARCHIVO_PLATOS << endl;
        if(restaurarbkp_cliente()==1)
            cout<<"- ARCHIVO: "<< ARCHIVO_CLIENTES << " RESTAURADO CORRECTAMENTE!"<< endl;
        else
            cout<<"- ERROR AL RESTAURAR ARCHIVO: " << ARCHIVO_CLIENTES << endl;
        if(restaurarbkp_pedido()==1)
            cout<<"- ARCHIVO: "<< ARCHIVO_PEDIDOS << "  RESTAURADO CORRECTAMENTE!"<< endl;
        else
            cout<<"- ERROR AL RESTAURAR ARCHIVO: " << ARCHIVO_PEDIDOS << endl;
    }
    else
        cout<< "- ERROR DE CONFIRMACION!" <<endl;
    borde();
    borde();
}

void configuracion_main()
{
    bool salir=false;
    int opcion;
    while(!salir)
    {
        menuconfiguracion();
        opcion = ingresoEnteroValidado();
        switch(opcion)
        {
        case 1:     //REALIZAR BACKUP
        {
            realizar_bkp();
            system("pause");
        }
        break;
        case 2:     //RESTAURAR BACKUP
        {
            restaurar_bkp();
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

#endif // CONFIGURACION_H_INCLUDED
