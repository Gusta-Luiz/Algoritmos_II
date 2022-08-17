#include <stdio.h>
#include <stdlib.h>

struct sVetor {   
    int *elementos;
    int tamanho;
    int inicio;
    int final; };
typedef struct sVetor sVet;

sVet* cria_vetor(int tamanho)
{
    /* aloca o espaço de uma struct e verifica se houve erro */
    sVet *Vet = malloc(sizeof(sVet));
    if (Vet == NULL)
        return NULL;
        
    /* aloca o espaço para os elem. do vetor e verifica se houve erro */
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
    return Vet;
}

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

void main ()
{
    int TamVet = 5;
    struct sVetor* Vetor;

    // Alocando a struct e o Vetor de valores:
    if (! (Vetor = cria_vetor(TamVet)))
        fprintf (stderr, "Erro na alocacao do vetor\n");
    else
        printf ("Vetor criado com sucesso\n");
    
    // Inserindo valores no vetor:
    for (int i=0; i<Vetor->tamanho; i++)
    {
        printf("Digite o valor do elemento %d: ", i);
        scanf("%d", &Vetor->elementos[i]);
    }

    //-------------- bota os coisa de teste aqui: ------------------
    int NumComp = 0;
    int x = buscaSequencial(Vetor->elementos, Vetor->tamanho, 3, &NumComp);
    printf("Numero de comparações: %d\n", NumComp);
    printf("Posição do elemento: %d\n", x);



    // ------------------- fim dos testes --------------------------
    // escreve os elementos do vetor:
    for (int i=0; i<Vetor->tamanho; i++)
        printf("%d ", Vetor->elementos[i]);
    printf("/n");
    free(Vetor->elementos);
    free(Vetor);
}