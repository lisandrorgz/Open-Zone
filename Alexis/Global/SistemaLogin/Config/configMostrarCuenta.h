#include <stdio.h>
#include <stdlib.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int puntos; //? "Puntos" "Saldo" "Score" "Fichas"
    //? Preguntar a Lisandro
}tDatosUsuarios;

tDatosUsuarios mDatosUsuario;
FILE *mostrarLogin;

void abrirArchivoParaMostrar();
void procesarCuentasUsuarios();
void leerDatosUsuario();
void mostrarCuentaUsuario();
void cerrarArchivoMostrar();

void abrirArchivoParaMostrar(){
	system("cls");
<<<<<<<< HEAD:Alexis/Global/SistemaLogin/Config/configMostrarCuenta.h
	mostrarLogin = fopen("Config/cuentaUsuario.dat", "rb");
========
	mostrarLogin = fopen("cuentaUsuario.dat", "rb");
>>>>>>>> 46b62373da49d8e065ecb194c65410f317e96e0c:SistemaPrincipal/configMostrarCuenta.h
	printf("\t*** REGISTRO DE USUARIOS ***\n" ); 
	printf("Cuenta | Usuario\t| Password\n"); 
}

void procesarCuentasUsuarios() {
	leerDatosUsuario();
	while(!feof( mostrarLogin)) {
		mostrarCuentaUsuario();
		leerDatosUsuario();
	}
}
	
void leerDatosUsuario() {
	fread(&mDatosUsuario, sizeof(tDatosUsuarios), 1, mostrarLogin);
}
	
void mostrarCuentaUsuario() {
	printf("%d\t %s\t%s\n", mDatosUsuario.codCuenta, mDatosUsuario.nombreUsuario, mDatosUsuario.password);
}

	
void cerrarArchivoMostrar(){
	fclose(mostrarLogin);
}