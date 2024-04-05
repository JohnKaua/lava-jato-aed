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

    // Loop sobre os carros representados pelo vetor V
    for (int i = 0; i < n; i++) {
        if (tempo > 0) 
            tempo--;   // Decrementa o tempo de espera para o próximo carro

        if (tempo == 0 && !estaVazia(fila)) { // Se não há mais carros esperando e a fila não está vazia
            remocaoFila(fila); // Remove um carro da fila para lavagem
            lavados++;         // Incrementa o contador de carros lavados
        }

        // Se o carro está marcado como '1' e a fila não está cheia e não há tempo de espera
        if (V[i] == '1' && !estaCheia(fila, k) && tempo == 0) {
            insercaoFila(fila, 1, k); // Insere o carro na fila para lavagem
            tempo = 2;                // Define um tempo de espera para o próximo carro
        }
    }

    // Imprime a quantidade total de carros lavados
    printf("Carros lavados: %d\n", lavados);

    // Libera a memória alocada para o vetor V e a fila
    free(V);
    free(fila);

    return 0;
}
