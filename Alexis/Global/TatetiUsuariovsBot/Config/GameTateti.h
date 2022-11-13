#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef char string[100];

char solucion[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void programaTateti();
void pedirDatosPlayer();
void datosBotAdmin();
void ponerXoOUsuario(int);
void ponerXoOBot(int);
int checarSiGano();
void mostrarTateti();

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

void programaTateti(){
    printf("Contra quien tengo que jugar?: ");
    scanf("%s", &nombrePlayer[1]);
    //? strcpy(nombrePlayer[1], "Nombre del Usuario Aca del Login (Mauri)");
    strcpy(nombrePlayer[2], "Bot - Administrador");
    system("cls");
    do{
    mostrarTateti();
    player--;
    marcar = (player == 1) ? 'X' : 'O';
    pedirDatosPlayer();
    ponerXoOUsuario(numElegidoPlayer);
    verSiGanoAlguien = checarSiGano();
        if (verSiGanoAlguien != 1) {
            player++;
            marcar = (player == 2) ? 'O' : 'X';
            datosBotAdmin(numElegidoPlayer);
            ponerXoOBot(numElegidoBot);
            verSiGanoAlguien = checarSiGano();
        }
    } while(verSiGanoAlguien == -1);
    mostrarTateti();
    if (verSiGanoAlguien == 1) {
        if (player == 1) {
            printf("\033[0;33mGanaste 5 Puntos %s!!\033[0m\n", nombrePlayer[player]);
            //? y si quiere volver a jugar es llamar a la funcion programaTateti y añadir un parametro para recibir nombre
            //TODO: Aca va los puntos porque gano el usuario...
        }
        else printf("Gano %s.\n", nombrePlayer[player]);
    }
    if (verSiGanoAlguien == 0) printf("\t\t\t==>\aGame Over");
}

void pedirDatosPlayer(){
    printf("\t\t\t%s, ingrese un numero: ", nombrePlayer[1]);
	scanf("%d", &numElegidoPlayer);
}

void datosBotAdmin(int pNumElegido){
    srand(time(NULL));
    numElegidoBot = 1 + rand() % 9;
    printf("\t\t\t%s: Me Toca a mi!\n", nombrePlayer[2]);
    Sleep(1);
    printf("\t\t\t%s: Dejame pensar bien...\n", nombrePlayer[2]);
    Sleep(1);
    printf("\t\t\t%s: Listo! Tu turno...\n", nombrePlayer[2]);
    Sleep(1);
}

void ponerXoOUsuario(int numElegido){
    if (numElegido == 1 && solucion[1] == '1') solucion[1] = marcar;
	else if (numElegido == 2 && solucion[2] == '2') solucion[2] = marcar;
	else if (numElegido == 3 && solucion[3] == '3') solucion[3] = marcar;
	else if (numElegido == 4 && solucion[4] == '4') solucion[4] = marcar;
	else if (numElegido == 5 && solucion[5] == '5') solucion[5] = marcar;
	else if (numElegido == 6 && solucion[6] == '6') solucion[6] = marcar;
	else if (numElegido == 7 && solucion[7] == '7') solucion[7] = marcar;
	else if (numElegido == 8 && solucion[8] == '8') solucion[8] = marcar;
	else if (numElegido == 9 && solucion[9] == '9') solucion[9] = marcar;
	else{
	    printf("\t\t\t\t\033[0;31m[!]Error[!]\033[0m\n");
        printf("\t\t\t%s, ingrese otro numero: ", nombrePlayer[1]);
	    scanf("%d", &numElegidoPlayer);
        ponerXoOUsuario(numElegidoPlayer);
	}
}

void ponerXoOBot(int numElegido){
    if (numElegido == 1 && solucion[1] == '1') solucion[1] = marcar;
	else if (numElegido == 2 && solucion[2] == '2') solucion[2] = marcar;
	else if (numElegido == 3 && solucion[3] == '3') solucion[3] = marcar;
	else if (numElegido == 4 && solucion[4] == '4') solucion[4] = marcar;
	else if (numElegido == 5 && solucion[5] == '5') solucion[5] = marcar;
	else if (numElegido == 6 && solucion[6] == '6') solucion[6] = marcar;
	else if (numElegido == 7 && solucion[7] == '7') solucion[7] = marcar;
	else if (numElegido == 8 && solucion[8] == '8') solucion[8] = marcar;
	else if (numElegido == 9 && solucion[9] == '9') solucion[9] = marcar;
	else{
	    numElegidoBot = 1 + rand() % 10;
        ponerXoOBot(numElegidoBot);
	}
}

int checarSiGano(){
    if (solucion[1] == solucion[2] && solucion[2] == solucion[3]) return 1;
    else if (solucion[4] == solucion[5] && solucion[5] == solucion[6]) return 1;
    else if (solucion[7] == solucion[8] && solucion[8] == solucion[9]) return 1;
    else if (solucion[1] == solucion[4] && solucion[4] == solucion[7]) return 1;
    else if (solucion[2] == solucion[5] && solucion[5] == solucion[8]) return 1;
    else if (solucion[3] == solucion[6] && solucion[6] == solucion[9]) return 1;
    else if (solucion[1] == solucion[5] && solucion[5] == solucion[9]) return 1;
    else if (solucion[3] == solucion[5] && solucion[5] == solucion[7]) return 1;
    else if (solucion[1] != '1' && solucion[2] != '2' && solucion[3] != '3' && solucion[4] != '4' && solucion[5] != '5' && solucion[6] != '6' && solucion[7] != '7' && solucion[8] != '8' && solucion[9] != '9') return 0;
    else return -1;
}

void mostrarTateti(){
    system("cls");
    printf("\n\n\t\t\t\t  -*- Tateti -*-\n\n");
    printf("\t\t\t  %s (X)  vs  %s (O)\n\n\n", nombrePlayer[1], nombrePlayer[2]);
    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n", solucion[1], solucion[2], solucion[3]);
    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n", solucion[4], solucion[5], solucion[6]);
    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n", solucion[7], solucion[8], solucion[9]);
    printf("\t\t\t\t     |     |     \n\n");
}