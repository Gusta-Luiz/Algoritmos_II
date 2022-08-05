#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp = 0;

	int Valor = 7;
    int Tamanho = 10;
    int vetor[10] = {3, 2, 10, 5, 4, 1, 9, 8, 6, 7};
    int save[Tamanho];
    printf("Escreva os valores do vetor: ");
	for (int i = 0; i < Tamanho; i++)
		{
        // scanf("%d", &vetor[i]);
        save[i] = vetor[i];
        }
    // printf("\nEscreva o valor a ser buscado: ");
    // scanf("%d", &Valor);

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	clock_t start, end;//variáveis do tipo clock_t
    double total;

    printf("\n--- Algoritmo Insertion Sort --- \n");
    start = clock();
    insertionSort(&numComp, vetor, Tamanho);
    end = clock(); 
	total = ((double)end - start)/CLOCKS_PER_SEC;
    Resultados(vetor, Tamanho, &numComp, total, save);

	printf("\n--- Algoritmo Selection Sort --- \n");
    start = clock();
    selectionSort(&numComp, vetor, Tamanho);
    end = clock(); 
	total = ((double)end - start)/CLOCKS_PER_SEC;
    Resultados(vetor, Tamanho, &numComp, total, save);

	int a = 0;
	int b = (Tamanho - 1);

    printf("\n--- Algoritmo Merge Sort --- \n");
    start = clock();
    mergeSort(&numComp, vetor, a, b);
    end = clock(); 
	total = ((double)end - start)/CLOCKS_PER_SEC;
    Resultados(vetor, Tamanho, &numComp, total, save);

	printf("\n--- Algoritmo Quick Sort --- \n");
    start = clock();
    quickSort(&numComp, vetor, a, b);
    end = clock(); 
	total = ((double)end - start)/CLOCKS_PER_SEC;
    Resultados(vetor, Tamanho, &numComp, total, save);

    printf("\n");

    insertionSort(&numComp, vetor, Tamanho);
    numComp = 0;
	printf("\n--- Algoritmo Busca Sequencial --- \n");
    start = clock();
    idxBusca = buscaSequencial(vetor, Tamanho, Valor, &numComp);
    end = clock(); 
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("A posição do valor encontrado: %d\n", idxBusca);
    Resultados(vetor, Tamanho, &numComp, total, save);

    insertionSort(&numComp, vetor, Tamanho);
    numComp = 0;
	printf("\n--- Algoritmo Busca Binaria --- \n");
    start = clock();
    idxBusca = buscaBinaria(vetor, a, b, Valor, &numComp);
    end = clock(); 
	total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("A posição do valor encontrado: %d\n", idxBusca);
    Resultados(vetor, Tamanho, &numComp, total, save);

	return 0;
}
