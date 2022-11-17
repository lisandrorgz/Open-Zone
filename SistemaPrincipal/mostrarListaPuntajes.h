#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    tDatosUsuario datos;
    struct nodo *izquierdo;
    struct nodo *derecho;
}tArbolPuntaje;

tArbolPuntaje *datosArbol;
tDatosUsuario datosPuntaje;
FILE *listaPuntaje;

void abrirArchivoPuntaje();
void procesarMostradoPuntaje();
void cerrarArchivoPuntaje();
void insertarPuntaje(tArbolPuntaje **, tDatosUsuario);
void ordenInverso(tArbolPuntaje *, int, int);

void abrirArchivoPuntaje() {
    listaPuntaje = fopen("cuentasUsuario.dat", "rb");
}

void procesarMostradoPuntaje() {
    system("cls");
    datosArbol = NULL;
    abrirArchivoPuntaje();
    fread(&datosPuntaje, sizeof(tDatosUsuario), 1, listaPuntaje);
    while (!feof(listaPuntaje)) {
        insertarPuntaje(&datosArbol, datosPuntaje);
        fread(&datosPuntaje, sizeof(tDatosUsuario), 1, listaPuntaje);
    }
    cerrarArchivoPuntaje();
    ordenInverso(datosArbol, 1, 1);
    system("pause");
    system("cls");
}

void cerrarArchivoPuntaje() {
    fclose(listaPuntaje);
}

void insertarPuntaje(tArbolPuntaje** pArbolPuntaje, tDatosUsuario pDatosUsuario) {
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

void ordenInverso(tArbolPuntaje *pArbolPuntaje, int titulo, int i) {
    if (titulo == 1) {
        printf("\t\t\t\t\t -*- Top global puntajes -*- \n");
        printf("\t\t\t\t\tPosicion - Usuario - Puntaje\n");
    }
    if (pArbolPuntaje != NULL) {
        ordenInverso(pArbolPuntaje->derecho, 2, i+1);
        printf("\t\t\t\t\t%d\t - %s -\t%d.\n", i, pArbolPuntaje->datos.nombreUsuario, pArbolPuntaje->datos.puntos);
        ordenInverso(pArbolPuntaje->izquierdo, 2, i+1);
    }
}