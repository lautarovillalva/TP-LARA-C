#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

//VALIDACIONES PLATO
bool validar_plato_nombre(char nombre[50])
{
    bool val = true;
    if(strcmp(nombre,"\0")==0)
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
    if(costo<0)
        val= false;
    return val;
}
bool validar_plato_valordeventa(float precio, float costo)
{
    bool val= true;
    if(precio<0 || precio<costo)
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

#endif // VALIDACIONES_H_INCLUDED
