#include "Greek_31_Card_Game.h"
#include "Matematicas.h"
#include "TICTAC~1.h"
#include "Vibora.h"




bool ganarFichas();
bool compararSaldo(int);

void imprimirTitulos() {
    printf("Elija un juego\n");
    printf("1- Juego de Matematicas\n");
    printf("2- Juego de Vibora\n");
    printf("3- Juego de BlackJack\n");
    printf("4- Jugar contra el bot para ganar saldo\n");
    printf("5- Salir\n>>> ");

}

void jugarsegunEleccion(int pEleccion, int * pSaldo) {
    switch (pEleccion)
    {
    case 1: mainmath(pSaldo); break;
    case 2: menusnake(pSaldo); break;
    case 3: menublackjack(); break;
    case 4: ganarSaldo(pSaldo); break;
    case 5: exit(0);
    default: printf("Valor ingresado erroneo!"); break;
    }
}

void menuprovisoriodeJuegos() {
    int ingreso;
    int contador = 1;
    do 
    {
        printf("<---\tTienes %d ficha/s\t--->\n", contador);
        imprimirTitulos();
        scanf("%d", &ingreso);
        jugarsegunEleccion(ingreso, &contador);
        if (saldoen0(contador)){
            printf("<---\tNo tienes mas fichas\t--->\n");
            if (ganarFichas()) ganarSaldo(&contador);
            else continue;
        }

    } while(contador>0); 

}
    

bool compararSaldo(int saldo) {
    return saldo > 0;
}

void ganarSaldo(int * pSaldo) {
    printf("Bot de Alexis");
}


bool ganarFichas() {
    int decision;
    printf("Para seguir jugando, tendras que ganar fichas contra el bot\nTambien puedes terminar tu turno\nChoose:\n(1) Jugar vs el bot\n(0) Terminar el turno\n>>> ");
    scanf("%d", &decision);
    return decision;
}





