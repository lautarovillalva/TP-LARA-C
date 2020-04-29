#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

// STRUCTS, CONSTANTES
const char ARCHIVO_PLATOS[]= "platos.dat";

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
// FUNCIONES
void cargarcadena(char * cad, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam;i++)
    {
        cad[i]=cin.get();
        if(cad[i]=='\n') break;
    }
    cad[i]='\0';
    fflush(stdin);
}
void borde()
{
        cout<<"---------------------------------------------------------"<<endl;
}
#endif // DATOS_H_INCLUDED
