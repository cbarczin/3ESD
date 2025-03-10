/*2. A divisão no conjunto de inteiros, produz 2 valores: o quociente e o resto.
No entanto, quando o divisor é zero há duas situações: impossível – quando apenas o
divisor é zero e indeterminada quando o dividendo e o divisor são zeros.
a. Faça a função divisaoInteira(...) , que recebe dois valores (o dividendo e o
divisor) e dois endereços de variáveis, um para armazenar o quociente e outro
para o resto. Esta função realiza a operação de divisão, se for possível,
preenchendo adequadamente o quociente e o resto, e retorna o valor 1
(sucesso). Caso a operação não possa ser realizada, a função deve retornar 0,
quando a divisão é impossível e -1 quando é indeterminada.*/

#include <stdio.h>

int divisaoInteira(int divisor, int dividendo, int *quociente, int *resto);

int main(void) {
    int divisor, dividendo, quociente, resto, result;

    printf("Qual eh o dividendo?: ");
    scanf("%d", &dividendo);

    printf("Qual eh o divisor?: ");
    scanf("%d", &divisor);

    result = divisaoInteira(divisor, dividendo, &quociente, &resto);

    if(result == 0) {
        printf("Eh impossivel realizar essa operacao!");
    } else {
        if(result == -1) {
            printf("Essa operacao eh indeterminada!");
        } else {
            printf("\nDividendo: %d", dividendo);
            printf("\nDivisor: %d", divisor);
            printf("\nQuociente: %d", quociente);
            printf("\nResto: %d", resto);
        }
    }
}

int divisaoInteira(int divisor, int dividendo, int *quociente, int *resto) {
    if((divisor == 0) && (dividendo != 0)) {
        return 0;
    }

    if((divisor == 0) && (dividendo == 0)) {
        return -1;
    }

    *quociente = dividendo/divisor;
    *resto = dividendo%divisor;

    return 1;
}