typedef struct{

    int  componenteId;
    char nombre[50];
    char base[50];

}sComponente;

typedef struct{

    int idColor;
    char nombre[50];
    int idComponente;
    int cantidad;

}sColor;


sColor* color_new();
int color_newParameteros(char* idColor, char* nombre, char* idComponente, char* cantidad);
int color_setIdColor(sColor* this, int idColor);
int color_getIdColor(sColor* this, int* idColor);
int color_setNombre(sColor* this, char* nombre);
char* color_getNombre(sColor* this);
int color_setIdComponente(sColor* this, int componente);
int color_getIdComponente(sColor* this, int* componente);
int color_setCantidad(sColor* this, int cantidad);
int color_getCantidad(sColor* this, int* cantidad);
void  color_showColor(sColor* this);
void  color_showColores(sColor* this);



sComponente* componente_new();
int componente_newParameteros(char* componenteId, char* nombre, char* base);
int componente_setComponenteId(sComponente* this, int componenteId);
int componente_getComponenteId(sComponente* this, int* componenteId);
int componente_setNombre(sComponente* this, char* nombre);
char* componente_getNombre(sComponente* this);
int componente_setBase(sComponente* this, char* base);
char* componente_getBase(sComponente* this);
void  componente_showComponente(sComponente* this);
void  componente_showComponentes(sComponente* this);
int componente_findCompById(sComponente* this, int len, int id);
