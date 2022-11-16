#include <stdio.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int saldo, puntos; 

}tDatosUsuario;

FILE * archivo;
tDatosUsuario usuario;
int ingreso, cod_anterior=0;
int main () {

    archivo = fopen("cuentasUsuario.dat", "rb");
    fread(&usuario, sizeof(tDatosUsuario), 1, archivo);
    while (!feof(archivo)){
        usr();
    }
    fclose(archivo);
    return 0;

}


void usr(){
    printf("\nNombre de usuario: %s ", usuario.nombreUsuario);
    printf("\nPassword: %s", usuario.password);
    printf("\nSaldo: %d", usuario.saldo);
    printf("\nPuntos: %d", usuario.puntos);
    printf("\nCod cuenta: %d", usuario.codCuenta);
    fread(&usuario, sizeof(tDatosUsuario), 1, archivo);
}