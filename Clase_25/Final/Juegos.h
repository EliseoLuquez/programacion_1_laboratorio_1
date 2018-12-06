
void juegos_inicializarJuego(sJuego lista[], int tam);
void juegos_inicializarCat(sCategoria lista[], int tam);
void juegos_inicializarMarca(sMarca lista[], int tam);
int juegos_buscarJuegoId(sJuego lista[], int tam, int id);
int juegos_BuscarLibre(sJuego juego[], int tam);

void juegos_listarCategorias(sCategoria cat[], int tam);
void juegos_listarMarca(sMarca marca[], int tamM);
void juegos_listarJuegos(sJuego jue[], int tamj);

void juegos_harcodeoCategorias(sCategoria categ[]);
void juegos_harcodeoJuegos(sJuego listaJ[], sMarca marca[], int tamM, sCategoria listaCat[], int tamc);
void juegos_harcodeoMarca(sMarca marca[], int tamM);


void juegos_obtenerJuego(sJuego juego[], int tamj, int idj, char desc[]);
int juegos_obtenerIdCategoria(sCategoria listaCat[], int tam, int indice);
int juegos_obtenerIdMarca(sMarca marca[], int tamM, int indice);
int juegos_obtenerCategoria(sCategoria listaCat[], int tamCat,sJuego juego[], int tamJue, int idJue, char desc[]);
int juegos_obtenerMarca(sMarca marca[], int tamM, sJuego juego[], int tamJue, int idJue, char nombre[]);

void juegos_mostrarJuegosXCategoria(sJuego jue[], int tamj, sCategoria cat[], int tamCat);
void juegos_mostrarJuegosXMarca(sJuego jue[], int tamj, sMarca marca[], int tamM);


