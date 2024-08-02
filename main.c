#include <stdio.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    int itens[MAX];
    int tamanho;
} ListaSequencial;


void criaListaVazia(ListaSequencial *lista) {
    lista->tamanho = 0;
}


bool listaVazia(ListaSequencial *lista) {
    return lista->tamanho == 0;
}


bool listaCheia(ListaSequencial *lista) {
    return lista->tamanho == MAX;
}

// 4. Obter o tamanho da lista
int tamanhoLista(ListaSequencial *lista) {
    return lista->tamanho;
}


int obterElemento(ListaSequencial *lista, int posicao, int *elemento) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return -1;
    }
    *elemento = lista->itens[posicao];
    return 0;
}


int modificarElemento(ListaSequencial *lista, int posicao, int novoValor) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return -1; //
    }
    lista->itens[posicao] = novoValor;
    return 0;
}


int inserirElemento(ListaSequencial *lista, int posicao, int elemento) {
    if (listaCheia(lista)  posicao < 0  posicao > lista->tamanho) {
        return -1;
    }
    for (int i = lista->tamanho; i > posicao; i--) {
        lista->itens[i] = lista->itens[i - 1];
    }
    lista->itens[posicao] = elemento;
    lista->tamanho++;
    return 0;
}


int retirarElemento(ListaSequencial *lista, int posicao, int *elemento) {
    if (listaVazia(lista)  posicao < 0  posicao >= lista->tamanho) {
        return -1;
    }
    *elemento = lista->itens[posicao];
    for (int i = posicao; i < lista->tamanho - 1; i++) {
        lista->itens[i] = lista->itens[i + 1];
    }
    lista->tamanho--;
    return 0;
}

int main() {
    ListaSequencial lista;
    criaListaVazia(&lista);

    inserirElemento(&lista, 0, 10);
    inserirElemento(&lista, 1, 20);
    inserirElemento(&lista, 2, 30);

    int elemento;
    if (obterElemento(&lista, 1, &elemento) == 0) {
        printf("Elemento na posição 1: %d\n", elemento);
    }

    modificarElemento(&lista, 1, 25);

    if (obterElemento(&lista, 1, &elemento) == 0) {
        printf("Elemento na posição 1 após modificação: %d\n", elemento);
    }

    retirarElemento(&lista, 1, &elemento);
    printf("Elemento retirado da posição 1: %d\n", elemento);

    return 0;
}
