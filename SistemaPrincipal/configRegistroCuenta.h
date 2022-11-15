#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; //? "Puntos" "Saldo" "Score" "Fichas"
    //? Preguntar a Lisandro
}tDatosRegistro;

tDatosRegistro rDatosRegistro;
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
    rDatosRegistro.puntos = 5; //* Aca van cuantos puntos va a tener despues de registrarse cambiar *//
    verCuentaSiNoEstaRegistrada();
    grabarRegistroAlumno();
    cerrarArchivoRegistro();
}

void grabarRegistroAlumno() {
    int respuesta;
    printf("\t\t\t\tDesea registrarse? 1-Si 2-No: ");
    scanf("%d", &respuesta);
    if (respuesta == 1) {
        fwrite(&rDatosRegistro, sizeof(tDatosRegistro), 1, registro);
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
    tDatosRegistro prueba;
    int respuesta;
    fread(&prueba, sizeof(tDatosRegistro), 1, registro);
    while (!feof(registro)) {
        rDatosRegistro.codCuenta = prueba.codCuenta+1;
        if (!strcmp(prueba.nombreUsuario, rDatosRegistro.nombreUsuario)) {
            printf("Usuario ya registrado...\n");
            printf("Nombre de usuario ya existe. Elija otro por favor:\n");
            scanf("%s", &rDatosRegistro.nombreUsuario);
            printf("Desea cambiar la contrase%ca? -> %s (1-Si) - (0-No):", 164, rDatosRegistro.password);
            scanf("%d", &respuesta);
            if (respuesta == 1) {
                printf("Ingrese la nueva contrase%ca:\n", 164);
                scanf("%s", &rDatosRegistro.password);
            }
        }
        fread(&prueba, sizeof(tDatosRegistro), 1, registro);
    }
}