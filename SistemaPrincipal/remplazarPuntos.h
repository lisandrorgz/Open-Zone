#include <stdio.h>
#include <string.h>
#include "menuJuegos.h" 


void abrirArchivo();
void incrementarPuntos(tDatosUsuario*);
void decrementarPuntos(tDatosUsuario*);
void cerrarArchivo();

FILE *modificarPuntos;

void abrirArchivo() {
    modificarPuntos = fopen("cuentasUsuario.dat","r+b");
}

void incrementarPuntos(tDatosUsuario*User) {
    abrirArchivo();
    tDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, User->nombreUsuario)) {
                int pos = ftell(modificarPuntos)-sizeof(tDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(User, sizeof(tDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivo();
}

void decrementarPuntos(regDatosUsuario pDatosUsuario) {
    abrirArchivo();
    regDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.puntos >= 0) {
                pDatosUsuario.puntos -= 1;
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

