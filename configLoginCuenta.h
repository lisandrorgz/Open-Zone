#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuJuegos.h"

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; 
}bDatosUsuario;

bDatosUsuario user;
FILE *login;

void abrirArchivoParaLogearse();
void pedirDatosUsuarioPassword();
void escanearArchivoParaLogearse();
void cerrarArchivoParaLogearse();

void abrirArchivoParaLogearse() {
	login = fopen("cuentasUsuario.dat", "rb");
}

void pedirDatosUsuarioPassword() {
    abrirArchivoParaLogearse();
    printf("\t\t\t\tUsuario: ");
    scanf("%s", &user.nombreUsuario);
    printf("\t\t\t\tContrase%ca: ", 164);
    scanf("%s", &user.password);
    escanearArchivoParaLogearse();
    cerrarArchivoParaLogearse();
}

void escanearArchivoParaLogearse() {
    bDatosUsuario pDatosUsuario;
    fread(&pDatosUsuario, sizeof(bDatosUsuario), 1, login);
    while (!feof(login)) {
        if (!strcmp(pDatosUsuario.nombreUsuario, user.nombreUsuario) && !strcmp(pDatosUsuario.password, user.password)) {
            printf("\t\t\t\tLogeado Correctamente!\n");
            system("pause");
            system("cls");
            menuJuegos(pDatosUsuario.codCuenta, pDatosUsuario.nombreUsuario, pDatosUsuario.password, pDatosUsuario.puntos);
            break;
        }
        else fread(&pDatosUsuario, sizeof(bDatosUsuario), 1, login);
    }
    if (feof(login)) {
        cerrarArchivoParaLogearse();
        system("cls");
        printf("\t\t\t\tUsuario o contrase%ca incorrecto\n", 164);
        printf("\t\t\t\tIntentelo de nuevo:\n");
        pedirDatosUsuarioPassword();
    }
}

void cerrarArchivoParaLogearse() {
	fclose(login);

}
