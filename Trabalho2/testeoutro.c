#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adiciona um caracter na string dentro da posição pos
void add(char *str, char c, int pos)
{
    int len = strlen(str);
    for (int i = len; i > pos; i--)
        str[i] = str[i - 1];
    str[pos] = c;
    str[len + 1] = '\0';
}

// Remove um caracter da string na posição pos
void rmv(char *str, int pos)
{
    int len = strlen(str);
    for (int i = pos; i < len; i++)
        str[i] = str[i + 1];
    str[len - 1] = '\0';
}

char *permutar(char *pront, char *resto)
{
    if (strlen(resto) == 0)
    {
        //printf("%s\n", pront);
        return pront;
    }
    else
        for (int i = 0; i < strlen(resto); i++)
        {
            char c = resto[i];
            // Realiza as operacoes (pronto + c) e (resto - c) necessarias para a permutacao
            add(pront, c, strlen(pront));
            rmv(resto, i);
            permutar(pront, resto);
            // Realiza o backtrack das operacoes anteriores:
            add(resto, c, i);
            rmv(pront, strlen(pront));
        }
}

void subconjuntos(char *pront, char *resto)
{
    char result[100] = "";
    char saida[6] = "";
    if (strlen(resto) == 0)
    {
        // Realiza a permutacao do subconjunto pronto
        if (strlen(pront) == 6)
            strcpy(result, permutar(saida, pront));
        printf("%s\n", result);
        return ;
    }
    else
        if (strlen(pront) < 6)
        {   
            char c = resto[0];
            // Realiza as operacoes necessarias para a chamada recursiva
            add(pront, c, strlen(pront));
            rmv(resto, 0);
            subconjuntos(pront, resto);
            // Realiza o setup para que a segunda chamada seja chamada
            rmv(pront, strlen(pront));
            subconjuntos(pront, resto);
            // Realiza o backtrack
            add(resto, c, 0);
        }
}
 
int main()
{
    char restante[100] = "abcd01234";
    char pronto[100000] = "";

    subconjuntos(pronto, restante);
    printf("\n---------------------------------\n");

    return 0;
}