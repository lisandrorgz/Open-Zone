#include "Greek_31_Card_Game.h"
#include "MathBlitz 1.0.h"
#include "TICTAC~1.h"
#include "Vibora.h"




void imprimirTitulos() {
    printf("Elija un juego\n");
    printf("1- Juego de Matematicas\n");
    printf("2- Juego de Vibora\n");
    printf("3- Juego de BlackJack\n");
    printf("4- Jugar contra el bot para ganar saldo\n>>> ");
}

void jugarsegunEleccion(int pEleccion, int pSaldo) {
    switch (pEleccion)
    {
    case 1: mainmath(); break;
    case 2: menusnake(); break;
    case 3: menublackjack(); break;
    case 4: menutictac(); break;
    default: printf("Valor ingresado erroneo!"); break;
    }
}

void menuprovisoriodeJuegos(int pSaldo) {
    int ingreso;
    if (determinarSaldo(pSaldo)){
    do {
        imprimirTitulos();
        scanf("%d", &ingreso);
        jugarsegunEleccion(ingreso, pSaldo);
        printf("Seguir jugando? 1 si 0 no\n");
        scanf("%d", &ingreso);
       } while(pSaldo>0 && ingreso!=0);}
    else {
        ganarSaldo(pSaldo);
        printf("Ya hay saldo para seguir jugando!!!\n");
        menuprovisoriodeJuegos(pSaldo++);
    }
    
    
}

bool determinarSaldo(int pSaldo) {
    return (pSaldo > 0);
}

void ganarSaldo(int pSaldo) {
    printf("asd");
}
