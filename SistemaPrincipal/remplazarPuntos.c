#include <stdio.h>
#include <string.h>
#include "configMostrarCuenta.h"

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos;
}regDatosUsuario;

regDatosUsuario usuarioLogeado;
FILE *modificarPuntos;

void abrirArchivo() {
    modificarPuntos = fopen("cuentasUsuario.dat","r+b");
}

void incrementarPuntos(regDatosUsuario pDatosUsuario) {
    abrirArchivo();
    fread(&usuarioLogeado, sizeof(regDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos)) {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario)) {
            if (pDatosUsuario.puntos >= 0) {
                pDatosUsuario.puntos += 1;
                //! Error no me quiere incrementar el punto y guardarlo...
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

int main() {
    regDatosUsuario prueba;
    prueba.codCuenta = 111;
    strcpy(prueba.nombreUsuario, "Alexis");
    strcpy(prueba.password, "alexis");
    prueba.puntos = 5;
    incrementarPuntos(prueba);
    abrirArchivoParaMostrar();
    procesarCuentasUsuarios();
    cerrarArchivoMostrar();
}

