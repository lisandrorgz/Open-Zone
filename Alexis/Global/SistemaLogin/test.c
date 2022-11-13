#include "Config/configLoginCuenta.h"
#include "Config/configMostrarCuenta.h"

void menu();

int main() {
    menu();
}

void menu() {
    int respuesta;
    while(respuesta != 0) {
        printf("1) Registrar Usuario\n");
        printf("2) Mostrar Cuentas de usuarios\n");
        scanf("%d", &respuesta);
        switch (respuesta) {
        case 1:
        //* funciones para registrar una cuenta...
            abrirArchivoParaRegistar();
	        ingresarDatos();
	        cerrarArchivoRegistro();
            break;
        case 2:
        //* funciones para mostrar cuentas registradas...
            abrirArchivoParaMostrar();
	        procesarCuentasUsuarios();
	        cerrarArchivoMostrar();
            break;
        default:
            break;
        }
    }
}