#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ini, fim, tamanho;
    unsigned capacidade;
    int* array;
} Fila;

Fila* criarFila(unsigned capacidade) {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->ini = fila->tamanho = 0; 
    fila->fim = capacidade - 1;
    fila->array = (int*) malloc(fila->capacidade * sizeof(int));
    memset(fila->array, 0, fila->capacidade * sizeof(int));
    return fila;
}

int estaCheia(Fila* fila) {
    return (fila->tamanho == fila->capacidade);
}

int estaVazia(Fila* fila) {
    return (fila->tamanho == 0);
}

void enfileirar(Fila* fila, int item) {
    if (estaCheia(fila))
        return;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->array[fila->fim] = item;
    fila->tamanho = fila->tamanho + 1;
}

int desenfileirar(Fila* fila) {
    if (estaVazia(fila))
        return -1;
    int item = fila->array[fila->ini];
    fila->ini = (fila->ini + 1) % fila->capacidade;
    fila->tamanho = fila->tamanho - 1;
    return item;
}

int main() {
    int n, k;
    char* V;

    // Recebe os valores de n e k
    printf("Digite o valor de n e k: ");
    scanf("%d %d", &n, &k);

    // Recebe o vetor binário V
    V = (char*) malloc((n + 1) * sizeof(char));
    printf("Digite o vetor binario V: ");
    scanf("%s", V);

    // Cria a fila
    Fila* fila = criarFila(k);

    int carrosLavados = 0;
    int tempoRestante = 0;

    for (int i = 0; i < n; i++) {
        if (tempoRestante > 0)
            tempoRestante--;

        if (tempoRestante == 0 && !estaVazia(fila)) {
            desenfileirar(fila);
            carrosLavados++;
        }

        if (V[i] == '1') {
            if (!estaCheia(fila) && tempoRestante == 0) {
                enfileirar(fila, 1);
                tempoRestante = 2;
            }
        }
    }

    // Processa os carros restantes na fila após o último minuto
    while (!estaVazia(fila) && tempoRestante <= 0) {
        desenfileirar(fila);
        carrosLavados++;
        if (!estaVazia(fila)) {
            tempoRestante = 2;
        }
    }

    printf("Carros lavados: %d\n", carrosLavados);

    free(V);
    free(fila->array);
    free(fila);

    return 0;
}
