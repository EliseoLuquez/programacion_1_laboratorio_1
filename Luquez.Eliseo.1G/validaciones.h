
typedef struct
    {
        int dia;
        int mes;
        int anio;
        int isEmpty;

    }sFecha;

typedef struct
    {
        int idCat;
        char descripcion[51];
        int isEmptyCat;

    }sCategoria;

typedef struct
    {
        int codigoJuego;
        char descripcion[51];
        float importe;
        sCategoria info_categtoria;
        int isEmptyJuego;

    }sJuego;

typedef struct{

    int codigoCliente;
    char nombreCliente[51];
    char sexo;
    char descripcion[51];
    char telefono[20];
    int isEmptyCliente;

}sCliente;

typedef struct{

    int CodigoAlquiler; /** Autoincremental **/
    sJuego cod_Juego;
    sCliente cod_Cliente;
    sFecha fecha;
    int isEmptyAlquiler;

}sAlquiler;


int options();
void initCliente(sCliente* list, int len);
int searchEmpty(sCliente* list, int len);
int addCliente(sCliente* list, int len);
void printCliente(sCliente list);
void printClientes(sCliente* list, int len);
int findClienteById(sCliente* list, int len, int id);
void modifyCliente(sCliente* list, int len);
int removeCliente(sCliente* list, int len);
int sortCliente(sCliente* list, int len, int order);

void getString(char* message, char* input);
char getChar(char* message);
int esNumerico(char* str);
int esTelefono(char* str);
int esSoloLetras(char* str);
int esSoloLetrasFM(char* str);
int getStringNumeros(char* message ,char* input);
int getStringLetras(char* message ,char* input);
int getStringLetrasFM(char* message ,char* input);
int validarNumeroFlotante(char str[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getStringNumerosTelefono(char* message ,char* input);
void harcodeoCliente(sCliente* list);


