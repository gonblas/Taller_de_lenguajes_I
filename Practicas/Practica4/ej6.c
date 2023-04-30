#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int data;
    struct nodo *next;
} List;

void inicializar(List* l, int data);
void eliminarLista(List** l);
void agregarInicio(List** l, int data);
void agregarFinal(List** l, int data);
int length(List* l);
void print_list(List* l);
int eliminar(List **l, int data); //Extra

int main()
{
    return 0;
}

void inicializar(List* l, int data){
    l->data = data;
    l->next = NULL;
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
    new->next = *l;
    *l = new;
}

void agregarFinal(List** l, int data){
    List* new = (List *)malloc(sizeof(List));
    new->data = data;
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
}

int length(List* l){
    int len = 0;
    while (l != NULL)
    {
        l = l->next;
        len++;
    }
    return len;
}

void print_list(List* l){
    printf("Lista: ");
    while (l != NULL){
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
    
}

int eliminar(List** l, int data){
    List *act = *l;
    List *ant = *l;

    while(act != NULL && act->data != data){
        ant = act;
        act = act->next;
    }
    if(act != NULL){
        if(act == *l)
            *l = act->next;
        else
            ant->next = act->next;
        free(act);
        return 1;
    }
    return 0;
}