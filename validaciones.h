#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

//VALIDACIONES PLATO
bool validar_plato_nombre(char nombre[50])
{
    bool val = true;
    if(strcmp(nombre,"\0")==0 || strcmp(nombre," ")==0)
    {
        val=false;
        return val;
    }
    FILE * p;
    plato reg;
    p= fopen(ARCHIVO_PLATOS, "rb");
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
    if(costo<=0)
        val= false;
    return val;
}
bool validar_plato_valordeventa(float precio, float costo)
{
    bool val= true;
    if(precio<=0 || precio<costo)
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
    {
        val= false;
    }
    return val;
}
bool validar_plato_comisionrestaurante(int com)
{
    bool val= true;
    if( com<0 || com>100)
    {
        val= false;
    }
    return val;
}
bool validar_plato_idcategoria(int idc)
{
    bool val=true;
    if(idc<0)
    {
        val=false;
    }
    return val;
}
bool validar_cliente_NAD(char * cadena)
{
    bool val= true;
    if (strcmp(cadena, "\0")==0)
        val= false;
    return val;
}
bool validar_cliente_mail(char * mail)
{
    bool val=true;
    if(strcmp(mail,"\0")==0)
        return 0;      //NO ES UNA CADENA VACIA.
    int tam = strlen(mail);
    if(mail[0]=='@' || mail[tam-1]=='@' || mail[tam-1]=='.')
        return 0;      //NO EMPIEZA CON @, NI TERMINA CON PUNTO O @.
    int acon=0, pcon=0;
    for(int i=0; i<tam; i++)
    {
        if((mail[i]>0 && mail[i]<45) || (mail[i]>46 && mail[i]<48) || (mail[i]>57 && mail[i]<64) || (mail[i]>90 && mail[i]<97) || (mail[i]>122))
            return 0;      //SOLO ALFANUMERICOS CON EXCEPCION DEL GUION, ARROBA Y PUNTO.
        if(mail[i]==' ')
            return 0;      //NO CONTIENE ESPACIOS.
        if(mail[i]=='@')
            acon++;
        if(mail[i]=='.')
            pcon++;
    }
    if(acon!=1)
        return 0;       //CONTIENE SOLO UN @.
    if(pcon==0)
        return 0;       //CONTIENE AL MENOS UN PUNTO.
    char * pch;
    pch = strstr(mail,"..");
    if(pch!=NULL)
        return 0;     //NO CONTIENE DOS PUNTOS SEGUIDOS.
    return val;
}
bool validar_fecha(int d, int m, int a)
{
    bool val= true;
    int dias_mes[] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    if(((a%4==0) && (a%100!=0)) || (a%400==0))
        dias_mes[1]++;
    if(m < 1 || m > 12)
        return false;
    if(d <= 0 || d > dias_mes[m-1])
        return false;
    return val;
}
bool validar_cliente_cp(int codp)
{
    bool val= true;
    if(codp<1000 || codp>9999)
        val= false;
    return val;
}
bool validar_pedido_cantidad(int cant)
{
    bool val= true;
    if(cant<0)
        val = false;
    return val;
}
bool validar_pedido_valoracion(int valo)
{
    bool val= true;
    if(valo<0 || valo>10)
        val= false;
    return val;
}
bool validar_pedido_estado(int estado)
{
    bool val= true;
    if(estado<1 || estado>3)
        return false;
    return val;
}
int ingresoEnteroValidado()
{
    int op;
    while(!(cin>>op))
    {
        cout<<"- ERROR, SE ESPERA UN VALOR NUMERICO: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return op;
}
float ingresoFlotanteValidado()
{
    float op;
    while(!(cin>>op))
    {
        cout<<"- ERROR, SE ESPERA UN VALOR NUMERICO: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return op;
}
void cargarcadena(char * cad, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        cad[i]=cin.get();
        if(cad[i]=='\n')
            break;
    }
    cad[i]='\0';
    fflush(stdin);
}
#endif // VALIDACIONES_H_INCLUDED
