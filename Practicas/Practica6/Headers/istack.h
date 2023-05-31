#ifndef ISTACK_H  //Evita que el archivo sea incluido multiples veces
#define ISTACK_H  //Se llama directiva de inclusion de guardia
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Stack;

Stack* s_create (); //Retorna una nueva pila. Se debe invocar antes de manipular cualquiera de ellas.
int s_push(Stack* s, int n); //Apila n en s. Retorna el elemento apilado.
int s_pop (Stack* s); //Desapila un elemento de s.
int s_top (Stack s); //Retorna el próximo elemento que será desapilado.
int s_empty(Stack s); //Retorna 1 si s está vacía, 0 en caso contrario.
int s_length(Stack s); //Retorna la cantidad de elementos apilados en s.

int counter = 0;  //El alcence de esta variable llega al archivo que la incluye

Stack* s_create (){
    Stack *S = (Stack*) malloc(sizeof(Stack));
    S->next = NULL;
    return S;
}

int s_push(Stack* s, int n){
    Stack* newNode = (Stack*) malloc(sizeof(Stack));
    newNode->data = n;

    newNode->next = s->next;
    s->next = newNode;
    counter++;
}

int s_pop (Stack* s){
    int element = s->next->data;
    Stack* temp = s->next;
    s->next = temp->next;
    free(temp);
    counter--;
    return element;
}

int s_top (Stack s){
    return s.data;
}

int s_empty(Stack s){
    return (s.next == NULL);
}

int s_length(Stack s){
    return counter;
}

/*
int s_length(Stack s){
    Stack *temp = s.next;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
*/

#endif  //Cierro la directiva de inclusion de guardia