#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    int info;
    struct No* prox;
};

struct Fila {
    struct No *ini, *fim;
    int tam;
};

struct No* criarNo(int info){
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->info = info;
    novo->prox = NULL;
    return novo;
}

struct Fila* criarFila() {
    struct Fila* fila = (struct Fila*)malloc(sizeof(struct Fila));
    fila->ini = fila->fim = NULL;
    fila->tam = 0;
    return fila;
}

int estaCheia(struct Fila* fila, int k) {
    if(fila->tam == k)
        return 1;
    return 0;
}

int estaVazia(struct Fila* fila) {
    if(fila->tam == 0)
        return 1;
    return 0;
}

void insercaoFila(struct Fila* fila, int info, int k) {
    if(!estaCheia(fila, k)){
        struct No* novo = criarNo(info);
        if(estaVazia(fila)){
            fila->ini = fila->fim = novo;
            fila->tam++;
            return;
        }
        fila->fim->prox = novo;
        fila->fim = novo;
        fila->tam++;
    }
}

void remocaoFila(struct Fila* fila) {
    if (!estaVazia(fila)){
        struct No* no = fila->ini;
        fila->ini = fila->ini->prox;

        if(fila->ini == NULL)
            fila->fim = NULL;
        
        free(no);
        fila->tam--;
    }
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
    struct Fila* fila = criarFila();

    int lavados = 0;
    int tempo = 0;

    for (int i = 0; i < n; i++) {
        if (tempo > 0)
            tempo--;

        if (tempo == 0 && !estaVazia(fila)) {
            remocaoFila(fila);
            lavados++;
        }

        if (V[i] == '1') {
            if (!estaCheia(fila, k) && tempo == 0) {
                insercaoFila(fila, 1, k);
                tempo = 2;
            }
        }
    }

    printf("Carros lavados: %d\n", lavados);

    free(V);
    free(fila);

    return 0;
}