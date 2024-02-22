#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHAVE 256

int proximo_primo(int maior_que)
{
    int j;
    int primo = 0;
    for(int i = maior_que + 1; primo == 0; i++)
    {
        for(j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                break;
            }
        }
        if(j == i)
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
    printf("Digite a quantidade de nomes:");
    int quantidade;
    scanf("%d", &quantidade);
    char nomes[quantidade][50];
    FILE* file = fopen("..//nomes.txt", "r");
    if (file == NULL)
    {
        printf("Arquivo nao econtrado.");
        exit(0);
    }
    int i = 0;
    while(fscanf(file, "%s", nomes[i]) != EOF && i < quantidade)
    {
        i++;
    }

    int quantidade_nomes = proximo_primo(quantidade * 2);

    for(int i = 0; i < quantidade; i++)
    {
        printf("%s, %ld\n", nomes[i], hash(nomes[i], quantidade_nomes));
    }
    fclose(file);

}
