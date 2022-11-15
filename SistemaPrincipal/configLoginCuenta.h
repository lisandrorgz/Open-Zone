#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuJuegos.h" //* Configuracion del Menu Juegos...

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; //? "Puntos" "Saldo" "Score" "Fichas"
    //? Preguntar a Lisandro
}sDatosUsuarios;

sDatosUsuarios pDatosUsuario;
sDatosUsuarios usuario;
FILE *login;

void abrirArchivoParaLogearse();
void pedirDatosUsuarioPassword();
void leerDatoUsuario();
void escanearArchivoParaLogearse();
void buscarUsuarioYPassword();
void cerrarArchivoParaLogearse();
void menu();

void abrirArchivoParaLogearse() {
	login = fopen("cuentasUsuario.dat", "rb");
}

void pedirDatosUsuarioPassword() {
    abrirArchivoParaLogearse();
    printf("\t\t\t\tUsuario: ");
    scanf("%s", &usuario.nombreUsuario);
    printf("\t\t\t\tContrase%ca: ", 164);
    scanf("%s", &usuario.password);
    escanearArchivoParaLogearse(usuario);
    cerrarArchivoParaLogearse();
}

void escanearArchivoParaLogearse() {
    fread(&pDatosUsuario, sizeof(sDatosUsuarios), 1, login);
    while (!feof(login)) {
        if (!strcmp(pDatosUsuario.nombreUsuario, usuario.nombreUsuario) && !strcmp(pDatosUsuario.password, usuario.password)) {
            printf("\t\t\t\tLogeado Correctamente!\n");
            system("pause");
            system("cls");
            menuJuegos(pDatosUsuario.codCuenta, pDatosUsuario.nombreUsuario, pDatosUsuario.password, pDatosUsuario.puntos);
            break;
        }
        else fread(&pDatosUsuario, sizeof(sDatosUsuarios), 1, login);
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
