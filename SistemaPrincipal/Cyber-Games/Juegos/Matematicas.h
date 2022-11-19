#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ingreso = 1;

void volverAlMenu();

void volverAlMenu()
{
    printf("Seguir jugando? 1/0: ");
    scanf("%d", &ingreso);
}
void menumath()
{

    system("cls");
    printf("1. Nivel 1 (Rangos entre: 1~10)\n");
    printf("2. Nivel 2 (Rangos entre: 1~20)\n");
    printf("3. Nivel 3 (Rangos entre: 1~50)\n");
    printf("4. Nivel 4 (Rangos entre: 1~100)\n");
    printf("5. Nivel 5 (Rangos entre: 1~200)\n");
}

void l1(tDatosUsuario *Usermath)
{
    int a, b, c, d, z, m, temp;
    time_t t;
    srand((unsigned)time(&t));
    printf("Nivel 1 seleccionado\n(Para seleccionar otro nivel, reinicie el programa)\n");
    while (ingreso == 1)
    {
        z = rand() % 5 + 1;
        a = rand() % 9 + 1;
        b = rand() % 9 + 1;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (z == 1)
        {
            c = a + b;
            printf("%d + %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 1;
                printf("Respuesta correcta\n");
                printf("+1 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);

                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
            system("pause");
            system("cls");
        }

        else if (z == 2)
        {
            c = a - b;
            printf("%d - %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 1;
                printf("Respuesta correcta\n");
                printf("+1 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
            system("pause");
            system("cls");
        }
        else if (z == 3)
        {
            c = a * b;
            printf("%d * %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 1;
                printf("Respuesta correcta\n");
                printf("+1 Puntos\n");
            }
            else
            {
                Usermath->puntos += 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
            system("pause");
            system("cls");
        }
        else if (z == 4)
        {
            if (a % b != 0)
            {
                m = a % b;
                a -= m;
            }
            c = a / b;
            printf("%d / %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 1;
                printf("Respuesta correcta\n");
                printf("+1 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
            system("pause");
            system("cls");
        }
    }
}

void l2(tDatosUsuario *Usermath)
{
    int a, b, c, d, z, m, temp;
    time_t t;
    srand((unsigned)time(&t));
    printf("Nivel 2 seleccionado\n(Para seleccionar otro nivel, reinicie el programa)\n");
    while (ingreso == 1)
    {
        z = rand() % 5 + 1;
        a = rand() % 19 + 1;
        b = rand() % 19 + 1;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (z == 1)
        {
            c = a + b;
            printf("%d + %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 2;
                printf("Respuesta correcta\n");
                printf("+2 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 2)
        {
            c = a - b;
            printf("%d - %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 2;
                printf("Respuesta correcta\n");
                printf("+2 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 3)
        {
            c = a * b;
            printf("%d * %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 2;
                printf("Respuesta correcta\n");
                printf("+2 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 4)
        {
            if (a % b != 0)
            {
                m = a % b;
                a -= m;
            }
            c = a / b;
            printf("%d / %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 2;
                printf("Respuesta correcta\n");
                printf("+2 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
    }
}

void l3(tDatosUsuario *Usermath)
{
    int a, b, c, d, z, m, temp;
    time_t t;
    srand((unsigned)time(&t));
    printf("Nivel 3 seleccionado\n(Para seleccionar otro nivel, reinicie el programa\n");
    while (ingreso == 1)
    {
        z = rand() % 5 + 1;
        a = rand() % 49 + 1;
        b = rand() % 49 + 1;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (z == 1)
        {
            c = a + b;
            printf("%d + %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 3;
                printf("Respuesta correcta\n");
                printf("+3 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 2)
        {
            c = a - b;
            printf("%d - %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 3;
                printf("Respuesta correcta\n");
                printf("+3 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 3)
        {
            c = a * b;
            printf("%d * %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 3;
                printf("Respuesta correcta\n");
                printf("+3 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 4)
        {
            if (a % b != 0)
            {
                m = a % b;
                a -= m;
            }
            c = a / b;
            printf("%d / %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 3;
                printf("Respuesta correcta\n");
                printf("+3 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
    }
}

void l4(tDatosUsuario *Usermath)
{
    int a, b, c, d, z, m, temp;
    time_t t;
    srand((unsigned)time(&t));
    printf("Nivel 4 seleccionado\n(Para seleccionar otro nivel, reinicie el programa)\n");
    while (ingreso == 1)
    {
        z = rand() % 5 + 1;
        a = rand() % 99 + 1;
        b = rand() % 99 + 1;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (z == 1)
        {
            c = a + b;
            printf("%d + %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 4;
                printf("Respuesta correcta\n");
                printf("+4 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 2)
        {
            c = a - b;
            printf("%d - %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 4;
                printf("Respuesta correcta\n");
                printf("+4 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 3)
        {
            c = a * b;
            printf("%d * %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 4;
                printf("Respuesta correcta\n");
                printf("+4 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 4)
        {
            if (a % b != 0)
            {
                m = a % b;
                a -= m;
            }
            c = a / b;
            printf("%d / %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 4;
                printf("Respuesta correcta\n");
                printf("+4 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
    }
}

void l5(tDatosUsuario *Usermath)
{
    int a, b, c, d, z, m, temp;
    time_t t;
    srand((unsigned)time(&t));
    printf("Nivel 5 seleccionado\n(Para seleccionar otro nivel, reinicie el programa)\n");
    while (ingreso == 1)
    {
        z = rand() % 5 + 1;
        a = rand() % 199 + 1;
        b = rand() % 199 + 1;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (z == 1)
        {
            c = a + b;
            printf("%d + %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 5;
                printf("Respuesta correcta\n");
                printf("+5 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 2)
        {
            c = a - b;
            printf("%d - %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 5;
                printf("Respuesta correcta\n");
                printf("+5 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 3)
        {
            c = a * b;
            printf("%d * %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 5;
                printf("Respuesta correcta\n");
                printf("+5 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
        else if (z == 4)
        {
            if (a % b != 0)
            {
                m = a % b;
                a -= m;
            }
            c = a / b;
            printf("%d / %d = ", a, b);
            scanf("%d", &d);
            if (c == d)
            {
                Usermath->puntos += 5;
                printf("Respuesta correcta\n");
                printf("+5 Puntos\n");
            }
            else
            {
                Usermath->saldo -= 1;
                printf("Respuesta incorrecta\nLa respuesta correcta es %d\n", c);
                if (saldoen0(Usermath->saldo))
                    break;
                else
                    volverAlMenu();
            }
            printf("Te quedan %d fichas!!\n", Usermath->saldo);
        }
    }
}

void mainmath(tDatosUsuario *Usuariomath)
{
    int n;
    printf("Selecciona un nivel:\n");
    menumath();
    fflush(stdin);
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        l1(Usuariomath);
        break;
    case 2:
        l2(Usuariomath);
        break;
    case 3:
        l3(Usuariomath);
        break;
    case 4:
        l4(Usuariomath);
        break;
    case 5:
        l5(Usuariomath);
        break;
    default:
        printf("Eleccion incorrecta!\n");
        break;
    }
}
