#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void abrirArchivoPuntos();
void actualizarFichas(tDatosUsuario*);
void actualizarPuntos(tDatosUsuario*);
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
}*/

void actualizarFichas(tDatosUsuario*ActualizarSaldo) {
    tDatosUsuario pDatosUsuario;
    tDatosUsuario usuarioLogeado;
    pDatosUsuario.codCuenta = ActualizarSaldo->codCuenta;
    strcpy(pDatosUsuario.nombreUsuario, ActualizarSaldo->nombreUsuario);
    strcpy(pDatosUsuario.password, ActualizarSaldo->password);
    pDatosUsuario.saldo = ActualizarSaldo->saldo;
    pDatosUsuario.puntos = ActualizarSaldo->puntos;
    abrirArchivoPuntos();
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.saldo > 0) {
                printf("Nuevo valor de SALDO antes de impactar en el archivo: %d\n", pDatosUsuario.saldo);
                int pos = ftell(modificarPuntos)-sizeof(tDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pDatosUsuario, sizeof(tDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
} 

void actualizarPuntos(tDatosUsuario*ActualizarPuntos) {
    abrirArchivoPuntos();
    tDatosUsuario pUsuario;
    tDatosUsuario usuarioLogeado;
    pUsuario.codCuenta = ActualizarPuntos->codCuenta;
    strcpy(pUsuario.nombreUsuario, ActualizarPuntos->nombreUsuario);
    strcpy(pUsuario.password, ActualizarPuntos->password);
    pUsuario.puntos = ActualizarPuntos->puntos;
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pUsuario.nombreUsuario)) {
            if (pUsuario.puntos>= 0) {
                pUsuario.puntos+=usuarioLogeado.puntos;
                printf("Nuevo valor de puntos antes de impactar en el archivo: %d\n", pUsuario.puntos);
                int pos = ftell(modificarPuntos)-sizeof(tDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pUsuario, sizeof(tDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
}

void cerrarArchivoPuntos() {
    fclose(modificarPuntos);
}

