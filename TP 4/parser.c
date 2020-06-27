#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "parser.h"


int parser_fromBin(LinkedList* this,FILE* pArchivo)
{
    int ret = -1;
    eCliente* cliente;

    if(this != NULL)
    {
        if(pArchivo != NULL)
        {
            if(!ll_isEmpty(this))
            {
                ll_clear(this);
            }
            while(!feof(pArchivo))
            {
                cliente = newCliente();
                if(fread(cliente,sizeof(eCliente),1,pArchivo) == 1)
                {
                    ll_add(this,cliente);
                }
            }
            ret = 0;
        }
    }
    return ret;
}
