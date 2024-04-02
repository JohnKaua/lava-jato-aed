typedef struct Fila{
    int ini, fim, tam_atual;
    unsigned tam;
    int* array;
}Fila;

Fila* criarFila(unsigned tam){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->tam = tam;
    fila->ini = fila->tam = 0;
    fila->fim = tam - 1;
    fila->array = (int*) malloc(fila->tam * sizeof(int));
    return fila;
}

int isCheia(Fila* fila){
    return(fila->tam_atual == fila->tam);
}

int isVazia(Fila* fila){
    return(fila->tam_atual == 0);
}

void insercaoFila(Fila* fila, int x){
    if(!isCheia(fila)){
        fila->fim = (fila->fim + 1) % fila->tam;
        fila->array[fila->fim] = x;
        fila->tam_atual = fila->tam_atual + 1;
    } else printf("overflow");
}

void remocaoFila(Fila* fila){
    if(!isVazia(fila)){
        int x = fila->array[fila->ini];
        fila->ini = (fila->ini + 1) % fila->tam;
        fila->tam_atual = fila->tam_atual - 1;
    } else printf("underflow");
}

int main(){
    int n, k;
    int* V;

    printf("Quantidade de minutos: ");
    scanf("%d", &n);
    printf("Capacidade do lavajato: ");
    scanf("%d", &k);

    V = (int*) malloc(n * sizeof(int));
    scanf("%d", V);
    printf("%d", V);
}