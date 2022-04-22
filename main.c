#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct turma {
    float nota;
    struct turma *prox;
};

typedef struct turma Turma;

Turma *inicializa (void);
Turma *insere (Turma *turma, float nota);
void calcula_media (Turma *turma, float *media);

int main()
{
    setlocale(LC_ALL, "portuguese");

    Turma *turma;
    int contador, quantidade_alunos;
    float media;

    turma = inicializa();

    printf("Programa para calcular as médias dos alunos!\nUsando Lista Encadeada\n\n");
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidade_alunos);

    for (contador = 0; contador < quantidade_alunos; contador++) {
        float valor;

        printf("Digite a nota do(a) aluno(a) %d: ", contador + 1);
        scanf("%f", &valor);

        turma = insere(turma, valor);
    }

    calcula_media(turma, &media);
    printf("\nA média das notas da turma é: %.2f\n", media);

    return 0;
}

Turma *inicializa (void) {
    return NULL;
}

Turma *insere (Turma *turma, float nota) {
    Turma *novo_elemento = (Turma*)malloc(sizeof(Turma));

    novo_elemento->nota = nota;
    novo_elemento->prox = turma;

    return novo_elemento;
}

void calcula_media (Turma *turma, float *media) {
    Turma *percorre;
    int quantidade = 0;
    float soma;

    for (percorre = turma; percorre != NULL; percorre = percorre->prox) {
        quantidade++;
    	soma += percorre->nota ;
	}

    *media = soma / quantidade;
}
