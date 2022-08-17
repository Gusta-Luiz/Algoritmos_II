#ifndef ORDENACAO_H_
#define ORDENACAO_H_

//a busca sequencial é a busca ingênua
int buscaSequencial(int Vet[], int tam, int val, int* NumC);

//busca binária no vetor
int buscaBinaria(int Vet[], int a, int b, int val, int* NumC);

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
