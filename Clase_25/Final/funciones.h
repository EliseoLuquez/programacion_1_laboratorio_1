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
    char nombreMarca[51];

}sMarca;

typedef struct
    {
        int id;
        char descripcion[51];
        int importe;
        int idMarca;
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
    sFecha fecha;
    int isEmpty;

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
int menuCliente();
int menuModificarCliente();
int menuAlquiler();
int menuJuego();
int menuInformes();
int existenClientes(sCliente lista[], int tam);

int compararFecha(sFecha fecha1, sFecha fecha2);


