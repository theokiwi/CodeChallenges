/******************************************************************************
 * 
 *  ETIQUETAS DE NOEL - BEECROWD
 *  
 *  Autor: Theo Diniz Viana
 *  Nota: 100/100
 *  Linguagem: C99
 *  Data: 21/03/2025
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *idioma;
    char *mensagem;
} Carta;

typedef struct
{
    char *idioma;
    char *nome;
} Destinatario;

Carta *recebeCarta()
{
    Carta *carta = malloc(sizeof(Carta));
    carta->idioma = malloc(sizeof(char) * 100);
    carta->mensagem = malloc(sizeof(char) * 100);

    scanf((" %[^\n]"), carta->idioma);
    scanf((" %[^\n]"), carta->mensagem);
    return carta;
}

Destinatario *recebeDestinatario()
{
    Destinatario *destino = malloc(sizeof(Destinatario));
    destino->idioma = malloc(sizeof(char) * 100);
    destino->nome = malloc(sizeof(char) * 100);

    scanf((" %[^\n]"), destino->nome);
    scanf((" %[^\n]"), destino->idioma);
    return destino;
}

void comparar(Destinatario **destinos, Carta **cartas, int qntCartas, int qntDestinos)
{
    for (int j = 0; j < qntDestinos; j++)
    {
        char *lingua = destinos[j]->idioma;
        for (int i = 0; i < qntCartas; i++)
        {
            if (strcmp(cartas[i]->idioma, lingua) == 0)
            {
                printf("%s\n%s\n", destinos[j]->nome, cartas[i]->mensagem);
            }
        }
    }
}

int main()
{
    int quantLinguas = 0;
    scanf(" %d", &quantLinguas);
    Carta **cartas = malloc(quantLinguas * sizeof(Carta *));
    for (int j = 0; j < quantLinguas; j++)
    {
        cartas[j] = recebeCarta();
    }

    int destinatarios = 0;
    scanf(" %d", &destinatarios);

    // Alocando memoria para destinatarios
    Destinatario **destinos = malloc(destinatarios * sizeof(Destinatario *));
    for (int f = 0; f < destinatarios; f++)
    {
        destinos[f] = recebeDestinatario();
    }

    comparar(destinos, cartas, quantLinguas, destinatarios);

    // Libera memoria
    for (int l = 0; l < quantLinguas; l++)
    {
        free(cartas[l]->idioma);
        free(cartas[l]->mensagem);
        free(cartas[l]);
    }
    free(cartas);

    for (int m = 0; m < destinatarios; m++)
    {
        free(destinos[m]->idioma);
        free(destinos[m]->nome);
        free(destinos[m]);
    }
    free(destinos);
}