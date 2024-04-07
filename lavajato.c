#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No { //Struct para nó
    int info; // campo de informação
    struct No* prox; // ponteiro para o proximo nó
};

struct Fila { // struct para fila
    struct No *ini, *fim; // ponteiros para início e fim da fila
    int tam; // tamanho da fila
};

struct No* criarNo(int info){ // função para criar nó
    struct No* novo = (struct No*)malloc(sizeof(struct No)); // alocação de memória para o novo nó
    novo->info = info; // campo info receber o valor passado no parâmetro
    novo->prox = NULL; // ponteiro para prox recebe lambda
    return novo; // retorna novo nó
}

struct Fila* criarFila() { // função para criar uma nova fila
    struct Fila* fila = (struct Fila*)malloc(sizeof(struct Fila)); // alocação de memória para a nova fila
    fila->ini = fila->fim = NULL; // a fila inicia vazia, com inicio e fim iguais a lambda
    fila->tam = 0; // tamanho começa em 0
    return fila; // retorna nova fila
}

int estaCheia(struct Fila* fila, int k) { // função que verifica se a fila está cheia
    if(fila->tam == k) // se o atributo tamanho da fila é igual seu tamanho máximo (k) a fila está cheia
        return 1;
    return 0;
}

int estaVazia(struct Fila* fila) { // função que verifica se a fila está vazia, se seu tamanho for 0 a fila está vazia
    if(fila->tam == 0)
        return 1;
    return 0;
}

void insercaoFila(struct Fila* fila, int info, int k) { // função de inserção na fila
    if(!estaCheia(fila, k)){ // verifica se a fila ainda tem espaço disponível
        struct No* novo = criarNo(info); // novo nó é criado
        if(estaVazia(fila)){ // verifica se a fila está vazia
            fila->ini = fila->fim = novo; // novo nó passa a ser tanto início quanto fim da fila
            fila->tam++; // e o tamanho incrementa
            return;
        } // caso a fila já tenha elementos
        fila->fim->prox = novo; // novo nó é inserido na fila
        fila->fim = novo; // e passa a ser o fim da fila
        fila->tam++; // tamanho incrementa
    }
}

void remocaoFila(struct Fila* fila) { // função para remoção na fila
    if (!estaVazia(fila)){ // verifica se a fila tem elementos
        struct No* no = fila->ini; // o nó a ser removido é o início da fila
        fila->ini = fila->ini->prox; // o ponteiro início anda para o próximo nó

        if(fila->ini == NULL) // se após a remoção início for lambda, o fim também será lambda, pois a fila se tornou vazia
            fila->fim = NULL;
        
        free(no); // liberação de memória do nó removido
        fila->tam--; // tamanho decrementa
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

    // Loop sobre os carros representados pelo vetor V
    for (int i = 0; i < n; i++) {
        if (tempo > 0) 
            tempo--;   // Se o tempo de lavagem não é 0, decrementa

        if (tempo == 0 && !estaVazia(fila)) { // Se o tempo da lavagem acabou e a fila não está vazia
            remocaoFila(fila); // Remove o carro da fila
            lavados++;         // Incrementa o contador de carros lavados
        }

        // se no minuto i chegar um carro, fila não está cheia e o tempo de lavagem acabou
        if (V[i] == '1' && !estaCheia(fila, k) && tempo == 0){
            insercaoFila(fila, 1, k); // Insere o carro na fila
            tempo = 2;                // Define o tempo de lavagem para 2
        }
        if (V[i] == '1' && !estaCheia(fila, k) && tempo != 0){
            insercaoFila(fila, 1, k);
        }
    }

    // Imprime a quantidade total de carros lavados
    printf("Carros lavados: %d\n", lavados);

    system("pause");

    // Libera a memória alocada para o vetor V e a fila
    free(V);
    free(fila);

    return 0;
}
