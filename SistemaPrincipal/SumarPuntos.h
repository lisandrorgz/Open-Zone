#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void abrirArchivoPuntos();
void actualizarFichas(tDatosUsuario *);
void actualizarPuntos(tDatosUsuario *);
void cerrarArchivoPuntos();

FILE *modificarPuntos;

void abrirArchivoPuntos()
{
    modificarPuntos = fopen("cuentasUsuario.dat", "r+b");
}

void actualizarFichas(tDatosUsuario *ActualizarSaldo)
{
    tDatosUsuario pDatosUsuario;
    tDatosUsuario usuarioLogeado;
    pDatosUsuario.codCuenta = ActualizarSaldo->codCuenta;
    strcpy(pDatosUsuario.nombreUsuario, ActualizarSaldo->nombreUsuario);
    strcpy(pDatosUsuario.password, ActualizarSaldo->password);
    pDatosUsuario.saldo = ActualizarSaldo->saldo;
    pDatosUsuario.puntos = ActualizarSaldo->puntos;
    abrirArchivoPuntos();
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos))
    {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario))
        {
            if (pDatosUsuario.saldo > 0)
            {
                int pos = ftell(modificarPuntos) - sizeof(tDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pDatosUsuario, sizeof(tDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
}

void actualizarPuntos(tDatosUsuario *ActualizarPuntos)
{
    abrirArchivoPuntos();
    tDatosUsuario pUsuario;
    tDatosUsuario usuarioLogeado;
    pUsuario.codCuenta = ActualizarPuntos->codCuenta;
    strcpy(pUsuario.nombreUsuario, ActualizarPuntos->nombreUsuario);
    strcpy(pUsuario.password, ActualizarPuntos->password);
    pUsuario.puntos = ActualizarPuntos->puntos;
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos))
    {
        if (!strcmp(usuarioLogeado.nombreUsuario, pUsuario.nombreUsuario))
        {
            if (pUsuario.puntos >= 0)
            {
                pUsuario.puntos += usuarioLogeado.puntos;
                int pos = ftell(modificarPuntos) - sizeof(tDatosUsuario);
                fseek(modificarPuntos, pos, SEEK_SET);
                fwrite(&pUsuario, sizeof(tDatosUsuario), 1, modificarPuntos);
                break;
            }
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
}

void actualizarConexion(tDatosUsuario *ActualizarSaldo)
{
    tDatosUsuario pDatosUsuario;
    tDatosUsuario usuarioLogeado;
    pDatosUsuario = *ActualizarSaldo;
    abrirArchivoPuntos();
    fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    while (!feof(modificarPuntos))
    {
        if (!strcmp(usuarioLogeado.nombreUsuario, pDatosUsuario.nombreUsuario))
        {
            time_t t = time(NULL);
            struct tm tiempoLocal = *localtime(&t);
            char fechaActual[100];
            char *formato = "%d - %m - %Y %H:%M:%S";
            int bytesEscritos = strftime(fechaActual, sizeof fechaActual, formato, &tiempoLocal);
            strcpy(pDatosUsuario.conexion, fechaActual);
            int pos = ftell(modificarPuntos) - sizeof(tDatosUsuario);
            fseek(modificarPuntos, pos, SEEK_SET);
            fwrite(&pDatosUsuario, sizeof(tDatosUsuario), 1, modificarPuntos);
            break;
        }
        fread(&usuarioLogeado, sizeof(tDatosUsuario), 1, modificarPuntos);
    }
    cerrarArchivoPuntos();
}

void cerrarArchivoPuntos()
{
    fclose(modificarPuntos);
}
