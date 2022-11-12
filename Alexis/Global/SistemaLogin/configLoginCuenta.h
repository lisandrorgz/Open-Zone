#include <stdio.h>
#include <stdlib.h>

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
	login = fopen("cuentaUsuario.dat", "a+b");
}

void ingresarDatos() {
	printf("Elija un Numero de Cuenta:");
    scanf("%d", &rDatosLogin.codCuenta);
    printf("Elija un Nombre de Usuario(Sin Espacios):");
    scanf("%s", &rDatosLogin.nombreUsuario);
    printf("Elija una contrasenia para la cuenta:");
    scanf("%s", &rDatosLogin.password);
    //! verCuentaSiNoEstaRegistrada(rDatosLogin);
    grabarRegistroAlumno();
}

void grabarRegistroAlumno() {
	fwrite(&rDatosLogin, sizeof(tDatosLogin), 1, login);
    printf("Registrado Correctamente\n");
}

void cerrarArchivoRegistro() {
	fclose(login);
}

void verCuentaSiNoEstaRegistrada(tDatosLogin pDatosLogin) {
    tDatosLogin prueba;
    while (!feof(login)) {
        //fscanf(login, "%d%s%s", &prueba.codCuenta, prueba.nombreUsuario, prueba.password);
        //fread(&rDatosLogin, sizeof(tDatosLogin), 1, login);
        if (prueba.codCuenta == rDatosLogin.codCuenta) {
            printf("Numero de cuenta ya existe. Elija otro por favor:\n");
            scanf("%d", &rDatosLogin.codCuenta);
        }
        if (prueba.nombreUsuario == rDatosLogin.nombreUsuario) {
            printf("Nombre de usuario ya existe. Elija otro por favor:\n");
            scanf("%s", &rDatosLogin.nombreUsuario);
        }
        if (prueba.codCuenta == rDatosLogin.codCuenta && prueba.nombreUsuario == rDatosLogin.nombreUsuario && prueba.password == rDatosLogin.password) {
            printf("Usuario ya registrado...\n");
        }
    }
}