#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "configLoginCuenta.h"
#include "configRegistroCuenta.h"
#include "mostrarListaPuntajes.h"

void menuPrincipal();
void menuSwitch();
int opcion;

void menuPrincipal()
{
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t-*- Iniciar Sesion | Registrarse -*-\n");
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t\t1. Iniciar Sesion.\n");
    printf("\t\t\t\t\t2. Registrarse.\n");
    printf("\t\t\t\t\t3. Ver tabla global de jugadores\n");
    printf("\t\t\t\t\t4. Salir.\n");
    printf("\t\t\t\t\t>>> ");
    scanf("%d", &opcion);
    menuSwitch();
}

void menuSwitch()
{
    switch (opcion)
    {
    case 1:
        system("cls");
        printf("\t\t\t\t\tIngrese:\n");
        pedirDatosUsuarioPassword();
        menuPrincipal();
        break;
    case 2:
        system("cls");
        ingresarDatosRegistro();
        menuPrincipal();
        break;
    case 3:
        procesarMostradoPuntaje();
        menuPrincipal();
        break;
    case 4:
        printf("\t\t\t\t\tSaliendo...\n");
        break;
    default:
        system("cls");
        printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        menuPrincipal();
        break;
    }
}