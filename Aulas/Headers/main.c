#include <stdio.h>
#include "inicializa.h"
//#include "algoritmos2.h"

/* 
struct sVetor {   
    int *elementos;
    int tamanho;
    int inicio;
    int final; };
typedef struct sVetor sVet;
*/

int main ()
{
    // Inicialização do vetor e variaveis:  -------------------------------------------------
    sVet* Vetor;
    int NumComp;
    int TamVet;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &TamVet);

    // Alocando a struct e o Vetor de valores:
    if (! (Vetor = cria_vetor(TamVet)))
        fprintf (stderr, "Erro na alocacao do vetor\n");
    else
        printf ("Vetor criado com sucesso\n");
    
    // Inserindo valores no vetor e em seguida o imprimindo:
    input_vet(Vetor);
    output_vet(Vetor);

    // Insertion Sort: ----------------------------------------------------

    // limpa os dados alocados: 
    limpa_vet(Vetor);
    Vetor = NULL;
}