
void inicializarJuego(sJuego lista[], int tam);
void inicializarCat(sCategoria lista[], int tam);
void inicializarMarca(sMarca marcas[], int tam);

int buscarJuegoId(sJuego lista[], int tam, int id);
void listarMarcas(sMarca marcas[], int tam);
void listarCategorias(sCategoria cat[], int tam);
void listarJuegos(sJuego jue[], int tamj);

void harcodeoCategorias(sCategoria categ[], int tamC);
void harcodeoJuegos(sJuego lista[], int tamj, sCategoria listaCat[], int tamc, sMarca marcas[], int tamMarca);
void harcodeoMarcas(sMarca marcas[]);


int obtenerIdMarca(sMarca marcas[], int tamMarca, int indice);
void obtenerJuego(sJuego juego[], int tamj, int idj, char desc[]);
int obtenerIdCategoria(sCategoria listaCat[], int tam, int indice);
int obtenerCategoria(sCategoria listaCat[], int tamCat,sJuego juego[], int tamJue, int idJue, char desc[]);
int obtenerMarca(sMarca marcas[], int tamMarca, sJuego juego[], int tamJue, int idJue, char desc[]);

void mostrarJuegosXCategoria(sJuego jue[], int tamj, sCategoria cat[], int tamCat);
void mostrarJuegosSinAlq(sJuego juegos[], int tamJue, sAlquiler alquileres[], int tamAlq);
void mostrarJuegosXMarca(sJuego jue[], int tamj, sMarca marcas[], int tamMar);

