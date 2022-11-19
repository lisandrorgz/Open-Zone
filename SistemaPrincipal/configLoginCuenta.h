#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuJuegos.h"

tDatosUsuario *DatosRef;
tDatosUsuario pDatosUsuario;
tDatosUsuario user;
FILE *login;

void abrirArchivoParaLogearse();
void pedirDatosUsuarioPassword();
void leerDatoUsuario();
void escanearArchivoParaLogearse();
void buscarUsuarioYPassword();
void cerrarArchivoParaLogearse();
void menu();

void abrirArchivoParaLogearse()
{
    login = fopen("cuentasUsuario.dat", "rb");
}

void pedirDatosUsuarioPassword()
{
    abrirArchivoParaLogearse();
    printf("\t\t\t\tUsuario: ");
    scanf("%s", &user.nombreUsuario);
    printf("\t\t\t\tContrase%ca: ", 164);
    scanf("%s", &user.password);
    escanearArchivoParaLogearse();
    cerrarArchivoParaLogearse();
}

void escanearArchivoParaLogearse()
{
    fread(&pDatosUsuario, sizeof(tDatosUsuario), 1, login);
    while (!feof(login))
    {
        if (!strcmp(pDatosUsuario.nombreUsuario, user.nombreUsuario) && !strcmp(pDatosUsuario.password, user.password))
        {
            cerrarArchivoParaLogearse();
            DatosRef = &pDatosUsuario;
            actualizarConexion(DatosRef);
            printf("\t\t\t\tLogeado Correctamente!\n");
            system("pause");
            system("cls");
            menuJuegos(DatosRef);
            break;
        }
        fread(&pDatosUsuario, sizeof(tDatosUsuario), 1, login);
    }
    if (feof(login))
    {
        cerrarArchivoParaLogearse();
        system("cls");
        printf("\t\t\t\tUsuario o contrase%ca incorrecto\n", 164);
        printf("\t\t\t\tIntentelo de nuevo:\n");
        pedirDatosUsuarioPassword();
    }
}

void cerrarArchivoParaLogearse()
{
    fclose(login);
}
