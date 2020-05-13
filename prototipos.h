#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

//MENUS
void menuprincipal();
void menuplatos();
void menuclientes();
void menupedidos();
bool salida(bool & );
void salidadefault();
void menuconfiguracion();
//PLATO
void plato_main();
int generarid_plato();
bool cargar_plato(plato * );
bool guardar_plato(plato );
void nuevo_plato();
void modificar_plato();
void mostrarplato(plato );
void listarplatoxid();
void listarplatoxrestaurante();
void listarplatos();
void eliminarplato();
int buscarplato(int );
plato leerplato(int );
int cantidadplatos();
//CLIENTE
void cliente_main();
int generarid_cliente();
bool cargar_cliente(cliente * );
bool guardar_cliente(cliente );
void nuevo_cliente();
void modificar_cliente();
void mostrarcliente(cliente );
void listarclientexid();
void listarclientes();
void eliminarcliente();
int buscarcliente(int );
cliente leercliente(int );
int cantidadclientes();
void listarclientes_memdin();
void ordenar_vcl(cliente *, int );
//PEDIDO
void pedido_main();
bool cargar_pedido(pedido *);
bool guardar_pedido(pedido );
void nuevo_pedido();
void modificar_pedido();
void listarpedidoxid();
void listarpedidos();
int generarid_pedido();
int buscarpedido(int );
pedido leerpedido(int );
int cantidadpedidos();
bool sobreescribir_pedido(pedido, int);
//CONFIGURACION
void configuracion_main();
void realizar_bkp();
void restaurar_bkp();
bool bkp_plato();
bool bkp_cliente();
bool bkp_pedido();
bool restaurarbkp_plato();
bool restaurarbkp_cliente();
bool restaurarbkp_pedido();
//VALIDACIONES
bool validar_plato_nombre(char *);
bool validar_plato_costodepreparacion(float );
bool validar_plato_valordeventa(float, float );
bool validar_plato_tiempodepreparacion(int );
bool validar_plato_idrestaurante(int );
bool validar_plato_comisionrestaurante(int );
bool validar_plato_idcategoria(int );
bool validar_cliente_NAD(char *);
bool validar_cliente_mail(char *);
bool validar_cliente_cp(int );
bool validar_fecha(int,int,int );
bool validar_pedido_cantidad(int );
bool validar_pedido_valoracion(int );
bool validar_pedido_estado(int );

#endif // PROTOTIPOS_H_INCLUDED
