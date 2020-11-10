# contador-repetidos
Código para fins de exercício de nivelamento em C

# Descrição
Esse programa lê um vetor de 50 números inteiros, cada Inteiro i com limite 0 <= i <= 99. Depois imprime o número de ocorrências de cada elemento do vetor, na ordem em que foram lidos.Porém, se um elemento já foi computado/exibido, não deverá aparecer novamente.

# Execução

>gcc -o contador contador.c

>./contador < arquivo_entrada > arquivo_saida
    
    O arquivo deve conter 50 numeros separados por um espaço no seguinte formato:
    
>      numero1 numero2 ... numero50

    A saida do programa é
    
>      numero1 quantidade1 \n
>      numero2 quantidade2 \n
>             ...
>      numeron quantidaden \n
