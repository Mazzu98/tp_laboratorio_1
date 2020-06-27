typedef struct
{
    int id;
    char nombre[51];
    char localidad[51];
}eCliente;

eCliente* newCliente();
eCliente* newClienteParametrizado(char*,char*,char*);
int cliente_setId(eCliente* ,int);
int cliente_getId(eCliente* ,int*);
int cliente_setNombre(eCliente* ,char*);
int cliente_getNombre(eCliente* ,char*);
int cliente_setLocalidad(eCliente* ,char*);
int cliente_getLocalidad(eCliente* ,char*);
int cliente_compareById(void*,void*);
int cliente_compareByName(void*,void*);
void cliente_imprimir(eCliente*);
