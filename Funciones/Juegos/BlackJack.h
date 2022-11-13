#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

void menublackjack(int*);


void showCards(int *array_cards, int siz)
{
	
	// card 'visuals' - no suits => infinite decks
	const char ace[]="\n*************\
				\n* A         *\
		    	\n*           *\
				\n*           *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*           *\
				\n*           *\
				\n*         A *\
				\n*************\n\n";
				
	const char two[]="\n*************\
				\n* 2         *\
		    	\n*           *\
				\n*     *     *\
				\n*           *\
				\n*           *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*         2 *\
				\n*************\n\n";
	
	const char three[]="\n*************\
				\n* 3         *\
		    	\n*           *\
				\n*     *     *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*         3 *\
				\n*************\n\n";
				
	const char four[]="\n*************\
				\n* 4         *\
		   		\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*           *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         4 *\
				\n*************\n\n";	
	
	const char five[]="\n*************\
				\n* 5         *\
			    \n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         5 *\
				\n*************\n\n";
				
	const char six[]="\n*************\
				\n* 6         *\
			    \n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         6 *\
				\n*************\n\n";
				
	const char seven[]="\n*************\
				\n* 7         *\
			    \n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         7 *\
				\n*************\n\n";
				
	const char eight[]="\n*************\
				\n* 8         *\
			    \n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*         8 *\
				\n*************\n\n";
				
	const char nine[]="\n*************\
				\n* 9         *\
			    \n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*         9 *\
				\n*************\n\n";
				
	const char ten[]="\n*************\
				\n* 10        *\
	   			\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*        10 *\
				\n*************\n\n";
				
	const char jack[]="\n*************\
				\n* J         *\
	   			\n*           *\
				\n*  J A C K  *\
				\n*    | |    *\
				\n*    | |    *\
				\n*    | |    *\
				\n*           *\
				\n*           *\
				\n*         J *\
				\n*************\n\n";
				
	const char queen[]="\n*************\
				\n* Q         *\
	   			\n*           *\
				\n*  Q U EE N *\
				\n*    / \\    *\
				\n*    / \\    *\
				\n*    / \\    *\
				\n*           *\
				\n*           *\
				\n*         Q *\
				\n*************\n\n";
								
	const char king[]="\n*************\
				\n* K         *\
	   			\n*           *\
				\n*  K I N G  *\
				\n*   / /\\ \\  *\
				\n*  /\\/\\/\\/\\ *\
				\n*  \\      / *\
				\n*   \\    /  *\
				\n*    \\  /   *\
				\n*         K *\
				\n*************\n\n";
				
				
				
	int c;
	for (c = 0; c < siz; c++)
	{
		switch(array_cards[c])
		{
			case(1):
				printf("%s", ace);
				break;
			case(2):
				printf("%s", two);
				break;
			case(3):
				printf("%s", three);
				break;
			case(4):
				printf("%s", four);
				break;
			case(5):
				printf("%s", five);
				break;
			case(6):
				printf("%s", six);
				break;
			case(7):
				printf("%s", seven);
				break;
			case(8):
				printf("%s", eight);
				break;
			case(9):
				printf("%s", nine);
				break;
			case(10):
				printf("%s", ten);
				break;
			case(11):
				printf("%s", jack);
				break;
			case(12):
				printf("%s", queen);
				break;
			case(13):
				printf("%s", king);
				break;
		}
	}
}


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

