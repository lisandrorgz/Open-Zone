#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>



#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//declaracion de variables
int tamanho, curvan, tam, vida;
char tecla;
//decalaração métodos
void cobrinha(), erro(), intervalo(long double), mover(int*), comer(), xyz(int x, int y), curvar(), borda(), descer(), esquerda(), subir(), direita(), sair(int*), menusnake(int*), jogar(int*), pontuacao(), descricao(), desenvolvedor();
int placar(), placarx();

struct coordenada
{
  int x, y, direcao;
};

typedef struct coordenada coordenada;

coordenada cabeca, curva[500], comida, corpo[30];

//método principal


//método que imprime e valida as opções do menu
void menusnake(int * contador)
{ 
  
  
  int opc = 0;
  do
  {
    cobrinha();
    printf("\n1. Jugar \n2. Ver puntuacion \n3. Salir\n****************************\n");
    scanf("%d", &opc);

    switch (opc)
    {
    //opcao 1
    case 1:
      system("cls");
      jogar(contador);
      break;
    //opcao 2
    case 2:
      system("cls");
      pontuacao();
      break;
    //opcao 3
    case 3:
      break;
  
    default:
      erro();
      printf("\nXXXXXXXXXXXXXXXXXXXXXXX Seleccione del 1 a 5 XXXXXXXXXXXXXXXXXXXXXXX\n");
      break;
     
    }

  } while (opc != 5 && *contador != 0);
 }



//método que inicia o jogo
void jogar(int * contador)
{
  char tecla;

  system("cls");
  tamanho = 5;
  cabeca.x = 25;
  cabeca.y = 20;
  cabeca.direcao = RIGHT;
  borda();
  comer();  //cria a primeira comida
  vida = 3; //numero de vidas
  curva[0] = cabeca;
  mover(contador); //inicia o jogo
}

//método que imprime a cobrinha em ASCII art do ficheiro de texto
void cobrinha()
{
  FILE *info = fopen("cobrinha.txt", "r");
  char c;

  do
  {
    putchar(c = getc(info));
  } while (c != EOF);

  fclose(info);
}

//método que imprime mensagem de erro em ASCII art do ficheiro de texto
void erro()
{
  FILE *info = fopen("erro.txt", "r");
  char c;

  do
  {
    putchar(c = getc(info));
  } while (c != EOF);

  fclose(info);
}

//método que imprime pontuação salva no ficheiro de texto
void pontuacao()
{
  printf("_______  Puntuacion _______\n");
  FILE *info = fopen("pontuacao.txt", "r");
  char c;

  do
  {
    putchar(c = getc(info));
  } while (c != EOF);

  fclose(info);
}



//método que movimenta a cobrinha em função de coordenadas
void mover(int *contador)
{
  int a, i;

  do
  {
    comer();
    fflush(stdin);
    tam = 0;

    for (i = 0; i < 30; i++)
    {
      corpo[i].x = 0;
      corpo[i].y = 0;

      if (i == tamanho)
      {
        break;
      }
    }

    intervalo(tamanho);
    borda();

    if (cabeca.direcao == RIGHT)
    {
      direita();
    }
    else if (cabeca.direcao == LEFT)
    {
      esquerda();
    }
    else if (cabeca.direcao == DOWN)
    {
      descer();
    }
    else if (cabeca.direcao == UP)
    {
      subir();
    }

    sair(contador);
  } while (!kbhit());

  a = getch();

  if (a == 27)
  {
    system("cls");
    exit(0);
  }

  tecla = getch();

  if ((tecla == RIGHT && cabeca.direcao != LEFT && cabeca.direcao != RIGHT) || (tecla == LEFT && cabeca.direcao != RIGHT && cabeca.direcao != LEFT) || (tecla == UP && cabeca.direcao != DOWN && cabeca.direcao != UP) || (tecla == DOWN && cabeca.direcao != UP && cabeca.direcao != DOWN))
  {
    curvan++;
    curva[curvan] = cabeca;
    cabeca.direcao = tecla;

    if (tecla == UP)
    {
      cabeca.y--;
    }

    if (tecla == DOWN)
    {
      cabeca.y++;
    }

    if (tecla == RIGHT)
    {
      cabeca.x++;
    }

    if (tecla == LEFT)
    {
      cabeca.x--;
    }

    mover(contador);
  }
  else if (tecla == 27)
  {
    system("cls");
    exit(0);
  }
  else
  {
    printf("\a");
    mover(contador);
  }
}

//método responsável por imprimir a parte gráfica do jogo
void xyz(int x, int y)
{
  HANDLE a;
  COORD b;
  fflush(stdout);
  b.X = x;
  b.Y = y;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(a, b);
}

//método para descer a direção da cobrinha
void descer()
{
  int i;

  for (i = 0; i <= (cabeca.y - curva[curvan].y) && tam < tamanho; i++)
  {
    xyz(cabeca.x, cabeca.y - i);
    {
      if (tam == 0)
      {
        printf("v");
      }
      else
      {
        printf("*");
      }
    }

    corpo[tam].x = cabeca.x;
    corpo[tam].y = cabeca.y - i;
    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.y++;
  }
}

//método que define a taxa de atualização (movimento da cobrinha)
void intervalo(long double k)
{
  placar();
  long double i;

  for (i = 0; i <= (10000000); i++)
    ;
}

