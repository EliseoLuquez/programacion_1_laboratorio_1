
int buscarLibreCliente(sCliente lista[], int tam);
//INICIALIZARLO
void inicializarClientes(sCliente lista[], int tam);
//DAR DE ALTA ALGO
void altaCliente(sCliente cliente[], int tam);
void mostrarCliente(sCliente cliente);
void mostrarClientes(sCliente cliente[], int tam);

void bajaCliente(sCliente lista[], int tam);
int buscarCliente(sCliente lista[], int tam, int id);
void modificarCliente(sCliente lista[], int tam);
void harcodeoClientes(sCliente lista[]);
void obtenerCliente(sCliente cliente[], int tamCli, int idCli, char nombre[]);

void mostrarClientesSinAlq(sCliente clientes[], int tam, sAlquiler alquileres[], int tamAlq);
void mostrarClientesPorSexoyNombre(sCliente cliente[], int tam);
int esMujer(sCliente clientes[], int tam, int idCliente);
int esHombre(sCliente clientes[], int tamCli, int idCliente);

