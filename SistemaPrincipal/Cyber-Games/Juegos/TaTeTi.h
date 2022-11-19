#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "structDatosUsuarioTDA.h"

tDatosUsuario *usuario;
string nombre_user;
char solucion[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void programaTateti(tDatosUsuario *);
char enteroACaracter(int);
void reiniciarJuego();
void pedirDatosPlayer();
void datosBotAdmin();
void ponerXoOUsuario(int);
void ponerXoOBot(int);
int checarSiGano();
void mostrarTateti();
bool saldoen0(int);

int player = 2;
bool bandera;
int verSiGanoAlguien;
//# Datos del Player...
string nombrePlayer[3];
int numElegidoPlayer;
//# Datos del BotAdmin...
int numElegidoBot;
//# Datos del Tateti
char marcar;
int ingreso;

void programaTateti(tDatosUsuario *Usertateti)
{

    usuario = Usertateti;
    strcpy(nombrePlayer[2], "Bot - Administrador");
    system("cls");
    do
    {
        do
        {
            mostrarTateti();
            player--;
            marcar = (player == 1) ? 'X' : 'O';
            pedirDatosPlayer();
            ponerXoOUsuario(numElegidoPlayer);
            verSiGanoAlguien = checarSiGano();
            if (verSiGanoAlguien != 1)
            {
                player++;
                marcar = (player == 2) ? 'O' : 'X';
                datosBotAdmin(numElegidoPlayer);
                ponerXoOBot(numElegidoBot);
                verSiGanoAlguien = checarSiGano();
            }
        } while (verSiGanoAlguien == -1);
        mostrarTateti();
        if (verSiGanoAlguien == 1)
        {
            if (player == 1)
            {
                printf("\n\t\t\t\t\t  \033[1;32mGanaste 1 Ficha y 2 Puntos!!\033[0m\n");
                sleep(2);
                usuario->saldo += 1;
                usuario->puntos += 2;
            }
            else
            {
                printf("\t\t\t\t\tGano %s.\n", nombrePlayer[player]);
                usuario->saldo -= 1;
            }
            reiniciarJuego();
        }
        else
        {
            printf("\t\t\t\t\t\t==>\aGame Over | Empate!");
            reiniciarJuego();
        }
        if (!(saldoen0(usuario->saldo)))
            printf("\n\t\t\t\t\t    Seguir jugando? (1/0): ");
        scanf("%d", &ingreso);
        system("cls");
    } while (ingreso && (usuario->saldo) != 0);
    printf("\n\t\t\t\t\tSaliendo del juego...");
    sleep(1);
    system("cls");
}

char enteroACaracter(int numero)
{
    return numero + '0';
}

void reiniciarJuego()
{
    int i;
    char aux;
    for (i = 1; i < 10; i++)
    {
        aux = enteroACaracter(i);
        solucion[i] = aux;
    }
    player = 2;
}

void pedirDatosPlayer()
{
    printf("\n\t\t\t\t\t%s, ingrese un numero: ", usuario->nombreUsuario);
    scanf("%d", &numElegidoPlayer);
}

void datosBotAdmin(int pNumElegido)
{
    srand(time(NULL));
    numElegidoBot = 1 + rand() % 9;
    printf("\t\t\t\t\t%s: Me Toca a mi!\n", nombrePlayer[2]);
    sleep(1);
    printf("\t\t\t\t\t%s: Dejame pensar bien...\n", nombrePlayer[2]);
    sleep(1);
    printf("\t\t\t\t\t%s: Listo! Tu turno...\n", nombrePlayer[2]);
    sleep(1);
}

void ponerXoOUsuario(int numElegido)
{
    if (numElegido == 1 && solucion[1] == '1')
        solucion[1] = marcar;
    else if (numElegido == 2 && solucion[2] == '2')
        solucion[2] = marcar;
    else if (numElegido == 3 && solucion[3] == '3')
        solucion[3] = marcar;
    else if (numElegido == 4 && solucion[4] == '4')
        solucion[4] = marcar;
    else if (numElegido == 5 && solucion[5] == '5')
        solucion[5] = marcar;
    else if (numElegido == 6 && solucion[6] == '6')
        solucion[6] = marcar;
    else if (numElegido == 7 && solucion[7] == '7')
        solucion[7] = marcar;
    else if (numElegido == 8 && solucion[8] == '8')
        solucion[8] = marcar;
    else if (numElegido == 9 && solucion[9] == '9')
        solucion[9] = marcar;
    else
    {
        printf("\t\t\t\t\t\t\033[0;31m[!]Error[!]\033[0m\n");
        printf("\t\t\t\t\t%s, ingrese otro numero: ", usuario->nombreUsuario);
        scanf("%d", &numElegidoPlayer);
        ponerXoOUsuario(numElegidoPlayer);
    }
}

void ponerXoOBot(int numElegido)
{
    if (numElegido == 1 && solucion[1] == '1')
        solucion[1] = marcar;
    else if (numElegido == 2 && solucion[2] == '2')
        solucion[2] = marcar;
    else if (numElegido == 3 && solucion[3] == '3')
        solucion[3] = marcar;
    else if (numElegido == 4 && solucion[4] == '4')
        solucion[4] = marcar;
    else if (numElegido == 5 && solucion[5] == '5')
        solucion[5] = marcar;
    else if (numElegido == 6 && solucion[6] == '6')
        solucion[6] = marcar;
    else if (numElegido == 7 && solucion[7] == '7')
        solucion[7] = marcar;
    else if (numElegido == 8 && solucion[8] == '8')
        solucion[8] = marcar;
    else if (numElegido == 9 && solucion[9] == '9')
        solucion[9] = marcar;
    else
    {
        numElegidoBot = 1 + rand() % 10;
        ponerXoOBot(numElegidoBot);
    }
}

int checarSiGano()
{
    if (solucion[1] == solucion[2] && solucion[2] == solucion[3])
        return 1;
    else if (solucion[4] == solucion[5] && solucion[5] == solucion[6])
        return 1;
    else if (solucion[7] == solucion[8] && solucion[8] == solucion[9])
        return 1;
    else if (solucion[1] == solucion[4] && solucion[4] == solucion[7])
        return 1;
    else if (solucion[2] == solucion[5] && solucion[5] == solucion[8])
        return 1;
    else if (solucion[3] == solucion[6] && solucion[6] == solucion[9])
        return 1;
    else if (solucion[1] == solucion[5] && solucion[5] == solucion[9])
        return 1;
    else if (solucion[3] == solucion[5] && solucion[5] == solucion[7])
        return 1;
    else if (solucion[1] != '1' && solucion[2] != '2' && solucion[3] != '3' && solucion[4] != '4' && solucion[5] != '5' && solucion[6] != '6' && solucion[7] != '7' && solucion[8] != '8' && solucion[9] != '9')
        return 0;
    else
        return -1;
}

void mostrarTateti()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t -*- TATETI -*-\n\n");
    printf("\t\t\t\t\t%s (X)  vs  %s (O)\n\n\n", usuario->nombreUsuario, nombrePlayer[2]);
    printf("\t\t\t\t\t             |     |     \n");
    printf("\t\t\t\t\t          %c  |  %c  |  %c \n", solucion[1], solucion[2], solucion[3]);
    printf("\t\t\t\t\t        _____|_____|_____\n");
    printf("\t\t\t\t\t             |     |     \n");
    printf("\t\t\t\t\t          %c  |  %c  |  %c \n", solucion[4], solucion[5], solucion[6]);
    printf("\t\t\t\t\t        _____|_____|_____\n");
    printf("\t\t\t\t\t             |     |     \n");
    printf("\t\t\t\t\t          %c  |  %c  |  %c \n", solucion[7], solucion[8], solucion[9]);
    printf("\t\t\t\t\t             |     |     \n\n");
}

bool saldoen0(int pSaldo)
{
    return (pSaldo == 0);
}