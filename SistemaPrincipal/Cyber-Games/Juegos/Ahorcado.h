// Learnprogramo-programming made simple
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define CANT_PALABRAS 11

typedef char str50[50];
str50 a;
str50 palabras[CANT_PALABRAS] = {{"cabeza"}, {"computadora"}, {"espacio"}, {"clavo"}, {"celular"}, {"tetera"}, {"coliflor"}, {"televisor"}, {"competencia"}, {"lodo"}, {"titanio"}};
char d = '_', alpha, ant[11], b[11];
int ingreso, palabraAzar, i, j, c, count, ans, flag1, flag2, *ptr;

void seguirJugando();
void iniciar();
void limpiarArreglos();
void menuahorcado(tDatosUsuario *), seguirJugando(), iniciar();

void menuahorcado(tDatosUsuario *Userahorcado)
{
	do
	{
		iniciar();
		printf("\n\n\t\t\t\t\t\t ** AHORCADO **\n");
		printf("\n\t\t\t\t\t\t**************\t\t\t");
		printf("\n\t\t\t\t\t\t..............\n\n\t\t\t\t\t\t");
		for (j = 0; j < c; j++)
		{
			printf("%c ", d);
			b[j] = d;
		}
		printf("\n\n\t\t\t\t\t\t..............\t\t\t");
		printf("\n\n\t\t\t\t\t\t**************");

		while (count < c)
		{
			flag1 = 0;
			flag2 = 1;
			while (flag2)
			{
				printf("\n\n\n\n\t\t\t\tIngresa un caracter: ");
				alpha = getche();
				for (i = 0; i < c; i++)
				{
					if (alpha == ant[i])
					{
						printf("\n\n\t\tEl caracter %c ya no se puede volver a repetir! vuelva a ingresar otro caracter", ant[i]);
					}

					else
					{
						flag2 = 0;
						if (alpha == a[i])
						{
							b[i] = a[i];
							ant[i] = a[i];
							flag1 = 1;
							ans++;
							break;
						}
					}
				}
			}

			printf("\n\n\t\t\t\t\t\t ** AHORCADO **\n");
			printf("\n\t\t\t\t\t\t**************\t\t\t");
			printf("\n\t\t\t\t\t\t..............\n\n\t\t\t\t\t\t");
			fflush(stdin);
			for (i = 0; i < c; i++)
				printf("%c ", b[i]);
			printf("\n\n\t\t\t\t\t\t..............\t\t\t");
			printf("\n\n\t\t\t\t\t\t**************");

			if (flag1 == 0)
			{
				count++;
				printf("\n\n\t\t\t\t\t  %c es una entrada incorrecta", alpha);
				printf("\n\t\t\t\t\t  Tienes %d intentos mas", c - count);
			}

			else
			{
				printf("\n\n\t\t\t\t\t\tAcertaste! Wow...");
				printf("\n\t\t\t\t\tQuedan %d caracteres por adivinar!", c - ans);
			}
			if (ans == c)
				break;
		}
		if (ans == c)
		{
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t\tGanaste!");
			printf("\n\n\t\t\t\t\t\t\t\033[1;32m+3 Puntos\n\033[0m");
			Userahorcado->puntos += 3;
			sleep(3);
			seguirJugando();
			sleep(2);
		}

		else
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t Perdiste!\n\t\t\t\t\t\t     **Estas ahorcado**\t");
			printf("\n\n\t\t\t\t\t\t        \033[1;31m-1 Ficha\n\033[0m");
			sleep(2);

			Userahorcado->saldo -= 1;
			if (Userahorcado->saldo == 0)
			{
				sleep(1);
				printf("\n\t\t\t\t\tNo te quedan mas fichas!\n");
				printf("\n\t\t\t\t\tSaliendo del juego...\n");
				sleep(2);
				system("cls");
			}
			else
				seguirJugando();
		}

	} while (ingreso);
	system("cls");
	printf("\n\t\t\t\t\t\tSaliendo del juego...\n");
	sleep(2);
	system("cls");
}

void seguirJugando()
{
	printf("\n\n\n\t\t\t\t\t\t  Seguir jugando? (1/0): ");
	fflush(stdin);
	scanf("%d", &ingreso);
}

void iniciar()
{
	system("cls");
	limpiarArreglos();
	srand(time(NULL));
	palabraAzar = 0 + rand() % 10;
	count = 0;
	ans = 0;
	flag1 = 0;
	strcpy(a, palabras[palabraAzar]);
	c = strlen(a);
}
void limpiarArreglos()
{
	for (i = 0; i < CANT_PALABRAS; i++)
	{
		a[i] = NULL;
		ant[i] = NULL;
		b[i] = NULL;
	}
}
