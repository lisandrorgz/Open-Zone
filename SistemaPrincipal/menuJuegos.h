#include "Juegos/Matematicas.h"
#include "Juegos/Vibora.h"
#include "Juegos/TaTeTi.h"
#include "Juegos/BlackJack.h"
#include <windows.h>
#include <string.h>
#include "configMostrarCuenta.h"

typedef char string[100];

string usuarioActual;
int puntosUsuario;

void menuJuegos(string, int);
void menuSwitchJuegos(int, int);
bool ganarFichas();
bool compararSaldo(int);
void ganarSaldo(string, int);
bool ganarFichas();

void menuJuegos(string usuarioLogeado, int pPuntosUsuario) {
    int respuesta = 0;
    strcpy(usuarioActual, usuarioLogeado);
    puntosUsuario = pPuntosUsuario;
    if (compararSaldo(puntosUsuario)) {
        printf("\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t-*- Juegos -*-\n");
        printf("\t\t---------------------------------------------------------------------\n");
        if (!strcmp(usuarioLogeado, "admin")) {
            printf("\t\t\t\t0. Mostrar cuentas usuarios\n");
        }
        printf("\t\t\t\t1. Matematicas\n");
        printf("\t\t\t\t2. BlackJack\n");
        printf("\t\t\t\t3. Vibora\n");
        printf("\t\t\t\t4- TaTeTi vs Bot | Ganar Saldo\n");
        printf("\t\t\t\t5- Salir\n\t\t\t\t<---\tTienes %d ficha/s\t--->\n\t\t\t\t>>> ", puntosUsuario);
        scanf("%d", &respuesta);
        menuSwitchJuegos(respuesta, puntosUsuario);
    }
    else {
        printf("<---\tNo tienes mas fichas\t--->\n");
        if (ganarFichas()) ganarSaldo(usuarioActual, puntosUsuario);
    }
}

void menuSwitchJuegos(int pEleccion, int pPuntosUsuario) {
    switch (pEleccion) {
    case 0: procesarCuentasUsuarios(); system("pause"); system("cls"); break;
    case 1: mainmath(pPuntosUsuario); break;
    case 2: menublackjack(&pPuntosUsuario);break;
    case 3: menusnake(&pPuntosUsuario);break;
    case 4: ganarSaldo(usuarioActual, pPuntosUsuario); break;
    case 5: exit(0);
    default:
        system("cls");
        printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        menuJuegos(usuarioActual, puntosUsuario);
        break;
    }
}

bool compararSaldo(int pSaldo) {
    return pSaldo > 0;
}

void ganarSaldo(string pUsuarioActual, int pSaldo) {
    programaTateti(pUsuarioActual, &pSaldo);
}

bool ganarFichas() {
    int decision;
    printf("Para seguir jugando, tendras que ganar fichas contra el bot\nTambien puedes terminar tu turno\nChoose:\n(1) Jugar vs el bot\n(0) Terminar el turno\n>>> ");
    scanf("%d", &decision);
    return decision;
}





