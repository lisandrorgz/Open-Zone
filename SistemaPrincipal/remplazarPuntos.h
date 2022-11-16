#include <stdio.h>
#include <string.h>

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
void cerrarArchivo();

FILE *modificarPuntos;

void abrirArchivo() {
    modificarPuntos = fopen("cuentasUsuario.dat","r+b");
}

void incrementarFichas(regDatosUsuario pDatosUsuario) {
    abrirArchivo();
    regDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.fichas >= 0) {
                pDatosUsuario.fichas += 1;
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

