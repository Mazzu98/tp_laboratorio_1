#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) calloc(sizeof(LinkedList),1);
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = this->size;
    }
    return ret;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL)
    {
        if(ll_len(this) > nodeIndex && nodeIndex > -1)
        {
            if(this->pFirstNode != NULL)
            {
                pNode = this->pFirstNode;
                for(i=0;i<nodeIndex;i++)
                {
                    pNode = pNode->pNextNode;
                }
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int len;
    int ret = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if(this != NULL)
    {
        len = ll_len(this);
        nuevoNodo = (Node*)malloc(sizeof(Node));
        nuevoNodo->pElement = pElement;

        if(nodeIndex < 0 || nodeIndex > len)
        {

        }
        else if(nodeIndex == 0 && len == 0)
        {
            this->pFirstNode = nuevoNodo;
            nuevoNodo->pNextNode = NULL;

            this->size += 1;
            ret = 0;
        }
        else if(nodeIndex > -1)
        {
            if(len == nodeIndex)
            {
                prev = getNode(this,nodeIndex-1);
                prev->pNextNode = nuevoNodo;
                nuevoNodo->pNextNode = NULL;
            }
            else
            {
                if(nodeIndex != 0)
                {
                    next = getNode(this,nodeIndex);
                    nuevoNodo->pNextNode = next;
                    prev = getNode(this,nodeIndex-1);
                    prev->pNextNode = nuevoNodo;
                }
                else
                {
                    next = getNode(this,nodeIndex);
                    nuevoNodo->pNextNode = next;
                    this->pFirstNode = nuevoNodo;
                }
            }
            this->size += 1;
            ret =0;
        }
    }
    return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int len;
    int ret = -1;
    if(this != NULL)
    {
        len = ll_len(this);
        ret = addNode(this,len,pElement);
    }

    return ret;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* ret = NULL;
    Node* nodo;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
        nodo = getNode(this,index);
        if(nodo != NULL)
        {
            ret = nodo->pElement;
        }
    }
    return ret;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int ret = -1;
    Node* actual;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
        actual = getNode(this,index);
        if(actual != NULL)
        {
            actual->pElement = pElement;
            ret = 0;
        }
    }
    return ret;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int ret = -1;
    Node* actual;
    Node* next;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
        if(index == 0)
        {
            next = getNode(this,index+1);
            actual = getNode(this,index);
            free(actual);
            this->pFirstNode = next;

        }
        else
        {
            next = getNode(this,index+1);
            actual = getNode(this,index);
            free(actual);
            actual = getNode(this,index-1);
            actual->pNextNode = next;
        }
        this->size -= 1;
        ret = 0;
    }
    return ret;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int ret = -1;
    int i;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        for(i=0 ;i < len;i++)
        {
            ll_remove(this,0);
        }
        ret = 0;
    }
    return ret;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int ret = -1;

    if(this != NULL)
    {
        ll_clear(this);
        //free(this);
        this = NULL;
        ret = 0;
    }
    return ret;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int ret = -1;
    int i;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            for(i=0;i<len;i++)
            {
                if(ll_get(this,i) == pElement)
                {
                    ret = i;
                    break;
                }
            }
        }
    }
    return ret;
}
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if( ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int ret;
    if(this != NULL)
    {
        ret = addNode(this,index,pElement);
    }
    return ret;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* ret = NULL;
    void* elemento;

    if(this != NULL)
    {
        elemento = ll_get(this,index);
        ll_remove(this,index);
        ret = elemento;
    }
    return ret;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int ret = -1;
    int indexOf;

    if(this != NULL)
    {
        ret = 0;
        indexOf = ll_indexOf(this,pElement);
        if(indexOf != -1)
        {
            ret = 1;
        }
    }
    return ret;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/

int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    void* pElement = NULL;
    int ret = -1;
    int len2;
    int retContains;
    int cont = 0;
    int i;

    if(this != NULL && this2 != NULL)
    {
        ret = 0;
        len2 = ll_len(this2);

        for(i=0; i<len2; i++)
        {
            pElement = ll_get(this2, i);
            retContains = ll_contains(this, pElement);

            if(retContains == 1)
            {
                cont++;
            }
        }

        if(cont == len2)
        {
            ret = 1;
        }
    }

    return ret;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i=from;i<to;i++)
            {
                pElement = ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            cloneArray = ll_subList(this,0,len);
        }
    }
    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

 int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order)
{
    void* element1 = NULL;
    void* element2 = NULL;
    void* auxElement = NULL;
    int ret =-1;
    int len;
    int i, j;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        len = ll_len(this);

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                element1 = ll_get(this, i);
                element2 = ll_get(this, j);

                if(pFunc(element1, element2)>0 && order == 1)
                {
                    auxElement = element1;
                    ll_set(this, i, element2);
                    ll_set(this, j, auxElement);

                }
                else if(pFunc(element1, element2)<0 && order == 0)
                {
                    auxElement = element1;
                    ll_set(this, i, element2);
                    ll_set(this, j, auxElement);
                }
            }
        }
        ret = 0;
    }
    return ret;
}
