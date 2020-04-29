#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

//MENUS
void menuprincipal();
void menuplatos();
bool salida(bool & );
void salidadefault();

//PLATO
int generarid_plato();
bool cargar_plato(plato * );
bool guardar_plato(plato * );
void nuevo_plato();
void modificar_plato();
void mostrarplato(plato );
void listarplatoxid();
void listarplatoxrestaurante();
void listarplatos();
void eliminarplato();
void plato_main();

//VALIDACIONES
bool validar_plato_nombre(char *);
bool validar_plato_costodepreparacion(float );
bool validar_plato_valordeventa(float , float );
bool validar_plato_tiempodepreparacion(int );
bool validar_plato_idrestaurante(int );
bool validar_plato_comisionrestaurante(int );
bool validar_plato_idcategoria(int );
#endif // PROTOTIPOS_H_INCLUDED
