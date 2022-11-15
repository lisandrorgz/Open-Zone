#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "configMostrarCuenta.h"

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos;
}tDatosUsuarios;

tDatosUsuarios pUsuarioLogeado;

void menuJuegos(int, string, string, int);
void menuSwitchJuegos(int, tDatosUsuarios);

void menuJuegos(int codCuenta, string nombreUsuario, string password, int puntos) {
    pUsuarioLogeado.codCuenta = codCuenta;
    strcpy(pUsuarioLogeado.nombreUsuario, nombreUsuario);
    strcpy(pUsuarioLogeado.password, password);
    pUsuarioLogeado.puntos = puntos;
    int respuesta = 0;
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t-*- Juegos -*-\n");
    printf("\t\t\t\t\t<---\tTienes %d fichas\t--->\n", pUsuarioLogeado.puntos);
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t1. Matematicas\n");
    printf("\t\t\t\t2. BlackJack\n");
    printf("\t\t\t\t3. Vibora\n");
    printf("\t\t\t\t4- TaTeTi vs Bot\n");
    printf("\t\t\t\t5- Salir\n");
    if (!strcmp(pUsuarioLogeado.nombreUsuario, "admin")) {
        printf("\t\t\t\t6. Mostrar cuentas registradas de usuarios\n");
        //* Aca van las cosas que puede hacer el admin...
    }
    printf("\t\t\t\t>>> ");
    scanf("%d", &respuesta);
    menuSwitchJuegos(respuesta, pUsuarioLogeado);
}

void menuSwitchJuegos(int pEleccion, tDatosUsuarios pUsuarioLogeado) {
    switch (pEleccion) {
        //* Los juegos reciben como parametro el struct de datos del usuarioLogeado...
    case 1: printf("\t\t\t\tAca Va el juego de Matematicas\n");/* ? Menu del juego */ break;
    case 2: printf("\t\t\t\tAca Va el juego de BlackJack\n");/* ? Menu del juego */ break;
    case 3: printf("\t\t\t\tAca Va el juego de Vivora\n");/* ? Menu del juego */ break;
    case 4: printf("\t\t\t\tAca Va el juego de Tateti\n");/* ? Menu del juego */ break;
    case 5: exit(0);
    case 6: procesarCuentasUsuarios(); system("pause"); system("cls"); break;
    default:
        system("cls");
        printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        menuJuegos(pUsuarioLogeado.codCuenta, pUsuarioLogeado.nombreUsuario, pUsuarioLogeado.password, pUsuarioLogeado.puntos);
        break;
    }
}