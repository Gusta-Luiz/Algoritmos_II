#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 6

// Troca a posicao entre dois elementos da string
void troca(char *x, char *y) 
{ 
    char aux; 
    aux = *x; 
    *x = *y; 
    *y = aux;
} 

// Retorna todos os subconjuntos de uma string
char *retorna_subconj(int vet[], char *str, char *pront)
{
    strcpy(pront, "");
    for (int i = 0; i < strlen(str); i++)
        if (vet[i] == 1)
            strncat(pront, &str[i], 1);
    return pront;
}

// Realiza a permutacao de uma string e retorna todas as possibilidades
char *permutacao(char *str, int pos, int n, char *result) 
{ 
    int i; 
    if (pos == n) 
    {
        printf("P-> %s\n", str);
        strcpy(result, str);
        return result;
    }
    for (i = pos; i < n; i++) 
    {
        troca((str + pos), (str + i)); 
        permutacao(str, pos + 1, n, result); 
        troca((str + pos), (str + i)); //backtrack 
    } 
} 

// Retorna todas as possiveis combinacoes de uma string recebida
void backtrack(int vet[], int pos, int n, char *str)
{
    if (pos == n)
    {
        char result[TAM+10]; 
        strcpy(result, retorna_subconj(vet, str, result));
        printf("S-> %s\n", result);
        strcpy(result, permutacao(result, 0, strlen(result), result));
        printf("R-> %s\n", result);
        return;
    }
    vet[pos] = 1;
    backtrack(vet, pos + 1, n, str);
    vet[pos] = 0;
    backtrack(vet, pos + 1, n, str);
}

int main ()
{
    int vet[TAM+1];
    char str[] = "abcdefgh";
    backtrack(vet, 0, 3, str);
}