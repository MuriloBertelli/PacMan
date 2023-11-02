#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char **mapa;
int linhas;
int colunas;

void lemapa()
{
	FILE *f;
	f = fopen("mapa.txt", "r");
	if (f == 0)
	{
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &linhas, &colunas);
	alocamapa();

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", mapa[i]);
	}

	fclose(f);
}

void alocamapa()
{
	mapa = malloc(sizeof(char *) * linhas);

	for (int i = 0; i < linhas; i++)
	{
		mapa[i] = malloc(sizeof(char) * colunas + 1);
	}
}

void liberamapa()
{
	for (int i = 0; i < linhas; i++)
	{
		free(mapa[i]);
	}

	free(mapa);
}

void imprimemapa()
{
	for (int i = 0; i < linhas; i++)
	{
		printf("%s\n", mapa[i]);
	}
}

int acabou()
{
	return 0;
}

void move(char direcao)
{
	int x;
	int y;

	// acha a posiçao do foge foge.
	for (int i = 0; i < colunas; i++)
	{
		for (int j = 0; j < linhas; j++)
		{
			if (mapa[i][j] == '@')
			{
				x = i;
				y = j;
				break;
			}
		}
	}

	switch (direcao)
	{
	case 'a':
		mapa[x][y - 1] = '@';
		break;
	case 'w':
		mapa[x - 1][y] = '@';
		break;
	case 's':
		mapa[x + 1][y] = '@';
		break;
	case 'd':
		mapa[x][y + 1] = '@';
		break;
		// dois pacman no mapa
	}
	mapa[x][y] = '.';
}

int main()
{

	lemapa();

	do
	{
		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while (!acabou());

	imprimemapa();

	liberamapa();
}