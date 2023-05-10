#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int data;
    struct nodo *next;
} List;

List *inicializar();
void eliminarLista(List **l);
void agregarInicio(List** l, int data);
void agregarFinal(List** l, int data);
int length(List* l);
void print_list(List* l);

int main()
{
    return 0;
}

List* inicializar(){
    List *l = malloc(sizeof(List));
    l->next = NULL;
    return l;
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
