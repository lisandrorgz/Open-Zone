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
}tDatosUsuarios;

tDatosUsuarios pDatosUsuario;
tDatosUsuarios usuario;
FILE *login;

void abrirArchivoParaLogearse();
void pedirDatosUsuarioPassword();
void leerDatoUsuario();
void escanearArchivoParaLogearse();
void buscarUsuarioYPassword();
void cerrarArchivoParaLogearse();
void menu();

void abrirArchivoParaLogearse() {
	login = fopen("cuentasUsuario.dat", "rb");
}

void pedirDatosUsuarioPassword() {
    printf("\t\t\t\tUsuario: ");
    scanf("%s", &usuario.nombreUsuario);
    printf("\t\t\t\tContrase%ca:", 164);
    scanf("%s", &usuario.password);
    escanearArchivoParaLogearse(usuario);
}

void escanearArchivoParaLogearse() {
    fread(&pDatosUsuario, sizeof(tDatosUsuarios), 1, login);
    while (!feof(login)) {
        if (!strcmp(pDatosUsuario.nombreUsuario, usuario.nombreUsuario) && !strcmp(pDatosUsuario.password, usuario.password)) {
            printf("\t\t\t\tLogeado Correctamente!\n");
            break;
        }
        else fread(&pDatosUsuario, sizeof(tDatosUsuarios), 1, login);
    }
    if (!strcmp(pDatosUsuario.nombreUsuario, usuario.nombreUsuario) && !strcmp(pDatosUsuario.password, usuario.password)){
        //* Menu de juegos...
        
    }
    else {
        cerrarArchivoParaLogearse();
        abrirArchivoParaLogearse();
        system("cls");
        printf("\t\t\t\tUsuario o contrase%ca incorrecto\n", 164);
        printf("\t\t\t\tIntentelo de nuevo:\n");
        pedirDatosUsuarioPassword();
    }
}

void cerrarArchivoParaLogearse() {
	fclose(login);
}
