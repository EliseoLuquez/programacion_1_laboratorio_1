typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char cuit[50];
}sCliente;

typedef struct
{
    int idVenta;
    int idCliente;
    int cantAfiches;
    char nombreArchImg[50];
    char zona[50];
    char estado[50];
}sVenta;

sCliente* cliente_new();
sCliente* cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* cuitStr);

int cliente_setId(sCliente* this,int id);
int cliente_getId(sCliente* this);

int cliente_setNombre(sCliente* this,char* nombre);
int cliente_getNombre(sCliente* this,char* nombre);

int cliente_setApellido(sCliente* this,char* apellido);
int cliente_getApellido(sCliente* this,char* apellido);

int cliente_setCuit(sCliente* this, char* cuit);
int cliente_getCuit(sCliente* this,char* cuit);

void  cliente_showCliente(sCliente* this);
void  cliente_showClientes(sCliente* this);

int employee_sortByName(void* empleadoA, void* empleadoB);
int employee_sortById(void* empleadoA, void* empleadoB);
int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB);
int employee_sortBySueldo(void* empleadoA, void* empleadoB);
int employee_loadSueldo(void* empleado);

/** Venta **/
sVenta* venta_new();
sVenta* venta_newParametros(char* idVentaStr, char* idClienteStr,char* cantAficheStr ,char* nombreImgStr, char* zonaStr, char* estadoStr);
int venta_setIdVenta(sVenta* this,int idVenta);
int venta_getIdVenta(sVenta* this);
int venta_setIdCliente(sVenta* this,int idCliente);
int venta_getIdCliente(sVenta* this);
int venta_setCantAfiches(sVenta* this,int cantAfiches);
int venta_getCantAfiches(sVenta* this);
int venta_setNombreArchImg(sVenta* this, char* nombreARchImg);
int venta_getNombreArchImg(sVenta* this,char* nombreArchImg);
int venta_setZona(sVenta* this,char* zona);
int venta_getZona(sVenta* this,char* zona);
int venta_setEstado(sVenta* this,char* estado);
int venta_getEstado(sVenta* this,char* estado);


