#include <stdio.h>

typedef char string[100];

typedef struct {
    int codCuenta;
    string nombreUsuario;
    string password;
    int saldo, puntos; //? "Puntos" "Saldo" "Score" "Fichas"
    //? Preguntar a Lisandro
}tDatosUsuario;

FILE * archivo;
tDatosUsuario usuario;
int ingreso, cod_anterior=0;
int main () {

    archivo = fopen("cuentasUsuario.dat", "wb");
    ingr();
    while (ingreso!=0){
        usr();
        ingr();
    }
    fclose(archivo);
    return 0;

}

void ingr(){
    printf("Ingresar usuario 1/0: "); scanf("%d", &ingreso);
}

void usr(){
    printf("\nNombre de usuario: "); scanf("%s",&usuario.nombreUsuario); fflush(stdin);
    printf("\nPassword: "); scanf("%s",&usuario.password); fflush(stdin);
    usuario.saldo = 1;
    usuario.puntos = 0;
    cod_anterior+=1;
    usuario.codCuenta = cod_anterior;
    
    fwrite(&usuario, sizeof(tDatosUsuario), 1, archivo);
}