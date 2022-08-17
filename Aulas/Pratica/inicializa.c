#include <stdio.h>
#include <stdlib.h>
#include "inicializa.h"

struct sVetor* cria_vetor(int tamanho)
{
    /* aloca o espaço de uma struct e verifica se houve erro */
    struct sVetor *Vet = malloc(sizeof(struct sVetor));
    if (Vet == NULL)
        return NULL;
        
    /* aloca o espaço para os elem. do Vet e verifica se houve erro */
    Vet->elementos = malloc(sizeof(int) * tamanho);
    if (Vet->elementos == NULL)
    {   
        /* libera memoria da struct em caso de erro */
        free(Vet);
        return NULL;
    }
    /* inicializa os campos da struct */
    Vet->tamanho = tamanho;
    Vet->inicio = 0;
    Vet->final = (tamanho - 1);
}

void input_vet(struct sVetor *Vet)
{
    /* Recebe os elementos e os insere no vetor */
    for (int i=0; i<Vet->tamanho; i++)
    {
        printf("Digite o valor do elemento %d: ", i);
        scanf("%d", &Vet->elementos[i]);
    }
}

void output_vet(struct sVetor *Vet)
{
    /* Faz um Printf de todos os elementos do vetor */
    for (int i=0; i<Vet->tamanho; i++)
        printf("%d ", Vet->elementos[i]);
    printf("\n");
}

void troca_vet(int *Vet, int pos1, int pos2)
{
    /* troca os elementos de pos1 e pos2 utilizando uma var auxiliar */
    int aux = Vet[pos1];
    Vet[pos1] = Vet[pos2];
    Vet[pos2] = aux;
}

void limpa_vet(struct sVetor *Vet)
{
    /* libera memoria do Vet */
    free(Vet->elementos);
    /* libera memoria da struct */
    free(Vet);
}