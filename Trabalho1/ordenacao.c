#include "ordenacao.h"
#include <stdio.h>
#include <string.h>

void getNome(char nome[])
{
	//substitua por seu nome
	strncpy(nome, "Luiz Gustavo Dalmaz Paquete", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

unsigned int getGRR()
{
	return 20211794;
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

void Resultados(int Vet[], int tam, int* NumC, double Tempo, int Aux[])
{
    printf("Número de comparações: %d\n", *NumC);
    printf("Tempo de execução: %f \nVetor ordenado: ", Tempo);
    for (int i = 0; i < tam; i++)
        {
        printf("%d ", Vet[i]);
        Vet[i] = Aux[i];
        }
    *NumC = 0;
    printf("\n");

}

int buscaSequencial(int Vet[], int tam, int val, int* NumC)
{   
    int a = 0;
    int b = (tam-1);

    if (a > b)
        return -1;

    (*NumC)++;
    if (val == Vet[b])
        return (b);
    if (val > Vet[b])
        return -1;
    return buscaSequencial(Vet, (tam-1), val, NumC);
}

int buscaBinaria(int Vet[], int a, int b, int val, int* NumC)
{   
    int m;
    if (a > b)
        return -1;
    m = (a + b)/2;
    
    (*NumC)++;
    if (val == Vet[m])
        return (m);
    if (val < Vet[m])
        return buscaBinaria(Vet, a, (m-1), val, NumC);
    
    return buscaBinaria(Vet, (m+1), b, val, NumC);
}

//Auxiliares de InsertionSort:
int busca_IS(int* NumC, int x, int Vet[], int a, int b)
{   
    if (a > b)
        return (a-1);
    (*NumC)++;
    if (x >= Vet[b])
        return b;
    return busca_IS(NumC, x, Vet, a, (b-1));
}
int insere_IS(int* NumC, int Vet[], int a, int b)
{   
    int p = busca_IS(NumC, Vet[b], Vet, a, (b-1)); // Linha de interesse
    int i = b;
    while (i > (p+1))
    {   
        //Troca os elementos de posição:
        int aux = Vet[i];
        Vet[i] = Vet[i-1];
        Vet[i-1] = aux;
        i--;
    }
    return *Vet;
}

int insertionSort(int* NumC, int Vet[], int tam)
{   
    int a = 0;
    int b = (tam-1);

    if (a >= b)
        return *NumC;
    insertionSort(NumC, Vet, (tam-1));   // linha de interesse
    insere_IS(NumC, Vet, a, b);          // linha de interesse
    return *NumC;
}

//Auxiliares de SelectionSort:
int maximo_SS(int* NumC, int Vet[], int a, int b)
{
    int m = b;
    int i = b;

    while (i > a)
    {
        (*NumC)++;
        i--;
        if (Vet[i] > Vet[m])
            m = i;
    }
    return m;
}

int selectionSort(int* NumC, int Vet[], int tam)
{
    int a = (0);
    int b = (tam-1);
    if (a >= b)
        return *Vet;
    //Troca os elementos de posição:
    int x = maximo_SS(NumC, Vet, a, b);
    int aux = Vet[b];
    Vet[b] = Vet[x];
    Vet[x] = aux;
    return selectionSort(NumC, Vet, (tam-1));
}

//Auxiliares de MergeSort:
int intercala_MS(int* NumC, int Vet[], int a, int m, int b)
{   
    if (a >= b)
        return *Vet;
    int aux[b-a+1];
    int i = a;
    int j = m + 1;

    for (int k = 0; k <= (b-a); k++)
    {
        (*NumC)++;
        if ((j > b) || (i <= m && Vet[i] <= Vet[j]))
            {
            aux[k] = Vet[i];
            i++;
            }
        else
            {
            aux[k] = Vet[j];
            j++;
            }
    }
    
    i = a;
    for (int k = 0; k <= (b-a); k++)
    {   
        Vet[i] = aux[k];
        i++;
    }
    return *Vet;
}

int mergeSort(int* NumC, int Vet[], int a, int b)
{   
    if (a >= b)
        return *Vet;
    int m = (a+b)/2;
    mergeSort(NumC, Vet, a, m);
    mergeSort(NumC, Vet, (m+1), b);
    return intercala_MS(NumC, Vet, a, m, b);
}

//Auxiliares de QuickSort:
int particiona_QS(int* NumC, int Vet[], int a, int b, int x)
{
    int m = (a-1);
    int i;
    for (i = a; i <= b; i++)
    {
        (*NumC)++;
        if (Vet[i] <= x)
        {
            m++;
            int aux = Vet[m];
            Vet[m] = Vet[i];
            Vet[i] = aux;
        }
    }
    return m;
}

int quickSort(int* NumC, int Vet[], int a, int b)
{
    if (a >= b)
        return *Vet;
    int m = particiona_QS(NumC, Vet, a, b, Vet[b]);
    quickSort(NumC, Vet, a, (m-1));
    return quickSort(NumC, Vet, (m+1), b);
}


