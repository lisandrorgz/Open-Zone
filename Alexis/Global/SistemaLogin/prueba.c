#include "configLoginCuenta.h"
#include "configMostrarCuenta.h"

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
            abrirArchivoParaRegistar();
	        ingresarDatos();
	        cerrarArchivoRegistro();
            break;
        case 2:
            abrirArchivoParaMostrar();
	        procesarCuentasUsuarios();
	        cerrarArchivoMostrar();
            break;
        default:
            break;
        }
    }
}