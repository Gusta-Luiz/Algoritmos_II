#ifndef inicializa
#define inicializa

struct sVetor 
{   
    int *elementos;
    int tamanho;
    int inicio;
    int final; 
};
typedef struct sVetor sVet;

// Cria uma struct com um vetor de "tamanho" elementos.
struct sVetor* cria_vetor(int tamanho);

// Preenche o vetor com os dados fornecidos.
void input_vet(struct sVetor *Vetor);

// Imprime os elementos do vetor.
void output_vet(struct sVetor *Vetor);

// Troca dois elementos de um vetor.
void troca_vet(int *vetor, int pos1, int pos2);

// Libera a memoria alocada para o vetor.
void limpa_vet(struct sVetor *Vetor);

#endif // inicializa.h