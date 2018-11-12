typedef struct
    {
        int dia;
        int mes;
        int anio;

    }sFecha;

typedef struct
    {
        int id;
        char descripcion[51];

    }sCategoria;

typedef struct
    {
        int id;
        char descripcion[51];
        float importe;
        int codCategoria;
        int isEmpty;

    }sJuego;

typedef struct{

    int id;
    char nombreCliente[51];
    char sexo;
    char telefono[21];
    int isEmpty;

}sCliente;

typedef struct{

    int id; /** Autoincremental **/
    int idJuego;
    int idCliente;
    int isEmpty;
    sFecha fecha;

}sAlquiler;


int esNumerico(char str[]);
int esTelefono(char str[]);
int esSoloLetras(char str[]);
int eEsLetraFoM(char str);
int esLetraSoN(char str);
void getCharLetra(char msj[],char input);

int getStringLetras(char msj[],char input[]);
int getStringNumeros(char msj[],char input[]);
int getStringFoM(char msj[], char input);
int getStringTelefono(char msj[],char input[]);

int continueSiONo(char msj[],char input);

//MENU
int menu();
int menuModificarCliente();
int existenClientes(sCliente lista[], int tam);




