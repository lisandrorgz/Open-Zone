#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

void menublackjack(tDatosUsuario *);


void menublackjack(tDatosUsuario *Userblackjack)
{
home:
	system("cls");
	printf("\n\n\t\t\t\t\t -*- BLACKJACK 31 -*-\n\n");
	sleep(1);
	printf("\n\t\t\t\tBot Administrador: Juguemos al BlackJack 31!");
	sleep(1);
	printf("\n\t\t\t\tBot Administrador: Tu contra mi!");
	sleep(1);
	printf("\n\n\t\t\t\tPresiona 'P' para jugar");
	printf("\n\t\t\t\tPresiona 'Q' para salir ");

Intro:;

	char key = toupper(getch());

	if (key != 'Q' && key != 'P')
		goto Intro;

	if (key == 'Q')
		goto salir;

	// deck array
	int deck[13];
	int c;
	for (c = 0; c < 13; c++)
	{
		deck[c] = c + 1;
	}

	while (key == 'P')
	{
		system("cls");
		printf("\n\n\t\t\t\tBot Administrador: Soy el repartidor! Vayamos a ello.\n");
		sleep(2);

		printf("\t\t\t\tBot Administrador: Repartiendo cartas...");
		sleep(2);

		srand((unsigned)time(NULL));
		int rand1 = rand() % 13 + 1;
		int rand2 = rand() % 13 + 1;

		int dealer_cards[15];
		printf("\n\t\t\t\tBot Administrador: Mi 2nda carta esta escondida.\n");
		sleep(1);
		printf("\t\t\t\tBot Administrador: Mi primera carta:\n");

		// reveal the smallest card although NOT the ace :P
		if ((rand1 > rand2 && rand2 != 1) || (rand1 == 1))
		{
			int temp = rand1;
			rand1 = rand2;
			rand2 = temp;
		}
		dealer_cards[0] = rand1;
		dealer_cards[1] = rand2;

		showCards(dealer_cards, 1);
		sleep(1);

		int dealer_size = 2;
		int sumD = 0;
		sumD = Summ(rand1, sumD);
		sumD = Summ(rand2, sumD);

		int rand3 = rand() % 13 + 1;
		int rand4 = rand() % 13 + 1;

		bool bust = false;
		int noob_cards[15];
		noob_cards[0] = rand3;
		noob_cards[1] = rand4;
		printf("\n\t\t\t\tBot Administrador: Tus cartas:\n");
		sleep(1);
		int noob_size = 2;
		showCards(noob_cards, noob_size);

		int sumN = 0;

		// ACESFUNC1
		int flagAceN = 0; // 0 = ace is still 1 - 1 = ace has changed to 11 --- combined with countAces
		int countAces = 0;
		if (CheckAce(rand3) && CheckAce(rand4))
		{
			sumN = Summ(10, sumN);
			countAces = 2;
			//			flagAceN = 0;  player can change the other - ask later
		}
		else if (CheckAce(rand3) || CheckAce(rand4))
		{
			countAces = 1;
			printf("\t\t\tBot Administrador: Quieres contar las cartas J/Q/K/A como 11/12/13/14? (y/n): ");

		check1:;

			char answerAce = toupper(getche());

			if (answerAce != 'Y' && answerAce != 'N')
				goto check1;

			if (answerAce == 'Y')
			{
				sumN = Summ(10, sumN);
				flagAceN = 1; // ace has changed to 11
			}
		}
		sleep(1);

		// ACESFUNC3-DEALER
		int flagAceDD = 0; // 0 = ace is still 1 - 1 = ace has changed to 11 --- combined with countAces
		int countAcesDD = 0;
		if (CheckAce(rand1) && CheckAce(rand2))
		{
			sumD = Summ(10, sumD);
			countAcesDD = 2;
			//			flagAceDD = 0;  dealer can change the other - check later
		}
		else if (CheckAce(rand1) || CheckAce(rand2))
			countAcesDD = 1; // flagAceDD = 0 and check later

		sumN = Summ(rand3, sumN);
		sumN = Summ(rand4, sumN);

		bool N_14 = Check14(sumN);
		if (rand3 == rand4 && rand3 == 2)
		{
			sumN = 14;
			N_14 = 1;
		}
		if (N_14)
		{
			goto deal;
		}

		// players turn
		char hit;
		// system("cls");
		printf("\n\n\t\t\t\t\tSuma: %d\n", sumN);
		printf("\t\t\t\t\tPedir o quedarse (h/s)?: ");

	check4:

		hit = toupper(getche());
		if (hit != 'H' && hit != 'S')
			goto check4;

		while (hit == 'H')
		{
			int rr = rand() % 13 + 1;
			noob_size++;
			noob_cards[noob_size - 1] = rr;
			printf("\n\t\t\t\t\tTus cartas:\n");
			showCards(noob_cards, noob_size);

			char answerAce;
			int newAce = 0;
			// ACESFUNC2
			if (CheckAce(rr))
			{
				countAces++;
				newAce = 1;
			}
			if (countAces == 1)
			{

				printf("\t\t\t\tBot Administrador: Quieres contar las cartas J/Q/K/A como 11/12/13/14? (y/n):");

			check2:;

				answerAce = toupper(getche());

				if (answerAce != 'Y' && answerAce != 'N')
					goto check2;

				if (answerAce == 'Y' && flagAceN == 0) // ace is 1 wanted 11 add 10
				{
					sumN = Summ(10, sumN);
					flagAceN = 1; // ace has changed to 11
				}
				//				if (answerAce == 'Y' && flagAceN == 1)  ace is 11 no action
				//				if (answerAce == 'N' && flagAceN == 0)  ace is 1 wanted 1 no action
				if (answerAce == 'N' && flagAceN == 1) // ace is 11 wanted 1 sub 10
				{
					sumN = Summ(-10, sumN);
					flagAceN = 0; // ace is 1 again
				}
			}
			if (countAces > 1)
			{
				if (newAce = 1)
				{
					sumN = Summ(10, sumN);
					newAce = 0;
				}
				printf("\t\t\t\tBot Administrador: Bot Administrador: Quieres contar las cartas J/Q/K/A como 11/12/13/14? (y/n):");

			check3:;

				answerAce = toupper(getche());

				if (answerAce != 'Y' && answerAce != 'N')
					goto check3;

				if (answerAce == 'Y' && flagAceN == 0)
				{
					sumN = Summ(10, sumN);
					flagAceN = 1; // ace has changed to 11
				}
				if (answerAce == 'N' && flagAceN == 1) // ace is 11 wanted 1 sub 10
				{
					sumN = Summ(-10, sumN);
					flagAceN = 0; // ace is 1 again
				}
			}
			sleep(1);

			sumN = Summ(rr, sumN);

			if (sumN > 31)
			{
				sleep(1);
				// system("cls");
				printf("\n\n\t\t\t\t\t\tVolaste!\n");
				Userblackjack->saldo -= 1;
				sleep(2);
				bust = true;
				break;
			}
			if (sumN == 31)
			{
				sleep(1);
				printf("\n\n\t\t\t\t\t>>>>>>>> 31 <<<<<<<\n");
				sleep(2);
				printf("\n\t\t\t\t\t\t...\n");
				sleep(1);
				break;
			}
			N_14 = Check14(sumN);
			if (N_14)
			{
				printf("\n\n\t\t\t\t\t\tBot Admiistrador: Tienes 14! Tendria que ir al 31....\n\n");
				sleep(2);
				goto deal;
			}
			printf("\n\t\t\t\tLas cartas suman %d\n", sumN);
			printf("\n\t\t\t\tPedir o quedarse (h/s)?: ");

		check5:

			hit = toupper(getche());
			if (hit != 'H' && hit != 'S')
				goto check5;
		}

	deal:;

		// dealers turn
		printf("\n\t\t\t\t\tBot Administrador: Mis cartas:\n");
		showCards(dealer_cards, dealer_size);
		sleep(1);

		bool D_14 = Check14(sumD);
		if ((rand1 == rand2 && rand1 == 2) || (rand1 == 3 && rand2 == 1) || (rand1 == 1 && rand2 == 3))
		{
			sumD = 14;
			D_14 = 1;
		}
		if (D_14)
		{

			if (saldoen0(Userblackjack->saldo) && bust) {
				printf("\n\t\t\t\t\tNo te quedan mas fichas\n");
				goto salir; }
			else
			{
				if (N_14) {
					printf("\n\n\t\t\t\tBot Administrador: Soy el ganador!!.\n\n");
					printf("\n\n\t\t\t\t\t\t  \033[1;31m-1 Ficha\n\033[0m");
					Userblackjack->saldo-=1; 
					goto end; }
				else if (sumN < 31)
					printf("\n\n\t\t\t\tBot Administrador: Tienes la suma de (%d).. Ganaste!!.\n\n", sumN);
				else if (sumN == 31)
				{
					printf("\n\t\t\t\tBot Administrador: Enserio? 31? ... Okay, ganaste\n\n");
					sleep(1);
					printf("\n\n\t\t\t\t\t\t  \033[1;32m+4 Puntos\n\033[0m");
					sleep(1);
					Userblackjack->puntos += 4;
					goto end;
				}

				if (bust)
				{
					printf("\n\t\t\t\t\tBot Administrador: Yo gane!\n");
					printf("\n\n\t\t\t\t\t\t  \033[1;31m-1 Ficha\n\033[0m");
					Userblackjack->saldo -= 1;
					goto end;
				}
				if (sumN > sumD) {
					printf("\t\t\t\tBot Administrador: Bien jugado!\n\n");
					sleep(1);
					printf("\t\t\t\t\t\t+4 Puntos\n");
					sleep(1);
					Userblackjack->puntos += 4;
					goto end;

				}
			}
		}

		printf("\n\n\t\t\t\tBot Administrador: Mis cartas suman %d\n", sumD);
		sleep(2);

		if (N_14)
			goto loopa;

		while (sumD < sumN && !bust)
		{
		loopa:;

			int rr = rand() % 13 + 1;

			dealer_size++;
			dealer_cards[dealer_size - 1] = rr;
			printf("\n\t\t\t\t\tBot Administrador: Mis cartas: ");
			showCards(dealer_cards, dealer_size);
			sleep(1);

			int newAceDD = 0;
			// ACESFUNC4-DEALER
			if (CheckAce(rr))
			{
				countAcesDD++;
				newAceDD = 1;
			}
			if (countAcesDD == 1)
			{
				if (flagAceDD == 0 && (Summ(rr, sumD) + 10 <= 31) && (Summ(rr, sumD) != 14))
				{
					sumD = Summ(10, sumD);
					flagAceDD = 1;
				}
				else if ((flagAceDD == 1 && (Summ(rr, sumD) > 31)) || (flagAceDD == 1 && (Summ(rr, sumD) - 10 == 14)))
				{
					sumD = Summ(-10, sumD);
					flagAceDD = 0;
				}
			}
			if (countAcesDD > 1)
			{
				if (newAceDD = 1)
				{
					sumD = Summ(10, sumD);
					newAceDD = 0;
				}

				if (flagAceDD == 0 && (Summ(rr, sumD) + 10 <= 31) && (Summ(rr, sumD) != 14))
				{
					sumD = Summ(10, sumD);
					flagAceDD = 1;
				}
				else if ((flagAceDD == 1 && (Summ(rr, sumD) > 31)) || (flagAceDD == 1 && (Summ(rr, sumD) - 10 == 14)))
				{
					sumD = Summ(-10, sumD);
					flagAceDD = 0;
				}
			}

			sumD = Summ(rr, sumD);
			printf("\n\n\t\t\t\tBot Administrador: Mis cartas suman %d\n", sumD);
			sleep(2);

			D_14 = Check14(sumD);
			if (saldoen0(Userblackjack->saldo) && bust) {
				printf("\n\t\t\t\t\tNo te quedan mas fichas\n");
				goto salir; }
			else
			{
				if (D_14)
				{

					if (N_14) {
						printf("\n\n\t\t\t\t\tBot Administrador: Soy el ganador!!.\n\n");
						Userblackjack->saldo -= 1; 
						goto end; }
						

					else if (sumN < 31) {
						printf("\n\n\t\t\t\t\tBot Administrador: Soy el ganador!!.\n\n");
						Userblackjack->saldo -= 1; 
						goto end; }
						

					else if (sumN == 31)
					{
						printf("\n\t\t\t\t\tBot Administrador: Enserio? 31? ... Okay, ganaste\n\n");
						sleep(1);
						printf("\n\n\t\t\t\t\t\t  \033[1;32m+4 Puntos\n\033[0m");
						sleep(1);
						Userblackjack->puntos += 4;
						goto end;
						
					}

					else if (bust) {
						printf("\n\t\t\t\t\tBot Administrador: Volaste! Yo gane!\n");
						printf("\n\n\t\t\t\t\t\t  \033[1;31m-1 Ficha\n\033[0m");
						goto end; }
						
				}

				
			}

			if (N_14 && sumD < 31)
				goto loopa;
		}

		// we have a winner
		printf("\n\t\t\t\tBot Administrador: Suma de mis cartas: %d\n\t\t\t\tBot Administrador: Suma de tus cartas: %d", sumD, sumN);
		sleep(1);
		if (saldoen0(Userblackjack->saldo) && bust) {
			printf("\n\t\t\t\t\tNo te quedan mas fichas\n");
			goto salir; }

		if ((sumD >= sumN && sumD <= 31) || bust)
		{
			printf("\n\t\t\t\tBot Administrador: Yo gane!\n");
			printf("\n\n\t\t\t\t\t\t  \033[1;31m-1 Ficha\n\033[0m");
			
			Userblackjack->saldo -= 1; 
		}
		else {
			printf("\n\t\t\t\tBot Administrador: Vole!, ganaste... es una lastima.\n");
			sleep(1);
			printf("\n\n\t\t\t\t\t\t  \033[1;32m+4 Puntos\n\033[0m");
			sleep(1);
			Userblackjack->puntos += 4;
		}

	end:
		fflush(stdin);
		printf("\n\t\t\t\t  Jugar de nuevo?(P/Q): ");
		key = toupper(getch());

		if (key != 'Q' && key != 'P')
			goto end;

		if (key == 'Q')
		{
			system("cls");
			goto salir;
		}
	}
	salir: ;
	system("cls");
	printf("\n\t\t\t\t\t\tSaliendo del juego...\n");
	sleep(2);
}


