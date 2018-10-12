typedef struct
    {
        char dia[3];
        char mes[3];
        char anio[5];
        char isEmpty;

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
        sCategoria categoria;
        int isEmptyJuego;

    }sJuego;

typedef struct{

    int codigoCliente;
    char nombreCliente[51];
    char sexo[2];
    char telefono[21];
    int isEmptyCliente;

}sCliente;

typedef struct{

    int codigoAlquiler; /** Autoincremental **/
    int codJuego;
    int codCliente;
    sFecha fecha;
    int isEmptyAlquiler;

}sAlquiler;


int getInt(char mensaje);
float getFloat(char mensaje);
char getChar(char mensaje);
void getString (char msj[],char input[]);


int esNumerico(char str[]);
int esTelefono(char str[]);
int esSoloLetras(char str[]);
int eEsLetraFoM(char str[]);

int getStringLetras(char msj[],char input[]);
int getStringNumeros(char msj[],char input[]);
int getStringFoM(char msj[], char input[]);
int getStringTelefono(char msj[],char input[]);