void menublackjack(int*contador) {
	home:
	
	printf("\
			//////////////////////////////////////////\n\
			////            WELCOME!              ////\n\
			//////////////////////////////////////////\n\n");
			
	printf("\t\t\t\t  .--,-``-.    \t           \n\
			\t /   /     '.  \t     ,---, \n\
			\t/ ../        ; \t  ,`--.' | \n\
			\t\\ ``\\  .`-    '\t /    /  : \n\
			\t \\___\\/   \\   :\t:    |.' ' \n\
			\t      \\   :   |\t`----':  | \n\
			\t      /  /   / \t   '   ' ; \n\
			\t      \\  \\   \\ \t   |   | | \n\
			\t  ___ /   :   |\t   '   : ; \n\
			\t /   /\\   /   :\t   |   | ' \n\
			\t/ ,,/  ',-    .\t   '   : | \n\
			\t\\ ''\\        ; \t   ;   |.' \n\
			\t \\   \\     .'  \t   '---'   \n\
			\t  `--`-,,-'    \t           \n\
			\t               \t           \n\
			\t			   \t		  \n\
	");
	
	
	sleep(1);
	printf("\nBot Administrador: Juguemos al BlackJack 31!!!");
	sleep(1);
	printf("\nBot Administrador: Tu contra mi!");
	sleep(1);
	printf("\n\nPresiona 'P' para jugar");
	printf("\nPresiona 'Q' para salir");
	
	
	Intro: ;
		
	char key = toupper(getch());
	
	if (key != 'Q' && key != 'P') goto Intro;
	
	if (!(key == 'Q')){
		
		
		//deck array
		int deck[13];
		int c;
		for (c = 0; c < 13; c++ ) {
		deck[c] =  c + 1;
		}
		
		
		
		while (key == 'P'){
			system("cls");
			printf("\nBot Administrador: Soy el repartidor! Vayamos a ello.\n\n");
			sleep(1);
			
			printf("\nBot Administrador: Repartiendo cartas...");
			sleep(2);
				
			srand((unsigned)time(NULL));
			int rand1 = rand() % 13 + 1;
			int rand2 = rand() % 13 + 1;

			
			int dealer_cards[15];
			printf("\nBot Administrador: Mi 2nda carta esta escondida.\n");
			sleep(1);
			printf("\nBot Administrador: Mi primera carta:\n");
			
			// reveal the smallest card although NOT the ace :P
			if ((rand1 > rand2 && rand2 != 1 ) || (rand1 == 1))
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
			printf("\nBot Administrador: Tus cartas:\n");
			sleep(1);
			int noob_size = 2;
			showCards(noob_cards, noob_size);
			
			int sumN = 0;
			
			
			
			
			// ACESFUNC1
			int flagAceN = 0;	// 0 = ace is still 1 - 1 = ace has changed to 11 --- combined with countAces
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
				printf("Bot Administrador: Quieres contar la A como 11?(y/n): ");
				
				check1: ;
				
					char answerAce = toupper(getche());
				
					if (answerAce != 'Y' && answerAce != 'N') goto check1;
				
				
				if (answerAce == 'Y') 
				{
					sumN = Summ(10, sumN);
					flagAceN = 1; // ace has changed to 11
				}
					
			}
			sleep(1);
			
			
			
			
			
			
			// ACESFUNC3-DEALER
			int flagAceDD = 0;	// 0 = ace is still 1 - 1 = ace has changed to 11 --- combined with countAces
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
				printf("\n\nBot Administrador: Tienes 14! Tengo que ir al 31.\n\n");
				sleep(2);
				goto deal;
			}
			
			
			
			//players turn
			char hit;
			system("cls");
			printf("\nSuma: %d\n",sumN);
			printf("\nPedir o quedarse (h/s)?: ");
			
			check4: 
			
				hit = toupper(getche());
				if (hit != 'H' && hit != 'S') goto check4;
				
				
			
			while (hit == 'H')
			{
				int rr = rand() % 13 + 1;
				noob_size++;
				noob_cards[noob_size-1] = rr;
				printf("\nTus cartas:\n");
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
					
					printf("Bot Administrador: Quieres contar la A como 11?(y/n): ");
					
					check2 : ;
					
						answerAce = toupper(getche());
						
						if (answerAce != 'Y' && answerAce != 'N') goto check2;
					
					if (answerAce == 'Y' && flagAceN == 0) // ace is 1 wanted 11 add 10
					{	
						sumN = Summ(10, sumN);
						flagAceN = 1; // ace has changed to 11
					}
	//				if (answerAce == 'Y' && flagAceN == 1)  ace is 11 no action
	//				if (answerAce == 'N' && flagAceN == 0)  ace is 1 wanted 1 no action
					if (answerAce == 'N' && flagAceN == 1)  // ace is 11 wanted 1 sub 10
					{	sumN = Summ(-10, sumN);
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
					printf("Bot Administrador: Quieres contar 1era A como 11?(y/n): ");
					
					check3 : ;
					
						answerAce = toupper(getche());
						
						if (answerAce != 'Y' && answerAce != 'N') goto check3;
					
					if (answerAce == 'Y' && flagAceN == 0)
					{	
						sumN = Summ(10, sumN);
						flagAceN = 1; // ace has changed to 11
					}
					if (answerAce == 'N' && flagAceN == 1)  // ace is 11 wanted 1 sub 10
					{	sumN = Summ(-10, sumN);
						flagAceN = 0; // ace is 1 again
					}
				}
				sleep(1);
			
			
			
			
				
				
				sumN = Summ(rr, sumN);
				
				if (sumN > 31)
				{
					sleep(1);
					system("cls");
					printf("\nVolaste!\n");
					*contador-=1;
					sleep(2);
					bust = true;
					break;
				}
				if (sumN == 31)
				{
					sleep(1);
					printf("\n-31-\n");
					sleep(2);
					printf("\n...\n");
					sleep(1);
					break;
				}
				N_14 = Check14(sumN);
				if (N_14)
				{
					printf("\n\nBot Administrador: Tienes 14! Tengo que ir al 31.\n\n");
					sleep(2);
					goto deal;
				}
				
				printf("\nSuma: %d\n",sumN);
	
				printf("\nPedir o quedarse (h/s)?: ");
				
				check5:
					
					hit = toupper(getche());
					if (hit != 'H' && hit != 'S') goto check5;
			}
			
			
			
			deal: ;
				
			// dealers turn
			printf("\nBot Administrador: Mis cartas:\n");
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
				if (saldoen0(*contador) && bust) goto salir;
				else {
				if (N_14) 
					printf("\n\nBot Administrador: Parece que tengo 14 tambien :P Soy el ganador!!.\n\n");
				else if (sumN < 31) 
					printf("\n\nBot Administrador: Parece que tengo 14 y tu tienes la suma de 31 (%d).. Soy el ganador!!.\n\n", sumN);
				else if (sumN == 31) 
					printf("\nBot Administrador: Enserio? 31? ... Okay, ganaste\n\n");
				else if (bust)
					printf("\nBot Administrador: Yo gane!\n");
				goto end;}
			}

				printf("\nSuma: %d\n",sumD);
				sleep(2);
				
				if (N_14) goto loopa;
				
				while (sumD < sumN && !bust)
				{
					loopa: ;
						
					int rr = rand() % 13 + 1;
					
					dealer_size++;
					dealer_cards[dealer_size-1] = rr;
					printf("\nBot Administrador: Mis cartas: ");
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
						if ( flagAceDD == 0 && (Summ(rr, sumD) + 10 <= 31) && (Summ(rr, sumD) != 14) )
						{
							sumD = Summ(10, sumD);
							flagAceDD = 1;
						} 
						else if ( (flagAceDD == 1 && (Summ(rr, sumD) > 31)) || (flagAceDD == 1 && (Summ(rr, sumD) - 10 == 14)) )
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
						
						
						if ( flagAceDD == 0 && (Summ(rr, sumD) + 10 <= 31) && (Summ(rr, sumD) != 14) )
						{
							sumD = Summ(10, sumD);
							flagAceDD = 1;
						} 
						else if ( (flagAceDD == 1 && (Summ(rr, sumD) > 31)) || (flagAceDD == 1 && (Summ(rr, sumD) - 10 == 14)) )
						{
							sumD = Summ(-10, sumD);
							flagAceDD = 0;
						}

					}
					
					
					
					
					
					
					
					
					sumD = Summ(rr, sumD);
					printf("\nSuma: %d\n",sumD);
					sleep(2);
					
					D_14 = Check14(sumD);
					if (saldoen0(*contador) && bust) goto salir;
					else {
					if (D_14)
					{
						
						
							if (N_14) printf("\n\nBot Administrador: Parece que tengo 14 tambien :P Soy el ganador!!.\n\n");
							
							else if (sumN < 31) printf("\n\nBot Administrador: Parece que tengo 14 y tu tienes la suma de 31 (%d).. Soy el ganador!!.\n\n", sumN);
								
							else if (sumN == 31) printf("\nBot Administrador: Enserio? 31? ... Okay, ganaste\n\n");
								
							else if (bust) printf("\nBot Administrador: Yo gane!\n");}
							
							
							
							 goto end; }

							
			
							
						
						
					
					
					if (N_14 && sumD < 31 ) goto loopa;
				}
				
				
				
				// we have a winner
				printf("\nBot Administrador: Suma de mis cartas: %d\nSuma de tus cartas: %d", sumD, sumN);
				sleep(1);
				if (saldoen0(*contador) && bust) goto salir;
				
				if ((sumD >= sumN && sumD <= 31) || bust) {
					printf("\nBot Administrador: Yo gane!\n");
					}
				else printf("\nBot Administrador: Ganaste... es una lastima.\n");
				sleep(1);
				
				
				end:
					
				printf("\nJugar de nuevo?(P/Q): ");
				key = toupper(getch());
				
				if (key != 'Q' && key != 'P') goto end;
				
				if (key == 'Q')	
				{
					system("cls");
					goto salir;
				}
			}
	
		}
	salir: ; 
	system("cls");
	printf("\nSaliendo del juego...\n");
}

	
 




// eimon96 11/2020 <<3







