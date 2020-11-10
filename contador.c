#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
/*
    Esse programa lê um vetor de 50 números inteiros, cada Inteiro i com limite 0 <= i <= 99. 
    Depois imprime o número de ocorrências de cada elemento do vetor, na ordem em que foram lidos. 
    Porém, se um elemento já foi computado/exibido, não deverá aparecer novamente.

    Para compilar: gcc -o contador contador.c
    Para executar: ./contador < arquivo_entrada > arquivo_saida
    O arquivo deve conter 50 numeros separados por um espaço no seguinte formato:
        numero1 numero2 ... numero50
    A saida do programa é
        numero1 quantidade1 \n
        numero2 quantidade2 \n
                ...
        numeron quantidaden \n
*/

typedef struct
{
    int numero, quantidade;
} valores;

void retorna_vetor_aleatorio(int *arr)
{
    int i;

    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
}

void le_vetor(int *aux, FILE *fp)
{
    int i;
    char linha[500];
    char *str = NULL;

    if (fp == NULL)
    {
        printf("%s\n", "Erro na abertura do arquivo!");
        exit(1);
    }
    fgets(linha, 500, fp);

    i = 0;

    str = strtok(linha, " ");

    while (str != NULL)
    {
        aux[i] = atoi(str);
        if (aux[i] < 0 || aux[i] > 99)
        {
            printf("%s\n", "A lista contém pelo menos um valor que não está no intervalo de n >=0 e n<=99");
            exit(1);
        }
        str = strtok(NULL, " \n");
        i++;
    }

    if (i < MAX_SIZE || i > MAX_SIZE)
    {
        printf("%s\n", "A quantidade de valores é menor ou maior que 50!");
        exit(1);
    }
}

void verifica_lista(valores *arr, int numero, int quantidade, int *size)
{
    for (int i = 0; i < *size; i++)
    {
        if (arr[i].numero == numero && arr[i].quantidade != 0)
        {
            return;
        }
    }

    arr[*(size)].numero = numero;
    arr[*(size)].quantidade = quantidade;
    *size += 1;
}

void inicializa_vetor(valores *repetidos)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        repetidos[i].numero = 0;
        repetidos[i].quantidade = 0;
    }
}

void cria_lista_quantidades(valores *repetidos, int *arr, int *size)
{

    int i, j, count = 0;

    for (i = 0; i < MAX_SIZE; i++)
    {
        count = 1;
        for (j = i + 1; j < MAX_SIZE; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        verifica_lista(repetidos, arr[i], count, size);
    }
}

void imprime_quantidades(valores *repetidos, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d %d \n", repetidos[i].numero, repetidos[i].quantidade);
    }
}

int main(int argc, char *argv[])
{
    int arr[MAX_SIZE];
    valores repetidos[MAX_SIZE];
    int i, j, size = 0;

    le_vetor(arr, stdin);

    inicializa_vetor(repetidos);

    cria_lista_quantidades(repetidos, arr, &size);

    imprime_quantidades(repetidos, size);

    return 0;
}
