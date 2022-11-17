#include <stdio.h>
#include <stdlib.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; 
}cDatosUsuario;

cDatosUsuario mDatosUsuario;
FILE *mostrarLogin;

void abrirArchivoParaMostrar();
void procesarCuentasUsuarios();
void leerDatosUsuario();
void mostrarCuentaUsuario();
void cerrarArchivoMostrar();

void abrirArchivoParaMostrar(){
	system("cls");
	mostrarLogin = fopen("cuentasUsuario.dat", "rb");
	printf("\t*** REGISTRO DE USUARIOS ***\n" ); 
	printf("Cuenta | Usuario\t| Password | Puntaje\n"); 
}

void procesarCuentasUsuarios() {
	abrirArchivoParaMostrar();
	leerDatosUsuario();
	while(!feof(mostrarLogin)) {
		mostrarCuentaUsuario();
		leerDatosUsuario();
	}
	cerrarArchivoMostrar();
}
	
void leerDatosUsuario() {
	fread(&mDatosUsuario, sizeof(cDatosUsuario), 1, mostrarLogin);
}
	
void mostrarCuentaUsuario() {
	printf("%d\t %s\t%s\t%d\n", mDatosUsuario.codCuenta, mDatosUsuario.nombreUsuario, mDatosUsuario.password, mDatosUsuario.puntos);
}

void cerrarArchivoMostrar(){
	fclose(mostrarLogin);
}