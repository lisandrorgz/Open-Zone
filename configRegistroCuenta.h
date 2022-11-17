#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; 
}aDatosUsuario;

aDatosUsuario rDatosRegistro;
FILE *registro;

void abrirArchivoParaRegistar();
void registraUsuario();
void cerrarArchivoRegistro();
void ingresarDatosRegistro();
void grabarRegistroAlumno();
void verCuentaSiNoEstaRegistrada();

void abrirArchivoParaRegistar() {
	registro = fopen("cuentasUsuario.dat", "a+b");
}

void ingresarDatosRegistro() {
    abrirArchivoParaRegistar();
    rDatosRegistro.codCuenta = 0;
    printf("\t\t\t\t\t-*- Formulario para registrarse -*-\n");
    printf("\t\t\t\tElija un Nombre de Usuario(Sin Espacios): ");
    scanf("%s", &rDatosRegistro.nombreUsuario);
    printf("\t\t\t\tElija una contrase%ca para la cuenta: ", 164);
    scanf("%s", &rDatosRegistro.password);
    rDatosRegistro.puntos = 0;
    verCuentaSiNoEstaRegistrada();
    grabarRegistroAlumno();
    cerrarArchivoRegistro();
}

void grabarRegistroAlumno() {
    int respuesta;
    printf("\t\t\t\tDesea registrarse? 1-Si 2-No: ");
    scanf("%d", &respuesta);
    if (respuesta == 1) {
        fwrite(&rDatosRegistro, sizeof(aDatosUsuario), 1, registro);
        printf("\t\t\t\tRegistrado Correctamente...\n");
        system("pause");
        system("cls");
    }
    else if (respuesta == 2) {
        //* tiene que ir al menu principal pero nose como ir...
    }
    else {
        printf("\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        grabarRegistroAlumno();
    }
}

void cerrarArchivoRegistro() {
	fclose(registro);
}

void verCuentaSiNoEstaRegistrada() {
    aDatosUsuario aux;
    int respuesta;
    fread(&aux, sizeof(aDatosUsuario), 1, registro);
    while (!feof(registro)) {
        rDatosRegistro.codCuenta = aux.codCuenta+1;
        if (!strcmp(aux.nombreUsuario, rDatosRegistro.nombreUsuario)) {
            printf("\t\t\t\tUsuario ya registrado...\n");
            printf("\t\t\t\tVuelva a intentarlo...\n");
            cerrarArchivoRegistro();
            ingresarDatosRegistro();
        }
        fread(&aux, sizeof(aDatosUsuario), 1, registro);
    }
}