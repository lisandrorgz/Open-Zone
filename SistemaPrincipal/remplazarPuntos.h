#include <stdio.h>
#include <string.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos;
}regDatosUsuario;

void abrirArchivo();
void incrementarPuntos(regDatosUsuario);
void decrementarPuntos(regDatosUsuario);
void cerrarArchivo();

FILE *modificarPuntos;

void abrirArchivo() {
    modificarPuntos = fopen("cuentasUsuario.dat","r+b");
}

void incrementarPuntos(regDatosUsuario pDatosUsuario) {
    abrirArchivo();
    regDatosUsuario usuarioLogeado;
    fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.puntos >= 0) {
                pDatosUsuario.puntos += 1;
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

