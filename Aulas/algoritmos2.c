#include <stdio.h>
#include <string.h>
#include "algoritmos2.h"
#include "inicializa.h"

int buscaSequencial(int Vet[], int tam, int val, int* NumComp) 
{   
    int a = 0;
    int b = (tam-1);
    if (a > b)
        return -1;
    (*NumComp)++;
    if (val == Vet[b])
        return (b);
    if (val > Vet[b])
        return -1;
    return buscaSequencial(Vet, (tam-1), val, NumComp);
}

int buscaBinaria(int Vet[], int a, int b, int val, int* NumComp) 
{   
    int m;
    if (a > b)
        return -1;
    m = (a + b)/2;
    (*NumComp)++;
    if (val == Vet[m])
        return (m);
    if (val < Vet[m])
        return buscaBinaria(Vet, a, (m-1), val, NumComp);
    
    return buscaBinaria(Vet, (m+1), b, val, NumComp);
}

//Auxiliares de InsertionSort:
int busca_IS(int* NumComp, int x, int Vet[], int a, int b) 
{   
    if (a > b)
        return (a-1);
    (*NumComp)++;
    if (x >= Vet[b])
        return b;
    return busca_IS(NumComp, x, Vet, a, (b-1));
}

int insere_IS(int* NumComp, int Vet[], int a, int b) 
{   
    int p = busca_IS(NumComp, Vet[b], Vet, a, (b-1)); // Linha de interesse
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

int insertionSort(int* NumComp, int Vet[], int tam) 
{   
    int a = 0;
    int b = (tam-1);

    if (a >= b)
        return *NumComp
        ;
    insertionSort(NumComp, Vet, (tam-1));   // linha de interesse
    insere_IS(NumComp, Vet, a, b);          // linha de interesse
    return *NumComp;
}

//Auxiliares de SelectionSort:
int maximo_SS(int* NumComp, int Vet[], int a, int b) 
{
    int m = b;
    int i = b;
    while (i > a)
    {
        (*NumComp)++;
        i--;
        if (Vet[i] > Vet[m])
            m = i;
    }
    return m;
}

int selectionSort(int* NumComp, int Vet[], int tam) 
{
    int a = (0);
    int b = (tam-1);
    if (a >= b)
        return *Vet;
    //Troca os elementos de posição:
    int x = maximo_SS(NumComp, Vet, a, b);
    int aux = Vet[b];
    Vet[b] = Vet[x];
    Vet[x] = aux;
    return selectionSort(NumComp, Vet, (tam-1));
}

//Auxiliares de MergeSort:
int intercala_MS(int* NumComp, int Vet[], int a, int m, int b) 
{   
    if (a >= b)
        return *Vet;
    int aux[b-a+1];
    int i = a;
    int j = m + 1;
    for (int k = 0; k <= (b-a); k++)
    {
        (*NumComp)++;
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

int mergeSort(int* NumComp, int Vet[], int a, int b)
{   
    if (a >= b)
        return *Vet;
    int m = (a+b)/2;
    mergeSort(NumComp, Vet, a, m);
    mergeSort(NumComp, Vet, (m+1), b);
    return intercala_MS(NumComp, Vet, a, m, b);
}

//Auxiliares de QuickSort:
int particiona_QS(int* NumComp, int Vet[], int a, int b, int x)
{
    int m = (a-1);
    int i;
    for (i = a; i <= b; i++)
    {
        (*NumComp)++;
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

int quickSort(int* NumComp, int Vet[], int a, int b)
{
    if (a >= b)
        return *Vet;
    int m = particiona_QS(NumComp, Vet, a, b, Vet[b]);
    quickSort(NumComp, Vet, a, (m-1));
    return quickSort(NumComp, Vet, (m+1), b);
}

/* ---------- Heapsort: ---------- */
// Aula 25/07 Filas de prioridade e heaps
int max_heapify(int Vet[], int i, int tam)
{   
    int maior = i;
    int esq = 2 * i;
    int dir = 2 * i + 1;

    if (esq <= tam && Vet[esq] > Vet[i])
        maior = esq;
    else
        maior = i;
    if (dir <= tam && Vet[dir] > Vet[maior])
        maior = dir;
    if (maior != i)
    {
        troca_vet(Vet, i, maior);
        max_heapify(Vet, maior, tam);
    }
}

// Aula 27/07 Construção de heaps e heapsort
int max_heap(int Vet[], int tam)
{
    int i;
    for (i = tam/2; i>0; i--)
        max_heapify(Vet, i, tam);
}

// Algoritmo Heapsort:
int heap_sort(int Vet[], int tam)
{
    max_heap(Vet, tam);
    int i;
    for (i=tam; i>0; i--)
    {
        troca_vet(Vet, 1, i);
        max_heapify(Vet, 1, i-1);
    }
}