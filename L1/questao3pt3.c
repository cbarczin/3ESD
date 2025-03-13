/*Incluir o nome na struct, 
ordenar o vetor por tempo/nome 
métodos possíveis: bolha, seleção (menor ou maior) , insertion*/

#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct {
    char nome[50];
    int tempo;
} TAtleta;

typedef struct No {
    char nome[50];
    int tempo;
    struct No *prox;
} TNo;

void horario(int minutos, int *qntdHoras, int *minRestantes);
int divisaoInteira(int divisor, int dividendo, int *quociente, int *resto);
void trocaDeLugar(TAtleta *valor1, TAtleta *valor2);
void ordenacaoDeAtletasTempo(TAtleta registros[]);
void ordenacaoDeAtletasNome(TAtleta registros[]);
void exibirOrdenacao(TAtleta registros[]);


int main(void) {
    int i, j, maiorTempo = 0, qntdDeAtletas = 0, qntdDeHoras, minRestantes;
    TAtleta registros[TAM];

    for(i=0;i<TAM;i++) {
        printf("Qual eh o nome do %dº atleta?: ", i+1);
        scanf("%s", registros[i].nome);
        printf("Qual foi o tempo do(a) %d atleta?: ", i+1);
        scanf("%d", &registros[i].tempo);
    }

    for(j=0;j<TAM;j++) {
        horario(registros[j].tempo, &qntdDeHoras, &minRestantes);
        printf("\nO(A) %s realizou o treino em: %d horas e %d minutos!", registros[j].nome, qntdDeHoras, minRestantes);

        if(registros[j].tempo > maiorTempo) {
            maiorTempo = registros[j].tempo;
            qntdDeAtletas = 1;
        } else {
            if(registros[j].tempo == maiorTempo) {
                qntdDeAtletas++;
            }
        }
    }

    printf("\n\nO maior tempo de treino registrado foi o de: %d minutos!", maiorTempo);
    printf("\nE %d atletas fizeram esse tempo de treino!", qntdDeAtletas);

    printf("\n\nTempos ordenados do menor para o maior: ");
    ordenacaoDeAtletasTempo(registros);

    printf("\n\nOrdenacao por nomes: ");
    ordenacaoDeAtletasNome(registros);

    return 0;
}

void trocaDeLugar(TAtleta *valor1, TAtleta *valor2) {
    TAtleta temporario = *valor1;
    *valor1 = *valor2;
    *valor2 = temporario;
}

void ordenacaoDeAtletasTempo(TAtleta registros[]) {
    int i, j;
    int houveTroca;
    
    for(i=0;i<TAM;i++) {
        houveTroca=0;
        for(j=0;j<TAM-1;j++) {
            if(registros[j].tempo > registros[j+1].tempo) {
                 trocaDeLugar(&registros[j], &registros[j+1]);
                 houveTroca = 1;
            }
        }

        if(houveTroca == 0) {
            break;
        }
    }

    exibirOrdenacao(registros);

}

void ordenacaoDeAtletasNome(TAtleta registros[]) {
    int i, j;
    int houveTroca;
    
    for(i=0;i<TAM;i++) {
        houveTroca=0;
        for(j=0;j<TAM-1;j++) {
            if(strcmp(registros[j].nome, registros[j+1].nome) >= 0) {
                trocaDeLugar(&registros[j], &registros[j+1]);
                houveTroca = 1;
            }
        }

        if(houveTroca == 0) {
            break;
        }
    }

    exibirOrdenacao(registros);

}

void exibirOrdenacao(TAtleta registros[]) {
    int i;

    for(i=0;i<TAM;i++) {
        printf("\n%s tempo: %d", registros[i].nome, registros[i].tempo);
    }
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