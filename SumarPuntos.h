#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; 
}zDatosUsuario;

void abrirArchivoPuntos();
void incrementarFichas(int, string, string, int, int);
void decrementarFichas(int, string, string, int, int);
void incrementarPuntos(int, string, string, int, int);
void cerrarArchivoPuntos();

FILE *modificarPuntos;

void abrirArchivoPuntos() {
    modificarPuntos = fopen("cuentasUsuario.dat","r+b");
}

/* void incrementarFichas(int codCuenta, string nombreUsuario, string password, int saldo, int puntos) {
    zDatosUsuario pDatosUsuario;
    zDatosUsuario usuarioLogeado;
    pDatosUsuario.codCuenta = codCuenta;
    strcpy(pDatosUsuario.nombreUsuario, nombreUsuario);
    strcpy(pDatosUsuario.password, password);
    pDatosUsuario.saldo = saldo;
    pDatosUsuario.puntos = puntos;
    abrirArchivoPuntos();
    fread(&usuarioLogeado, sizeof(zDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            int pos = ftell(modificarPuntos)-sizeof(zDatosUsuario);
            fseek(modificarPuntos, pos, SEEK_SET);
            fwrite(&pDatosUsuario, sizeof(zDatosUsuario), 1, modificarPuntos);
            break;
        }
        fread(&usuarioLogeado, sizeof(zDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
}

void decrementarFichas(int codCuenta, string nombreUsuario, string password, int saldo, int puntos) {
    zDatosUsuario pDatosUsuario;
    zDatosUsuario usuarioLogeado;
    pDatosUsuario.codCuenta = codCuenta;
    strcpy(pDatosUsuario.nombreUsuario, nombreUsuario);
    strcpy(pDatosUsuario.password, password);
    pDatosUsuario.saldo = saldo;
    pDatosUsuario.puntos = puntos;
    abrirArchivoPuntos();
    fread(&usuarioLogeado, sizeof(gDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.saldo < 0) {
                pDatosUsuario.saldo -= 1;
                int pos = ftell(modificarPuntos)-sizeof(zDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pDatosUsuario, sizeof(zDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(zDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
} */

void incrementarPuntos(int codCuenta, string nombreUsuario, string password, int puntos, int puntosDelJuego) {
    abrirArchivoPuntos();
    zDatosUsuario pUsuario;
    zDatosUsuario usuarioLogeado;
    pUsuario.codCuenta = codCuenta;
    strcpy(pUsuario.nombreUsuario, nombreUsuario);
    strcpy(pUsuario.password, password);
    pUsuario.puntos = puntos;
    fread(&usuarioLogeado, sizeof(zDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pUsuario.nombreUsuario)) {
            if (pUsuario.puntos>= 0) {
                pUsuario.puntos += puntosDelJuego;
                int pos = ftell(modificarPuntos)-sizeof(zDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pUsuario, sizeof(zDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(zDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
}

void cerrarArchivoPuntos() {
    fclose(modificarPuntos);
}

