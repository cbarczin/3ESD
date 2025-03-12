/*Faça um programa que leia o tempo de treino (em minutos) de 10 atletas, mostrando
a cada um, o tempo de treino no formato hh:mm. (utilize a função do item a).
No final deve ser exibido o maior tempo de treino e quantos atletas o fizeram*/

#include <stdio.h>
#define TAM 10

void horario(int minutos, int *qntdHoras, int *minRestantes);
int divisaoInteira(int divisor, int dividendo, int *quociente, int *resto);

int main(void) {
    int i, j, maiorTempo = 0, qntdDeAtletas = 0, qntdDeHoras, minRestantes;
    int tempos[TAM];

    for(i=0;i<TAM;i++) {
        printf("Qual foi o tempo do(a) %d atleta?: ", i+1);
        scanf("%d", &tempos[i]);
    }

    for(j=0;j<TAM;j++) {
        horario(tempos[j], &qntdDeHoras, &minRestantes);
        printf("\nO %dº atleta realizou o treino em: %d horas e %d minutos!", j+1, qntdDeHoras, minRestantes);

        if(tempos[j] > maiorTempo) {
            maiorTempo = tempos[j];
            qntdDeAtletas = 1;
        } else {
            if(tempos[j] == maiorTempo) {
                qntdDeAtletas++;
            }
        }
    }

    printf("\n\nO maior tempo de treino registrado foi o de: %d minutos!", maiorTempo);
    printf("\nE %d atletas fizeram esse tempo de treino!", qntdDeAtletas);

    return 0;
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