#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100
#define MAX_CARACTERES 200

typedef struct {
    int n;
    int max;
    char **linhas;
} Fila;

void insereOrdenado(Fila *fila, char *linha) {
    if (fila->n == fila->max) {
        printf("Fila cheia\n");
        return;
    }

    int pos = 0;
    while (pos < fila->n && strlen(fila->linhas[pos]) >= strlen(linha)) {
        pos++;
    }

    for (int i = fila->n; i > pos; i--) {
        fila->linhas[i] = fila->linhas[i - 1];
    }

    fila->linhas[pos] = malloc((strlen(linha) + 1) * sizeof(char));
    if (fila->linhas[pos] == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }
    strcpy(fila->linhas[pos], linha);
    
    fila->n++;
}

void printaFila(Fila *fila) {
    for (int i = 0; i < fila->n; i++) {
        printf("%s", fila->linhas[i]);
        if (i < fila->n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    Fila fila;
    fila.n = 0;
    fila.max = MAX_LINHAS;
    fila.linhas = malloc(fila.max * sizeof(char *));
    if (fila.linhas == NULL) {
        printf("Erro de alocação\n");
        return 1;
    }

    int quantLinha;
    scanf("%d", &quantLinha);
    getchar();  

    char linhasPre[MAX_CARACTERES];

    for (int i = 0; i < quantLinha; i++) {
        fgets(linhasPre, sizeof(linhasPre), stdin);
        linhasPre[strcspn(linhasPre, "\n")] = '\0';  

        char *token = strtok(linhasPre, " ");
        while (token != NULL) {
            char *linha = malloc((strlen(token) + 1) * sizeof(char));
            if (linha == NULL) {
                printf("Erro de alocação\n");
                return 1;
            }
            strcpy(linha, token);
            insereOrdenado(&fila, linha);
            token = strtok(NULL, " ");
        }
    }

    printaFila(&fila);

    for (int i = 0; i < fila.n; i++) {
        free(fila.linhas[i]);
    }
    free(fila.linhas);

    return 0;
}
