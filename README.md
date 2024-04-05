# Lava Jato - AED
O código, escrito em C, consiste em uma implementação simples de uma simulação de um sistema de lavagem de carros com uma fila limitada.
## Estrutura da Dados
Duas estruturas de dados são definidas:

__No:__ Representa um nó de uma lista encadeada, contendo uma informação (valor inteiro) e um ponteiro para o próximo nó.

__Fila:__ Representa uma fila de carros a serem lavados, mantendo ponteiros para o início e fim da fila, além do tamanho atual da fila.
## Funções principais
__criarNo(int info):__ Cria um novo nó com a informação especificada.

__criarFila():__ Cria uma nova fila vazia.

__estaCheia(struct Fila* fila, int k):__ Verifica se a fila está cheia, com base no limite de capacidade k.

__estaVazia(struct Fila* fila):__ Verifica se a fila está vazia.

__insercaoFila(struct Fila* fila, int info, int k):__ Insere um novo carro na fila, desde que a fila não esteja cheia.

__remocaoFila(struct Fila* fila):__ Remove um carro da fila para lavagem.
## Função Principal (Main)
Na função main():

1- São solicitados ao usuário os valores de n (quantidade total de carros) e k (capacidade máxima da fila).

2- O usuário insere o vetor binário V, representando os carros que chegam ao sistema de lavagem.

3- É inicializada uma fila vazia.

4- É realizada uma iteração sobre os carros representados pelo vetor V, verificando se eles precisam ser lavados e manipulando a fila conforme necessário.

5- É impressa a quantidade total de carros lavados.

6- A memória alocada para o vetor V e a fila é liberada.

## Como funciona o programa?