//método que verifica as vidas
void sair(int * contador)
{
  int i, verificar = 0;
  

  for (i = 4; i < tamanho; i++) //inicia com 4, pois só assim é que a cobrinha poderá enrolar-se
  {
    if (corpo[0].x == corpo[i].x && corpo[0].y == corpo[i].y)
    {
      verificar++; //verifica se a coordenada da cabeça é a mesma que do corpo
    }

    if (i == tamanho || verificar != 0)
    {
      break;
    }
  }

  if (cabeca.x <= 10 || cabeca.x >= 70 || cabeca.y <= 10 || cabeca.y >= 30 || verificar != 0)
  {
    
    vida--;
    

    if ( vida > 0)
    {
      cabeca.x = 25;
      cabeca.y = 20;
      curvan = 0;
      cabeca.direcao = RIGHT;
      mover(contador);
    }
    else
    {
      system("cls");
      *contador-=1;
      if(saldoen0(*contador)) {
        printf("Perdiste y no tienes mas fichas!!!\n");
        exit(0);}
      system("cls");
      printf("Perdiste!!!\n---\tVolviendo al Menu\t---\n");
      
      menusnake(contador);
      
    }
      
    }
  }


//método que cria a comida
void comer()
{
  if (cabeca.x == comida.x && cabeca.y == comida.y)
  {
    tamanho++;
    time_t a;
    a = time(0);
    srand(a);
    comida.x = rand() % 70;

    if (comida.x <= 10)
    {
      comida.x += 11;
    }

    comida.y = rand() % 30;

    if (comida.y <= 10)
    {
      comida.y += 11;
    }
  }
  else if (comida.x == 0) /*cria a primeira comida do jogo*/
  {
    comida.x = rand() % 70;

    if (comida.x <= 10)
    {
      comida.x += 11;
    }

    comida.y = rand() % 30;

    if (comida.y <= 10)
    {
      comida.y += 11;
    }
  }
}

//método para mudar a direção da cobrinha a esquerda
void esquerda()
{
  int i;

  for (i = 0; i <= (curva[curvan].x - cabeca.x) && tam < tamanho; i++)
  {
    xyz((cabeca.x + i), cabeca.y);
    {
      if (tam == 0)
      {
        printf("<");
      }
      else
      {
        printf("*");
      }
    }

    corpo[tam].x = cabeca.x + i;
    corpo[tam].y = cabeca.y;
    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.x--;
  }
}

//método para mudar a direção da cobrinha a direita
void direita()
{
  int i;

  for (i = 0; i <= (cabeca.x - curva[curvan].x) && tam < tamanho; i++)
  {
    corpo[tam].x = cabeca.x - i;
    corpo[tam].y = cabeca.y;
    xyz(corpo[tam].x, corpo[tam].y);
    {
      if (tam == 0)
      {
        printf(">");
      }
      else
      {
        printf("*");
      }
    }

    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.x++;
  }
}

//método para curvar a direção da cobrinha
void curvar()
{
  int i, j, diff;

  for (i = curvan; i >= 0 && tam < tamanho; i--)
  {
    if (curva[i].x == curva[i - 1].x)
    {
      diff = curva[i].y - curva[i - 1].y;

      if (diff < 0)
      {
        for (j = 1; j <= (-diff); j++)
        {
          corpo[tam].x = curva[i].x;
          corpo[tam].y = curva[i].y + j;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
      else if (diff > 0)
      {
        for (j = 1; j <= diff; j++)
        {
          corpo[tam].x = curva[i].x;
          corpo[tam].y = curva[i].y - j;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
    }
    else if (curva[i].y == curva[i - 1].y)
    {
      diff = curva[i].x - curva[i - 1].x;

      if (diff < 0)
      {
        for (j = 1; j <= (-diff) && tam < tamanho; j++)
        {
          corpo[tam].x = curva[i].x + j;
          corpo[tam].y = curva[i].y;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
      else if (diff > 0)
      {
        for (j = 1; j <= diff && tam < tamanho; j++)
        {
          corpo[tam].x = curva[i].x - j;
          corpo[tam].y = curva[i].y;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
    }
  }
}

//método que imprime o retângulo
void borda()
{
  system("cls");
  int i;
  xyz(comida.x, comida.y); /*imprime a comida*/
  printf("C");

  for (i = 10; i < 71; i++)
  {
    xyz(i, 10);
    printf("-");
    xyz(i, 30);
    printf("_");
  }

  for (i = 10; i < 31; i++)
  {
    xyz(10, i);
    printf("|");
    xyz(70, i);
    printf("|");
  }
}



//método que imprime o placar do jogo
int placar()
{
  int placa;

  xyz(20, 8);
  placa = tamanho - 5;
  printf("Pontos : %d", (tamanho - 5));
  placa = tamanho - 5;
  xyz(50, 8);
  printf("Vidas : %d", vida);

  return placa;
}

//método que atualiza o placar do jogo
int placarx()
{
  int placax = placar();

  system("cls");

  return placax;
}

//método para subir a direção da cobrinha
void subir()
{
  int i;

  for (i = 0; i <= (curva[curvan].y - cabeca.y) && tam < tamanho; i++)
  {
    xyz(cabeca.x, cabeca.y + i);
    {
      if (tam == 0)
      {
        printf("^");
      }
      else
      {
        printf("*");
      }
    }

    corpo[tam].x = cabeca.x;
    corpo[tam].y = cabeca.y + i;
    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.y--;
  }
}