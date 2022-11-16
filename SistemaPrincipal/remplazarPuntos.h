#include <stdio.h>
#include <string.h>
#include "menuJuegos.h" 

<<<<<<< HEAD

void abrirArchivo();
void incrementarPuntos(tDatosUsuario*);
void decrementarPuntos(tDatosUsuario*);
=======
typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int fichas;
    int puntos;
}regDatosUsuario;

void abrirArchivo();
void incrementarFichas(regDatosUsuario);
void decrementarFichas(regDatosUsuario);
>>>>>>> 2424475a317a8e324688e0fec22bac1bc6190bc1
void cerrarArchivo();

FILE *modificarPuntos;

void abrirArchivo() {
    modificarPuntos = fopen("cuentasUsuario.dat","r+b");
}

<<<<<<< HEAD
void incrementarPuntos(tDatosUsuario*User) {
=======
void incrementarFichas(regDatosUsuario pDatosUsuario) {
>>>>>>> 2424475a317a8e324688e0fec22bac1bc6190bc1
    abrirArchivo();
    tDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
<<<<<<< HEAD
        if (!strcmp(usuarioLogeado.nombreUsuario, User->nombreUsuario)) {
                int pos = ftell(modificarPuntos)-sizeof(tDatosUsuario);
=======
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.fichas >= 0) {
                pDatosUsuario.fichas += 1;
                int pos = ftell(modificarPuntos)-sizeof(regDatosUsuario);
>>>>>>> 2424475a317a8e324688e0fec22bac1bc6190bc1
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(User, sizeof(tDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivo();
}

void decrementarFichas(regDatosUsuario pDatosUsuario) {
    abrirArchivo();
    regDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.fichas < 0) {
                pDatosUsuario.fichas -= 1;
                int pos = ftell(modificarPuntos)-sizeof(regDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pDatosUsuario, sizeof(regDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivo();
}

void incrementarPuntos(regDatosUsuario pDatosUsuario, int puntosAcumulado) {
    abrirArchivo();
    regDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.fichas >= 0) {
                pDatosUsuario.puntos += puntosAcumulado;
                int pos = ftell(modificarPuntos)-sizeof(regDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pDatosUsuario, sizeof(regDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivo();
}

void cerrarArchivo() {
    fclose(modificarPuntos);
}

