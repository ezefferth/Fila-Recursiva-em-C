#include <stdio.h>
#include <stdlib.h>

typedef struct noh_t {
    int item;
    struct noh_t *Prox;
}noh;

typedef struct {
    noh *inicio;
    noh *fim;
}Fila;

void CriaFila (Fila *F) {
    F->inicio = malloc(sizeof(noh));
    F->fim = F->inicio;
    F->inicio->Prox=NULL;
}

int Vazia (Fila *F){
    return F->inicio == F->fim;
}

void enfileira (int *X, Fila *F){
    noh *aux;
    aux = malloc(sizeof(noh));
    F->fim->Prox=aux;
    F->fim=aux;
    aux->Prox=NULL;
    aux->item=*X;
}

void desinfilera (Fila *F, int *X){
    noh *aux;
    if (Vazia(F)){
        printf("Fila vazia.");
        return;
    }
    aux=F->inicio;
    F->inicio=F->inicio->Prox;
    *X=F->inicio->item;
    aux->Prox=NULL;
    free(aux);
}

void apaga (Fila *F){
    int X;
    while (!(Vazia(F))){
        desinfilera(F, &X);
    }
    free(F->inicio);
}

int main()
{
    Fila *F=malloc(sizeof(noh));
    CriaFila(F);
    int i,X;
    for (i=0;i<30;i++){
        enfileira(&i,F);
    }
    for (i=0;i<30;i++){
        desinfilera(F,&X);
        printf("%d\n",X);
    }
    apaga(F);
    free(F);
    return 0;
}
