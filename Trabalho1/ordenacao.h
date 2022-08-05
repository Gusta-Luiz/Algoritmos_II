#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

//a função getNome deve colocar o seu nome dentro da chamada
//seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

//Assum que os vetores estão ordenados ao chamar as funções de busca
//As funções de busca não devem alterar o vetor
//O retorno das funções de busca é o índice do elemento no vetor,
//ou -1 caso o elemeno não exista no vetor
//Você deve armazenar no ponteiro int* numComparacoes o número de comparações
//envolvendo elementos do vetor feito pelo seu algoritmo na chamada

//função auxiliar para mostrar resultados
void Resultados(int Vet[], int tam, int* NumC, double Tempo, int Aux[]);

//função para limpar variaveis
void LimpaVetor(int Vet[], int tam, int* NumC);

//a busca sequencial é a busca ingênua
int buscaSequencial(int Vet[], int tam, int val, int* NumC);

//busca binária no vetor
int buscaBinaria(int Vet[], int a, int b, int val, int* NumC);

//Cada uma das funções deve ordenar o vetor passado como parâmetro
//O retorno das funções de ordenação é o número de comparações
//entre elementos do vetor

//Funções auxiliares do InsertionSort:
int busca_IS(int* NumC, int x, int Vet[], int a, int b);
int insere_IS(int* NumC, int Vet[], int a, int b);

int insertionSort(int* NumC, int Vet[], int tam);

//Função auxiliar do SelectionSort:
int maximo_SS(int* NumC, int Vet[], int a, int b);

int selectionSort(int* NumC, int Vet[], int tam);

//Função auxiliar do MergeSort:
int intercala_MS(int* NumC, int Vet[], int a, int m, int b);

int mergeSort(int* NumC, int Vet[], int a, int b);

//Função auxiliar do QuickSort:
int particiona_QS(int* NumC, int Vet[], int a, int b, int x);

int quickSort(int* NumC, int Vet[], int a, int b);

#endif // ORDENACAO_H_