// eimon96 11/2020 <<3
int Summ(int draw, int sum)
{
	if (draw == 11 || draw == 12 || draw == 13) sum += 10;
	else sum += draw;
	
	return (sum);
}


int Check14(int s)
{	
	if (s == 14) 	return (1);
	else 			return (0);
}


int CheckAce(int draw)
{
	if (draw == 1) 	return (1);
	else			return (0);
}


void showCards(int *array_cards, int siz)
{

	// card 'visuals' - no suits => infinite decks
	const char ace[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* A         *\
		    	\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         A *\
				\n\t\t\t\t\t\t*************\n\n";

	const char two[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 2         *\
		    	\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         2 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char three[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 3         *\
		    	\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         3 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char four[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 4         *\
		   		\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         4 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char five[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 5         *\
			    \n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         5 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char six[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 6         *\
			    \n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         6 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char seven[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 7         *\
			    \n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         7 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char eight[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 8         *\
			    \n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         8 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char nine[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 9         *\
			    \n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*         9 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char ten[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* 10        *\
	   			\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*     *     *\
				\n\t\t\t\t\t\t*  *     *  *\
				\n\t\t\t\t\t\t*        10 *\
				\n\t\t\t\t\t\t*************\n\n";

	const char jack[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* J         *\
	   			\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  J A C K  *\
				\n\t\t\t\t\t\t*    | |    *\
				\n\t\t\t\t\t\t*    | |    *\
				\n\t\t\t\t\t\t*    | |    *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         J *\
				\n\t\t\t\t\t\t*************\n\n";

	const char queen[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* Q         *\
	   			\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  Q U EE N *\
				\n\t\t\t\t\t\t*    / \\    *\
				\n\t\t\t\t\t\t*    / \\    *\
				\n\t\t\t\t\t\t*    / \\    *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*         Q *\
				\n\t\t\t\t\t\t*************\n\n";

	const char king[] = "\n\t\t\t\t\t\t*************\
				\n\t\t\t\t\t\t* K         *\
	   			\n\t\t\t\t\t\t*           *\
				\n\t\t\t\t\t\t*  K I N G  *\
				\n\t\t\t\t\t\t*   / /\\ \\  *\
				\n\t\t\t\t\t\t*  /\\/\\/\\/\\ *\
				\n\t\t\t\t\t\t*  \\      / *\
				\n\t\t\t\t\t\t*   \\    /  *\
				\n\t\t\t\t\t\t*    \\  /   *\
				\n\t\t\t\t\t\t*         K *\
				\n\t\t\t\t\t\t*************\n\n";

	int c;
	for (c = 0; c < siz; c++)
	{
		switch (array_cards[c])
		{
		case (1):
			printf("%s", ace);
			break;
		case (2):
			printf("%s", two);
			break;
		case (3):
			printf("%s", three);
			break;
		case (4):
			printf("%s", four);
			break;
		case (5):
			printf("%s", five);
			break;
		case (6):
			printf("%s", six);
			break;
		case (7):
			printf("%s", seven);
			break;
		case (8):
			printf("%s", eight);
			break;
		case (9):
			printf("%s", nine);
			break;
		case (10):
			printf("%s", ten);
			break;
		case (11):
			printf("%s", jack);
			break;
		case (12):
			printf("%s", queen);
			break;
		case (13):
			printf("%s", king);
			break;
		}
	}
}