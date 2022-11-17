#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Matematicas.h"
#include "configMostrarCuenta.h"
//#include "mostrarListaPuntajes.h"

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; 
}eDatosUsuario;

bool ganarFichas();
void menuJuegos(int, string, string, int);
void menuSwitchJuegos(int, eDatosUsuario);

void menuJuegos(int a, string b, string c, int d) {
    eDatosUsuario pUserlogeado;
    pUserlogeado.codCuenta = a;
    strcpy(pUserlogeado.nombreUsuario, b);
    strcpy(pUserlogeado.password, c);
    pUserlogeado.puntos = d;
    int respuesta;
        printf("\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\tBienvenido %s!!!\n", pUserlogeado.nombreUsuario);
        //printf("\t\t\t\t\t\t-*- Juegos -*-\n");
        printf("\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t1. Ganar Puntos con un Juego de Matematicas.\n");
        /* printf("\t\t\t\t2. BlackJack\n");
        printf("\t\t\t\t3. Ahorcado\n");
        printf("\t\t\t\t4- TaTeTi vs Bot\n"); */
        printf("\t\t\t\t2. Ver tabla global de jugadores\n");
        printf("\t\t\t\t3- Salir\n");
        if (!strcmp(pUserlogeado.nombreUsuario, "admin")) {
            printf("\t\t\t\t6. Mostrar cuentas registradas de usuarios\n");
        }
        printf("\t\t\t\t>>> ");
        scanf("%d", &respuesta);
        menuSwitchJuegos(respuesta, pUserlogeado);
}

void menuSwitchJuegos(int pEleccion, eDatosUsuario pUserlogeado) {
    switch (pEleccion) {
        case 1: mainmath(&pUserlogeado); break;
        case 2: procesarMostradoPuntaje(); system("pause"); system("cls"); break;
        case 3: exit(0);
        case 6: 
            if (!strcmp(pUserlogeado.nombreUsuario, "admin")) {
                procesarCuentasUsuarios(); system("pause"); system("cls");
            }
            break;
    default:
        system("cls");
        printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        break;
    }
}