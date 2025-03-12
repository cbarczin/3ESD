/*3. Construa o programa a seguir.
a. Faça a função horario que receba um parâmetro (inteiro por valor) com o total de
minutos de um evento e receba também dois parâmetros (inteiros por referência) no
qual deve preencher a quantidade de hora e de minutos equivalente. Por exemplo:
145 minutos equivale a 2 h e 25 min. Esta função deverá OBRIGATORIAMENTE chamar
a função DivisaoInteira*/

#include <stdio.h>

void horario(int minutos, int *qntdHoras, int *minRestantes);
int divisaoInteira(int divisor, int dividendo, int *quociente, int *resto);

int main(void) {
    int minutos, qntdHoras, minRestantes;

    printf("Informe o tempo em minutos: ");
    scanf("%d", &minutos);

    horario(minutos, &qntdHoras, &minRestantes);

    printf("O tempo de: %d minutos é equivalente a: %d horas e %d minutos", minutos, qntdHoras, minRestantes);

}

void horario(int minutos, int *qntdHoras, int *minRestantes) {
    divisaoInteira(60, minutos, qntdHoras, minRestantes);
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