#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; //? "Puntos" "Saldo" "Score" "Fichas"
    //? Preguntar a Lisandro
}tDatosLogin;

tDatosLogin rDatosLogin;
FILE *login;

void abrirArchivoParaRegistar();
void registraUsuario();
void cerrarArchivoRegistro();
void ingresarDatos();
void grabarRegistroAlumno();
void verCuentaSiNoEstaRegistrada();

void abrirArchivoParaRegistar() {
	login = fopen("Config/cuentaUsuario.dat", "a+b");
}

void ingresarDatos() {
    rDatosLogin.codCuenta = 1;
    printf("Elija un Nombre de Usuario(Sin Espacios):");
    scanf("%s", &rDatosLogin.nombreUsuario);
    printf("Elija una contrasenia para la cuenta:");
    scanf("%s", &rDatosLogin.password);
    verCuentaSiNoEstaRegistrada();
    grabarRegistroAlumno();
}

void grabarRegistroAlumno() {
	fwrite(&rDatosLogin, sizeof(tDatosLogin), 1, login);
    //printf("Datos de la cuenta:\nNumero de Cuenta: %d.\nNombre de Usuario: %s\nPassword: %s\n\n", rDatosLogin.codCuenta, rDatosLogin.nombreUsuario, rDatosLogin.password);
    printf("Registrado Correctamente\n");
    system("pause");
    system("cls");
}

void cerrarArchivoRegistro() {
	fclose(login);
}

void verCuentaSiNoEstaRegistrada() {
    tDatosLogin prueba;
    int respuesta;
    fread(&prueba, sizeof(tDatosLogin), 1, login);
    while (!feof(login)) {
        rDatosLogin.codCuenta = prueba.codCuenta+1;
        if (!strcmp(prueba.nombreUsuario, rDatosLogin.nombreUsuario)) {
            printf("Usuario ya registrado...\n");
            printf("Nombre de usuario ya existe. Elija otro por favor:\n");
            scanf("%s", &rDatosLogin.nombreUsuario);
            printf("Desea cambiar la contrase%ca? -> %s (1-Si) - (0-No):", 164, rDatosLogin.password);
            scanf("%d", &respuesta);
            if (respuesta == 1) {
                printf("Ingrese la nueva contrase%ca:\n", 164);
                scanf("%s", &rDatosLogin.password);
            }
        }
        fread(&prueba, sizeof(tDatosLogin), 1, login);
    }
}