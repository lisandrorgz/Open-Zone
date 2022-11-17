#include <stdio.h>
#include <stdlib.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos;
}lDatosUsuario;

typedef struct nodo {
    lDatosUsuario datos;
    struct nodo *izquierdo;
    struct nodo *derecho;
}tArbolPuntaje;

tArbolPuntaje *datosArbol;
lDatosUsuario datosPuntaje;
FILE *listaPuntaje;

void abrirArchivoPuntaje();
void procesarMostradoPuntaje();
void cerrarArchivoPuntaje();
void insertarPuntaje(tArbolPuntaje **, lDatosUsuario);
void ordenInverso(tArbolPuntaje *, int);

void abrirArchivoPuntaje() {
    listaPuntaje = fopen("cuentasUsuario.dat", "rb");
}

void procesarMostradoPuntaje() {
    system("cls");
    datosArbol = NULL;
    abrirArchivoPuntaje();
    fread(&datosPuntaje, sizeof(lDatosUsuario), 1, listaPuntaje);
    while (!feof(listaPuntaje)) {
        insertarPuntaje(&datosArbol, datosPuntaje);
        fread(&datosPuntaje, sizeof(lDatosUsuario), 1, listaPuntaje);
    }
    cerrarArchivoPuntaje();
    ordenInverso(datosArbol, 1);
    system("pause");
    system("cls");
}

void cerrarArchivoPuntaje() {
    fclose(listaPuntaje);
}

void insertarPuntaje(tArbolPuntaje** pArbolPuntaje, lDatosUsuario pDatosUsuario) {
    if (pDatosUsuario.codCuenta > 0) {
        if (*pArbolPuntaje == NULL) {
            (*pArbolPuntaje) = (tArbolPuntaje*) malloc(sizeof(tArbolPuntaje));
            if (*pArbolPuntaje != NULL) {
                (*pArbolPuntaje)->datos = pDatosUsuario;
                (*pArbolPuntaje)->izquierdo = NULL;
                (*pArbolPuntaje)->derecho = NULL;
            }
            else printf("No hay Memoria!\n");
        }
        else {
            if (pDatosUsuario.puntos < (*pArbolPuntaje)->datos.puntos) insertarPuntaje(&((*pArbolPuntaje)->izquierdo), pDatosUsuario);
            else if (pDatosUsuario.puntos >= (*pArbolPuntaje)->datos.puntos) insertarPuntaje(&((*pArbolPuntaje)->derecho), pDatosUsuario);
        }
    }
}

void ordenInverso(tArbolPuntaje *pArbolPuntaje, int titulo) {
    if (titulo == 1) {
        printf("\t\t\t\t\t -*- Tabla de puntajes globales -*- \n");
        printf("\t\t\t\t\tCodCuenta - Usuario - Puntaje\n");
    }
    if (pArbolPuntaje != NULL) {
        ordenInverso(pArbolPuntaje->derecho, 2);
        printf("\t\t\t\t\t%d\t - %s -\t%d.\n", pArbolPuntaje->datos.codCuenta, pArbolPuntaje->datos.nombreUsuario, pArbolPuntaje->datos.puntos);
        ordenInverso(pArbolPuntaje->izquierdo, 2);
    }
}