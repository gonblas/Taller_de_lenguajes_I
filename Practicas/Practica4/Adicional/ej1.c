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