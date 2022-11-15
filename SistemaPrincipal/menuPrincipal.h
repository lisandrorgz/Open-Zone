#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "configLoginCuenta.h" //* Configuracion de Login...
#include "configRegistroCuenta.h" //* Configuracion de Registro...

void menuPrincipal();
void menuSwitch();
int opcion;

void menuPrincipal() {
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t-*- Iniciar Sesion | Registrarse -*-\n");
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t\t1. Iniciar Sesion.\n");
    printf("\t\t\t\t\t2. Registrarse.\n");
    printf("\t\t\t\t\t3. Salir.\n");
    printf("\t\t\t\t\t>>> ");
    scanf("%d", &opcion);
    menuSwitch();
}

void menuSwitch() {
    switch (opcion) {
    case 1:
        system("cls");
        printf("\t\t\t\t\tIngrese:\n");
        abrirArchivoParaLogearse();
        pedirDatosUsuarioPassword();
        cerrarArchivoParaLogearse();
        menuPrincipal();
        break;
    case 2:
        system("cls");
        abrirArchivoParaRegistar();
	    ingresarDatos();
	    cerrarArchivoRegistro();
        menuPrincipal();
        break;
    case 3:
        printf("Saliendo...");
        break; 
    default:
        system("cls");
        printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        menuPrincipal();
        break;
    }
}