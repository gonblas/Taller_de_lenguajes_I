#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int data;
    struct nodo *next;
    int size;
} List;

void inicializar(List** l);
void eliminarLista(List** l);
void agregarInicio(List** l, int data);
void agregarFinal(List** l, int data);
int length(List* l);
void print_list(List* l);
void insertarOrdenado(List **l, int data);

int main()
{
    List *l = NULL, *pares = NULL, *impares = NULL, *aux;
    int num;
    printf("Ingrese valores a la lista (0 finaliza la carga): ");
    do
    {
        scanf("%d",&num);
        if(num != 0)
            insertarOrdenado(&l, num);
    } while (num != 0);
    
    aux = l;
    while (aux != NULL)
    {
        if(aux->data%2 == 0)
            insertarOrdenado(&pares, aux->data);
        else
            insertarOrdenado(&impares, aux->data);
        aux = aux->next;
    }
    free(aux);
    printf("\nEl largo de la lista es %d.\n", length(l));
    printf("Sus elementos son: ");
    print_list(l);
    printf("\nEl largo de la lista de pares es %d.\n", length(pares));
    printf("Sus elementos son: ");
    print_list(pares);
    printf("\nEl largo de la lista de impares es %d.\n", length(impares));
    printf("Sus elementos son: ");
    print_list(impares);

    eliminarLista(&l);
    eliminarLista(&pares);
    eliminarLista(&impares);
    return 0;
}

void eliminarLista(List** l){
    List* act = *l;
    List *aux = NULL;

    while(act = NULL){
        aux = act;
        act = act->next;
        free(aux);
    }
    *l = NULL;
}

void agregarInicio(List** l, int data){
    List* new = (List *)malloc(sizeof(List));
    new->data = data;
    if(*l != NULL)
        new->size = (*l)->size;
    else
        new->size = 0;
    new->next = *l;
    *l = new;
    (*l)->size++;
}

void agregarFinal(List** l, int data){
    List* new = (List *)malloc(sizeof(List));
    new->data = data;
    new->size = 0;
    new->next = NULL;
    if(*l == NULL){
        *l = new;
    }
    else{
        List* act = *l;
        while(act->next!=NULL){
            act = act->next;
        }
        act->next = new;
    }
    (*l)->size++;
}

int length(List* l){
    return (l->size);
}

void print_list(List* l){
    while (l != NULL){
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
    
}

void insertarOrdenado(List **l, int data){
    List* new = (List *)malloc(sizeof(List));
    new->data = data;
    new->size = 0;

    List *act = *l;
    List *ant = *l;

    while(act != NULL && act->data < data){
        ant = act;
        act = act->next;
    }
    if(ant == act) //Si es el primero
        *l = new;
    else
        ant->next = new;
    new->next = act;
    (*l)->size++;
}