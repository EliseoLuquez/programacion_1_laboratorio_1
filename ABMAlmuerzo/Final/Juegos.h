
void inicializarJuego(sJuego lista[], int tam);
void inicializarCat(sCategoria lista[], int tam);
int buscarJuegoId(sJuego lista[], int tam, int id);

void listarCategorias(sCategoria cat[], int tam);
void listarJuegos(sJuego jue[], int tamj);

void harcodeoCategorias(sCategoria categ[], int tamC);
void harcodeoJuegos(sJuego lista[], int tamj, sCategoria listaCat[], int tamc);


void obtenerJuego(sJuego juego[], int tamj, int idj, char desc[]);
int obtenerIdCategoria(sCategoria listaCat[], int tam, int indice);
int obtenerCategoria(sCategoria listaCat[], int tamCat,sJuego juego[], int tamJue, int idJue, char desc[]);

void mostrarJuegosXCategoria(sJuego jue[], int tamj, sCategoria cat[], int tamCat);
void mostrarJuegosSinAlq(sJuego juegos[], int tamJue, sAlquiler alquileres[], int tamAlq);

