typedef struct
{
    int id;
    char nombre[128];
    char email[50];
    char sexo[20];
    char pais[50];
    char password[20];
    char ip_Address[50];

}Usuario;

Usuario* usuario_new();
Usuario* usuario_newParametros(char* idStr, char* nombreStr, char* emailStr, char* sexoStr, char* paisStr, char* passwordStr,
                                char* ip_AddressStr);
//void employee_delete();

int usuario_setId(Usuario* this, int id);
int usuario_getId(Usuario* this, int* id);

int usuario_setNombre(Usuario* this, char* nombre);
int usuario_getNombre(Usuario* this, char* nombre);

int usuario_setEmail(Usuario* this, char* email);
int usuario_getEmail(Usuario* this, char* email);

int usuario_setSexo(Usuario* this, char* sexo);
int usuario_getSexo(Usuario* this, char* sexo);

int usuario_setPais(Usuario* this, char* pais);
int usuario_getPais(Usuario* this, char* pais);

int usuario_setPassword(Usuario* this, char* password);
int usuario_getPassword(Usuario* this, char* password);

int usuario_setIp_Address(Usuario* this, char* ip_Address);
int usuario_getIp_Address(Usuario* this, char* ip_Address);

void  usuario_showUsuario(Usuario* this);
void  usuario_showUsuarios(Usuario* this);

int usuario_sortByName(void* usuarioA, void* usuarioB);
int usuario_sortByNaciName(void* usuarioA, void* usuarioB);

/*
int vendedor_sortById(void* vendedor, void* empleadoB);
int vendedor_sortByHsTrabajadas(void* vendedor, void* empleadoB);
int vendedor_sortBySueldo(void* vendedor, void* empleadoB);
float vendedor_loadSueldo(void* vendedor);
int vendedor_niveles(void* vendedor, int* nivel);
*/
