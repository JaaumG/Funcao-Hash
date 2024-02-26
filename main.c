#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define CHAVE 31
#define MAX_ARRAY_SIZE 10000

int proximo_primo(int maior_que)
{
    int j;
    int primo = 0;
    for (int i = maior_que; primo == 0; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j == i)
        {
            primo = i;
        }
    }
    return primo;
}


long hash(char* str, int mod)
{
    long hash_value = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        hash_value = ((hash_value * CHAVE) + str[i]) % mod;
    }

    return hash_value;
}



void main()
{
    int quantidade;
    char nome[100];
    int colisoes = 0;
    printf("Digite a quantidade de nomes:");
    scanf("%d", &quantidade);
    FILE* file = fopen("..//nomes.txt", "r");
    if (file == NULL)
    {
        printf("Arquivo nao econtrado.");
        exit(0);
    }
    int mod = proximo_primo(quantidade);
    int array_colisoes[MAX_ARRAY_SIZE] = {0};
    for (int i = 0; fscanf(file, "%s", nome) != EOF && i < quantidade; i++)
    {
        long hash_value = hash(nome, mod);
        if (array_colisoes[hash_value] == 0)
            array_colisoes[hash_value] = 1;
        else
            colisoes+=1;
        printf("%s, %lu\n", nome, hash_value);
    }
    printf("\nNumero primo utilizado: %d", mod);
    printf("\nChave: %d", CHAVE);
    printf("\nColisoes: %d", colisoes);
    fclose(file);
}
